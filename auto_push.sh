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

git merge main 2> /dev/null
git add . 2> /dev/null
git commit -m "ccur" 2> /dev/null
git push > /dev/null
merge_branch main ccur "ccur" 2> /dev/null
merge_branch ccur main "ccur" 2> /dev/null

