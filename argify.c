/**
 * @file            argify.c
 * @brief           Implementation of the argify library.
 *
 * @author          Yanujz
 * @date            11/01/2025
 * @version         1.0
 */

/*
    MIT License

    Copyright (c) 2025 Yanujz

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
 */

#include "argify.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CAPACITY 8  // Initial number of argument slots

int argify(int *argc, char ***argv, const char *input)
{
    if (!argc || !argv || !input) {
        return -1;
    }

    *argc = 0;
    *argv = malloc(INITIAL_CAPACITY * sizeof(char *));
    if (!*argv) {
        return -1;
    }

    int capacity = INITIAL_CAPACITY;
    char *buffer = malloc(strlen(input) + 1);
    if (!buffer) {
        free(*argv);
        return -1;
    }

    const char *ptr = input;
    char *arg = buffer;
    int in_single_quote = 0, in_double_quote = 0;

    while (*ptr) {
        if (isspace(*ptr) && !in_single_quote && !in_double_quote) {
            if (arg != buffer) {
                *arg = '\0';
                if (*argc >= capacity) {
                    capacity *= 2;
                    char **new_argv = realloc(*argv, capacity * sizeof(char *));
                    if (!new_argv) {
                        free(buffer);
                        return -1;
                    }
                    *argv = new_argv;
                }
                (*argv)[(*argc)++] = strdup(buffer);
                arg = buffer;
            }
            ptr++;
        } else if (*ptr == '\'' && !in_double_quote) {
            in_single_quote = !in_single_quote;
            ptr++;
        } else if (*ptr == '"' && !in_single_quote) {
            in_double_quote = !in_double_quote;
            ptr++;
        } else if (*ptr == '\\' && *(ptr + 1)) {
            ptr++;
            *arg++ = *ptr++;
        } else {
            *arg++ = *ptr++;
        }
    }

    if (arg != buffer) {
        *arg = '\0';
        if (*argc >= capacity) {
            capacity *= 2;
            char **new_argv = realloc(*argv, capacity * sizeof(char *));
            if (!new_argv) {
                free(buffer);
                return -1;
            }
            *argv = new_argv;
        }
        (*argv)[(*argc)++] = strdup(buffer);
    }

    free(buffer);
    (*argv)[*argc] = NULL;
    return 0;
}

void free_args(char **argv)
{
    if (!argv) return;

    for (int i = 0; argv[i]; i++) {
        free(argv[i]);
    }
    free(argv);
}
