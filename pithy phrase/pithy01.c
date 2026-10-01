#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    /*
     *r es un apuntador que sirve solamente para revisar si fgets no regresa NULL. Contra medida por si feof() no detiene la ejecucion del while loop a tiempo.
     Como r obtiene la direccion de buffer (o NULL si falla) puede ser usado para imprimir el contenido de buffer en lugar de buffer.
     */
    char *r, *entry;
    int items = 0;


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
        printf("%s", buffer);
    }

    fclose(file_pointer);

    return 0;
}