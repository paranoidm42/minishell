#include "minishell.h"
/*
 commo_seperate fonksiyonunun parçası,tırnaklar için flag kontrolü yapar.
*/
static int flag_check(char input, int *xsingle, int *ydouble)
{
    if (input == '\'' && !(*ydouble))
    {
        (*xsingle)--;
        if (*xsingle == -2)
            *xsingle = 0;
        return 0;
    }
    else if (input == '"' && !(*xsingle))
    {
        (*ydouble)--;
        if (*ydouble == -2)
            *ydouble = 0;
        return 0;
    }
    return 1;
}
/*
 commo_seperate fonksiyon bir metnin içindeki tırnakları eşleğenine göre kaldırır
*/
char *commo_seperate(const char *input)
{
    int xsingle = 0;
    int ydouble = 0;
    char *output;
    char *save;
    output = malloc(sizeof(char) * 255);
    if (output == NULL)
        return NULL;
    save = output;
    while (*input)
    {
        if (flag_check(*input, &xsingle, &ydouble))
        {
            if (*input == '\'' || *input == '"')
                *output = *input;
            else
                *output = *input;
            output++;
        }
        input++;
    }
    *output = '\0';
    if (ydouble == -1 || xsingle == -1)
        return (free(save),NULL);
    return save;
}

void lexer_main(t_data *data)
{
    char *outputText;
    outputText = commo_seperate(data->cmd);
    printf("%s\n", outputText);
}
