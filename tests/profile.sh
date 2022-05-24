#!/usr/bin/env bash
##
## EPITECH PROJECT, 2022
## antman
## File description:
## profiling
##

ogsize=$(stat --printf "%s" "$2")

if [ -z "$ogsize"  ]; then
    exit 2
fi

time_co=$((/bin/time -f %e antman/antman "$2" "$1" > compressed.tmp) 2>&1)
time_de=$((/bin/time -f %e giantman/giantman compressed.tmp "$1" > decompressed.tmp) 2>&1)

cosize=$(stat --printf "%s" compressed.tmp)
reduction=$((cosize * 100 / ogsize))

printf "%-26s %5d%% of original t = %s %s\n" "$2" "$reduction" "$time_co" "$time_de"

if cmp -s -- "$2" decompressed.tmp; then
    # echo "$2: same output"
    exit 0
else
    echo -e "$2: \033[0;31mERROR!\033[0m Output differs"
    exit 1
fi
