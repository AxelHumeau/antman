/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman compression
*/

#pragma once

#include "antman_common.h"

#include <stdbool.h>

void write_compressed(char *buf, int len);
void write_image_compressed(char *buf, int size);

int find_line_size(char *buf, int buf_size);
bool is_valid_number(char *buf, int line_size);

int write_uncompressed_block(char *buf, int buf_size);
int write_compressed_block(char *buf, int buf_size);
int write_xs_compressed_block(char *buf, int buf_size);

char *find_occurrences(char *str, int size);
char *sort_dict(int *dict);
