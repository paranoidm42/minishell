#!/bin/bash

merge_branch() {
    git switch "$1"
    git pull
    git merge "$2"
    git add .
    git commit -m "$3"
    git push
}

# Ana işlem
gir merge main
git add .
git commit -m "ccur"
git push
merge_branch main ccur "ccur"
merge_branch ccur main "ccur"
