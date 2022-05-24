/*
** EPITECH PROJECT, 2022
** antman
** File description:
** buffering header
*/

#pragma once

#define BUFFER_SIZE 8192

struct buffer {
    unsigned int pos;
    char buffer[BUFFER_SIZE];
};
