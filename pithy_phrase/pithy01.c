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

    while(!feof(file_pointer))
    {
        /*
        Return Value of fgets:
            Returns the pointer to buff if successful.
            Returns NULL if an error occurs or the end-of-file (EOF) is reached.
        */
        r = fgets(buffer, BSIZE, file_pointer);
        if(r==NULL)
            break;
        
        // Syntax ptr = malloc(size);
        // char es un byte pero como necesitamos que sea del tamaño del texto guardado en buffer 
        // Lo multiplicamos por strlen(buffer) + 1. El "+ 1 seguramente es para tener en cuenta al caracter terminador.
        // El cast es para decirle para que tipo de pointer va a ser
        /*
        Note: In C, an explicit cast such as (int *)malloc(...) is not required. malloc() returns a void *, which can be implicitly converted to another object pointer type in C.*/
        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if(entry == NULL)
        {
            fprintf(stderr, "unable to allocate memory\n");
            exit(1);
        }
        strcpy(entry, buffer);
        printf("%d: %s\n", items, entry);
        items++;
    }

    fclose(file_pointer);

    return 0;
}