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

local self="$1"

git merge main 2> /dev/null
git add . 2> /dev/null
git commit -m "ccur" 2> /dev/null
git push > /dev/null
merge_branch main '$self' "42" 2> /dev/null
merge_branch $self main "42" 2> /dev/null


