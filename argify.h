/**
 * @file            argify.h
 * @brief           Header for the argify library.
 *
 * @author          Yanujz
 * @date            11/01/2025
 * @version         1.0
 */

/*
 *  MIT License
 *
 *  Copyright (c) 2025 Yanujz
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef ARGIFY_H
#define ARGIFY_H
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Splits a string into an array of arguments, handling quotes and escapes.
 *
 * @param[out] argc Pointer to an integer where the argument count will be stored.
 * @param[out] argv Pointer to an array of strings to store the arguments.
 * @param[in] input The input string to parse.
 * @return 0 on success, -1 on failure.
 */
int argify(int* argc, char*** argv, const char* input);

/**
 * Frees the memory allocated for the argument array.
 *
 * @param[in] argv The argument array to free.
 */
void free_args(char** argv);

#ifdef __cplusplus
}
#endif

#endif // ARGIFY_H
