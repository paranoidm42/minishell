#!/bin/bash

merge_branch()
{
    git switch "$1" 2> /dev/null
    git pull 2> /dev/null
    git merge "$2" 2> /dev/null
    git add . 2> /dev/null
    git commit -m "$3" 2> /dev/null
    git push 2> /dev/null
}

git merge main 2> /dev/null
git add . 2> /dev/null
git commit -m "ccur" 2> /dev/null
git push > /dev/null
merge_branch main ccur "ccur" 2> /dev/null
merge_branch ccur main "ccur" 2> /dev/null

