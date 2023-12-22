#!/bin/bash

merge_branch()
{
    git switch "$1"
    git pull
    git merge "$2"
    git add .
    git commit -m "$3"
    git push
}

<<<<<<< HEAD
name="$1"
echo "Merhaba $name ..."
git merge main
git add .
git commit -m "42"
git push
merge_branch main "$name" "42"
merge_branch "$name" main "42"
=======
local self="$1"

git merge main 2> /dev/null
git add . 2> /dev/null
git commit -m "ccur" 2> /dev/null
git push > /dev/null
merge_branch main '$self' "42" 2> /dev/null
merge_branch $self main "42" 2> /dev/null


>>>>>>> ccur
