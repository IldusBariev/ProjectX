#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

FILE* create_open_file(const char* filename) {
    FILE* fp = fopen(filename, "a+");
    if (fp == NULL) {
        perror("Ошибка при открытии файла");
        return NULL;
    }
    return fp;
}

char* view_file(const char* filename) {
    
    FILE* fs_file = fopen(filename, "r");

    rewind(fs_file);

    char line[MAX_SIZE];
    int found = 0;
    char content[MAX_SIZE]; 
    content[0] = '\0';

    while (fgets(line, sizeof(line), fs_file)) {
        // Удаляем символ новой строки
        int i = 0;
        while (line[i] != '\n' && line[i] != '\0') i++;
        line[i] = '\0';

        if (!found) {
            int match = 1;
            for (i = 0; filename[i] != '\0' && line[i] != '\0'; i++) {
                if (filename[i] != line[i]) {
                    match = 0;
                    break;
                }
            }
            if (match && filename[i] == '\0' && line[i] == '\0') {
                found = 1;
            }
        } else {
            if (line[0] == '/') break;

            if (content[0] != '\0') {
                strcat(content, "\n");
            }
            strcat(content, line);
        }
    }

    return content;
}

char* delete_file(const char* filename) {
    if (remove(filename) == 0) return "ФАЙЛ УДАЛЕН";
    
    return "ОШИБКА";
}

char* add_file(const char* main_filename) {
    char filename[1024];
    printf("Введите название файла из ФС\n");
    scanf("%s", filename);
    
    
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return "ERROR\n";
    }
    fclose(fp);
    
    fp = fopen(main_filename, "r");
    if (fp != NULL) {
        return "ERROR\n";
    }
    fclose(fp);
    
    FILE* fs_file = fopen(main_filename, "a+");
    
    char content[1024];
    printf("Введите содержимое файла\n");
    scanf("%s", content);

    fseek(fs_file, 0, SEEK_END); // перемещает указатель
    
    fprintf(fs_file, "%s\n", filename);
    fprintf(fs_file, "%s\n", content);
    fprintf(fs_file, "/\n");
    
    fflush(fs_file); // очищает буфер
    
    return "GOOD";
}

void modify_file(const char* fs_filename) {
    // Запрашиваем имя файла для изменения
    char filename[256];
    printf("Введите имя файла для изменения: ");
    scanf(" %255[^\n]", filename);

    // Открываем файловую систему для чтения, чтобы проверить существует ли такой файл
    FILE* fs_file = fopen(fs_filename, "r");
    if (fs_file == NULL) {
        printf("ERROR: Не удалось открыть файловую систему\n");
        return;
    }

    // Временный файл
    FILE* temp_file = fopen("temp_fs.txt", "w");
    if (temp_file == NULL) {
        printf("ERROR: Не удалось создать временный файл\n");
        fclose(fs_file);
        return;
    }

    // получаем новое содержимое
    char new_content[1024];
    printf("Введите новое содержимое для файла '%s':\n", filename);
    scanf(" %1023[^\n]", new_content);
    getchar(); // Очищаем буфер ввода

    char line[256];
    int found = 0;
    int copying = 1;

    // Обрабатко файловой системы
    while (fgets(line, sizeof(line), fs_file) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Удаляем символ новой строки

        if (!found) {
            if (strcmp(line, filename) == 0) {
                found = 1;
                copying = 0;
                fprintf(temp_file, "%s\n%s\n", line, new_content);
            } else {
                fprintf(temp_file, "%s\n", line);
            }
        } else {
            if (copying) {
                fprintf(temp_file, "%s\n", line);
            } else if (line[0] == '/') {
                copying = 1;
                fprintf(temp_file, "%s\n", line);
            }
        }
    }

    // Закрываем файла и замена оригинального
    fclose(fs_file);
    fclose(temp_file);

    remove(fs_filename);
    rename("temp_fs.txt", fs_filename);

    if (found) {
        printf("Файл '%s' успешно изменен\n", filename);
    } else {
        printf("Файл '%s' не найден\n", filename);
        remove("temp_fs.txt"); // Удаление временного файла если нет основного
    }
}
