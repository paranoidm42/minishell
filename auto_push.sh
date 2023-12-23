#!/bin/bash

merge_branch()
{
    git switch "$1"  > /dev/null
    git pull  > /dev/null
    git merge "$2"  > /dev/null
    git add .  > /dev/null
    git commit -m "$3"  > /dev/null
    git push  > /dev/null
}

name="$1"  > /dev/null
printf "Merhaba $name ..."
git merge main  > /dev/null
git add .  > /dev/null
git commit -m "42"  > /dev/null
git push  > /dev/null
merge_branch main "$name" "42"  > /dev/null
merge_branch "$name" main "42"  > /dev/null
