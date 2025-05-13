#include <stdio.h>
#include <string.h>

char* read_file(const char* file) {
    FILE *fp;
    fp = fopen(file, "r");
    
    // Проверка на наличие файла
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

char* read_and_work(const char* file) {
    FILE *fp;
    fp = fopen(file, "r+");
    
    // Проверка на наличие файла
    if (fp == NULL) {
        perror("Ошибка. Файл не существует либо не правильно написан");
        return "Error";
    }
    
    int action;
    printf("1 - чтение данного файла\n2 - добавление в данный файл (в начало)\n");
    scanf("%d", &action);
    
    // Выбор действия
    if (action == 1) {
        int length;
        printf("Введите длину строки, которую вы хотите\n");
        scanf("%d", &length);
        
        char line[length];
        fgets(line, sizeof(line), fp);
        fclose(fp);
        
        return line;
    }
    else if (action == 2) {
        printf("Введите текст который вы хотите ввести в файл (введите 1 слово)\n");
        char text[1024];
        scanf("%s", text);
        fprintf(fp, "%s\n", text);
        fclose(fp);
        
        return "OK";
    } else return "Error";
    
}

char* read_and_append(const char* file) {
    FILE *fp;
    fp = fopen(file, "a+");
    
    // Проверка на наличие файла
    if (fp == NULL) {
        perror("Ошибка. Файл не существует либо не правильно написан");
        return "Error";
    }
    
    int action;
    printf("1 - чтение данного файла\n2 - добавление в данный файл (в конец)\n");
    scanf("%d", &action);
    
    // Выбор действия
    if (action == 1) {
        int length;
        printf("Введите длину строки, которую вы хотите\n");
        scanf("%d", &length);
        
        char line[length];
        fgets(line, sizeof(line), fp);
        fclose(fp);
        
        return line;
    }
    else if (action == 2) {
        printf("Введите текст который вы хотите ввести в файл (введите 1 слово)\n");
        char text[1024];
        scanf("%s", text);
        fprintf(fp, "%s\n", text);
        fclose(fp);
        
        return "OK";
    } else return "Error";
    
}
// Добавляет только одно слово
char* update_file( const char* file) {
    FILE *fp;
    fp = fopen(file, "w");
    
    printf("Введите текст который вы хотите ввести в файл(введите 1 слово)\n");
    char text[1024];
    scanf("%s", text);
    fprintf(fp, "%s\n", text);
    fclose(fp);
    
    return "OK";
}

char* append_file (const char* file) {
    FILE *fp;
    fp = fopen(file, "a");
    
    printf("Введите текст который вы хотите ввести в файл(введите 1 слово)\n");
    char text[1024];
    scanf("%s", text);
    fprintf(fp, "%s\n", text);
    fclose(fp);
    
    return "OK";
}

void file_delete(const char* file) {
    if (remove(file) == 0) printf("Файл удален\n");
    else perror("Ошибка. Файл не существует либо не правильно написан");
}
