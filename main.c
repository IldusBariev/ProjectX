#include <stdio.h>

#include "filesystem.h"

int main()
{
    char file[255];
    printf("Input your file\n");
    scanf("%s", file);
    
    
    int file_action;
    printf("Ваше действие с файлом\n1 - Открытие для чтения\n2 - Открытие для записи\n3 -  Открытие для добавления\n4 - Открытие для чтения и записи\n5 - Открытие для чтения и добавления\n6 - удаление файла\n");
    scanf("%d", &file_action);
    
    switch(file_action) {
        case 1:
            printf("Ваша строка %s", read_file(file));
            break;
        case 2:
            printf("Результат: %s", update_file(file));
            break;
        case 3:
            printf("Результат: %s",append_file(file));
            break;
        case 4:
            printf("Результат: %s", read_and_work(file));
            break;
        case 5:
            printf("Результат: %s",read_and_append(file)); 
            break;
        case 6:
            file_delete(file);
            break;
        default:
            printf("Ошибка такого действие еще нет", file);
    }

    return 1;
}


