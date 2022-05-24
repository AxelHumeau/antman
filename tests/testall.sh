#!/usr/bin/env bash
##
## EPITECH PROJECT, 2022
## antman
## File description:
## test all files
##

errors=0
executed=0
for type in 1 2 3; do
    for filename in tests/$type/* tests/err/*; do
        tests/profile.sh $type "$filename" || ((errors++))
        ((executed++))
    done
done

echo "Finished with $errors errors out of $executed files"
