#!/bin/bash

merge_branch()
{
    git switch "$1" > /dev/null
    git pull > /dev/null
    git merge "$2" > /dev/null
    git add . > /dev/null
    git commit -m "$3" > /dev/null
    git push > /dev/null
}

git merge main > /dev/null
git add . > /dev/null
git commit -m "ccur" > /dev/null
git push > /dev/null
merge_branch main ccur "ccur" > /dev/null
merge_branch ccur main "ccur" > /dev/null
