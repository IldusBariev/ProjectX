#include <stdio.h>

void work_with_file(const char* file, const char* action) {
    printf("!");
}

char* read_file(const char* file) {
    FILE *fp;
    fp = fopen(file, "r");
    
    if (fp == NULL) {
        perror("Ошибка. Файл не существует либо не правильно написан");
        return "Error";
    }
    
    int length;
    printf("Введите длину строки, которую вы хотите\n");
    scanf("%d", &length);
    
    char line[length];
    fgets(line, sizeof(line), fp);
    fclose(fp);
    
    return line;
}

void fs_delete(const char* file) {
    if (remove(file) == 0) printf("Файл удален\n");
    else perror("Ошибка. Файл не существует либо не правильно написан");
}
