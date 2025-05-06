#include <stdio.h>

void fs_delete(const char* file) {
    if (remove(file) == 0) printf("Файл удален\n");
    else perror("Ошибка. Файл не существует либо не правильно написан");
}
