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

name="$1"
echo "hello $name"
git merge main
git add .
git commit -m "42"
git push
merge_branch main "$name" "42"
merge_branch "$name" main "42"
