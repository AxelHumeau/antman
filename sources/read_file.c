/*
** EPITECH PROJECT, 2022
** antman
** File description:
** main
*/

#include "antman_common.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int file_size(char *pathname)
{
    struct stat statbuf;

    if (stat(pathname, &statbuf))
        return -1;
    if ((statbuf.st_mode & S_IFMT) != S_IFREG) {
        return -1;
    }
    return statbuf.st_size;
}

char *read_file(char *path, int size)
{
    int fd = open(path, O_RDONLY);
    char *buf;
    int offset = 0;
    int res;

    if (fd == -1)
        return NULL;
    buf = malloc(size);
    while ((res = read(fd, buf + offset, size - offset)) > 0) {
        offset += res;
    }
    close(fd);
    if (res < 0) {
        free(buf);
        return NULL;
    }
    return buf;
}
