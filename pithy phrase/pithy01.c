#include <stdio.h>
#include <stdlib.h>

#define BSIZE 256

int main(void)
{
    // Arreglo de caracteres que contiene el nombre del pithy list 
    const char filename[] = "pithy.txt";
    // FILE es una estructura definida en stdio.h
    /*
    FILE is a type of structure typedef as FILE. It is considered as opaque data type as its implementation is hidden.
    */
    FILE *file_pointer;
    // Arreglo donde se van a guardar las frases que se lean del archivo. Solo una frase
    char buffer[BSIZE];
    char *r;
    file_pointer = fopen(filename, "r");
    if(file_pointer == NULL)
    {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    return 0;
}