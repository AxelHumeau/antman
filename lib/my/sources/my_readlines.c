/*
** EPITECH PROJECT, 2021
** cat
** File description:
** Concat files & write them to stdout
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "my.h"

int seek_line(char *buf, int limit)
{
    int i = 0;

    while (i < limit) {
        if (buf[i] == '\n') {
            return i + 1;
        }
        i++;
    }
    return -1;
}

int read_append(int fd, char **buf, int *offset, int *count)
{
    int appended_count;

    increase_buffer_capacity(buf, *offset, *count);
    appended_count = read(fd, *buf + *count - *offset, 1024);
    *count += appended_count - *offset;
    *offset = 0;
    return appended_count > 0;
}

static void line_found(char *buf, int len, void *data,
                        void (*f)(void *data, char *line))
{
    char *copy = malloc(sizeof(char) * (len + 1));

    my_strncpy(copy, buf, len);
    copy[len] = 0;
    (*f)(data, copy);
    free(copy);
}

void increase_buffer_capacity(char **buf, int offset, int count)
{
    char *new = malloc(sizeof(char) * (count - offset + 1024));
    int i = 0;

    while (offset + i < count) {
        new[i] = (*buf)[offset + i];
        i++;
    }
    free(*buf);
    *buf = new;
}

void my_readlines(int fd, void *data, void (*f)(void *data, char *line))
{
    char *buf = malloc(1024);
    int offset = 0;
    int count = 0;
    int linelen;

    count = read(fd, buf, 1024);
    while (1) {
        linelen = seek_line(buf + offset, count - offset);
        if (linelen > 0) {
            line_found(buf + offset, linelen - 1, data, f);
            offset += linelen;
            continue;
        }
        if (!read_append(fd, &buf, &offset, &count))
            break;
        offset = 0;
    }
    line_found(buf + offset, count - offset, data, f);
    free(buf);
}
