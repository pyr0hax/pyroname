#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* input_file;
    char* output_file;

    if (argc != 5) {
        printf("Usage: %s -i <input_file> -o <output_file>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "-i") == 0) {
            input_file = argv[i + 1];
        } else if (strcmp(argv[i], "-o") == 0) {
            output_file = argv[i + 1];
        } else {
            printf("Invalid argument: %s\n", argv[i]);
            return 1;
        }
    }

    char sed_command[200];
    snprintf(sed_command, sizeof(sed_command), "sed -i 's|^|//|' %s", output_file);
    system(sed_command);

    char cat_command[200];
    snprintf(cat_command, sizeof(cat_command), "cat %s >> %s", input_file, output_file);
    system(cat_command);

    printf("Content from %s has been appended to %s\n", input_file, output_file);

    return 0;
}
