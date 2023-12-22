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

git merge main > /dev/null
git add . > /dev/null
git commit -m "ccur" > /dev/null
git push > /dev/null
merge_branch main ccur "ccur" > /dev/null
merge_branch ccur main "ccur" > /dev/null 

