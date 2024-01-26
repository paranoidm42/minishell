#!/bin/bash

function loading() {
    echo -n "Progress: ["
    for ((i = 1; i <= 100; i++)); do
        echo -n "#"
        sleep 0.5
    done
    echo -e "] 100%\n"
}

merge_branch()
{
    git switch "$1"  2> /dev/null 2>&1
    git pull  > /dev/null 2>&1
    git merge "$2"  > /dev/null 2>&1
    git add .  > /dev/null 2>&1
    git commit -m "$3"  > /dev/null 2>&1
    git push  > /dev/null 2>&1
}

name="$1" > /dev/null 2>&1
printf "Merhaba $name ...\n" && loading
git merge main > /dev/null 2>&1
printf "branch changed to main...\n"
printf "Branch changed...\n"
git add . > /dev/null 2>&1
git commit -m "42" > /dev/null 2>&1
git push  > /dev/null 2>&1
printf "everything pusshed\n"
merge_branch main "$name" "42" > /dev/null 2>&1
printf "branch merged from $name to main...\n"
merge_branch "$name" main "42" > /dev/null 2>&1
printf "branch merged from main to $...\n"
