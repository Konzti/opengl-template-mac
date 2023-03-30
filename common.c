#include "common.h"

char *parse_shader(const char *file_path)
{   
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }
    
    char* contents;
    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);
    contents = (char *)malloc(length + 1);
    fread(contents, 1, length, file);
    fclose(file);
    contents[length] = '\0';
    return contents;
}