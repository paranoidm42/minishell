/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:02:36 by ccur              #+#    #+#             */
/*   Updated: 2024/01/25 23:09:13 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	freestructs_nodata(t_scmd_list *temp)
{
	t_cmd	*tempcmd;

	tempcmd = temp->data;
	if (temp->type == CMD)
		free(tempcmd->arg);
	free(temp->data);
	temp->data = NULL;
}

void	freescmdlst_nodata(t_scmd_list **lst)
{
	t_scmd_list	*temp;
	t_scmd_list	*next;

	temp = *lst;
	while (temp)
	{
		next = temp->next;
		if (temp->data)
			freestructs_nodata(temp);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

void	freelst_nodata(t_list *lst)
{
	t_list	*temp;
	t_list	*next;

	if (!lst)
		return ;
	temp = lst;
	while (temp)
	{
		next = temp->next;
		freescmdlst_nodata((void *)&temp->content);
		free(temp);
		temp = next;
	}
	lst = NULL;
}
