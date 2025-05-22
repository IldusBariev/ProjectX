#ifndef FILESYSTEM_H
#define FILESYSTEM_H
FILE* create_open_file(const char* filename);
char* view_file(const char* filename);
char* delete_file(const char* filename);
char* add_file(const char* main_filename);
char* modify_file(const char* filename);
#endif
