#include <stdio.h>
#include "argify.h"

int main() {
    const char *input = "arg1 \"quoted arg2\" 'single quoted arg3' arg\\ 4 'string with \"quote\" inside'";
    int argc;
    char **argv;

    if (argify(&argc, &argv, input) == 0) {
        printf("Parsed %d arguments:\n", argc);
        for (int i = 0; i < argc; i++) {
            printf("argv[%d]: %s\n", i, argv[i]);
        }
        free_args(argv);
    } else {
        fprintf(stderr, "Failed to parse arguments.\n");
        return 1;
    }

    return 0;
}
