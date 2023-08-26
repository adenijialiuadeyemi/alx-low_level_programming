#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void check_for_elf(unsigned char *eid);
void magic_print(unsigned char *eid);
void print_class(unsigned char *eid);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int typ, unsigned char *e_ident);
void entry_print(unsigned long int entr, unsigned char *e_ident);
void print_data(unsigned char *eid);
void version_print(unsigned char *eid);
void print_abi(unsigned char *e_ident);
void close_elf(int elf);

ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);

#endif
