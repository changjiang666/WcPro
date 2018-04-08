#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


/*
**function:return the length of file
**parameter:file pointer
*/


static int
filelength(FILE *fp)
{
    int num;
    fseek(fp, 0, SEEK_END);
    num = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return num;
}


/*
**function:read file to buffer
**parameter:file path,relative or absolute path
*/


char *
readfile(char const *path)
{
    FILE *fp;
    int len;
    char *buf;

    if((fp = fopen(path, "r")) == NULL)
    {
        printf("open file %s error.\n", path);
        exit(0);
    }

    len = filelength(fp);
    printf("file length :%d\n", len);
    buf = (char *) malloc (sizeof(char) * (len + 2));
    fread(buf, sizeof(char), len, fp);

    fclose(fp);
    *(buf + len) = ' ';
    *(buf + len + 1) = '\0';

    return buf;
}

