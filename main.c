#include <stdio.h>

#include "filesystem.h"

int main()
{
    char file[255];
    printf("Input your file\n");
    scanf("%s", file);
    
    
    int file_action;
    printf("Ваше действие с файлом\n1 - Открытие для чтения\n2 - Открытие для записи\n3 -  Открытие для добавления\n4 - Открытие для чтения и записи\n5 -  Открытие для чтения и записи\n6 - Открытие для чтения и добавления\n");
    scanf("%d", &file_action);
    
    switch(file_action) {
        case 1:
            printf("Ваша строка %s", read_file(file));
            break;
        case 2:
            work_with_file(file, "w");
            break;
        case 3:
            work_with_file(file, "a");
            break;
        case 4:
            work_with_file(file, "r+");
            break;
        case 5:
            work_with_file(file, "w+");
            break;
        case 6:
            work_with_file(file, "a+"); 
            break;
        default:
            printf("Ошибка такого действие еще нет", file);
    }

    return 1;
}
