#include <stdio.h>
#include <time.h>

#define JUMP printf("\n");

int main(int argc, char *argv[])
{
    time_t now;
    struct tm *clock;
    int hour;
    char time_string_buffer[64];

    time(&now);
    clock = localtime(&now);

    /*
     * strftime es como printf. Sirve para formatear el tiempo como un string.
     * Es necesario pasarle una structura tm que es una estructura que con el tiempo. En este caso es clock.
     * El texto ya formateado se guarda en un buffer/arreglo de caracteres y despues ya se puede 
     * usar ese arreglo de caracteres como cualquier string en un printf.
     *
     * Formato de strftime:
     * strftime(<buffer/arreglo de caracteres>, <tamaño de buffer>, <texto que se va a guardar en el buffer>, <struct tm con tiempo actual>
     * */
    strftime(time_string_buffer, 64, "Today is %A, %B %d, %Y%nIt's %r%n", clock);
    hour = clock->tm_hour;

    JUMP
    if(hour <= 4)
    {
        puts("Hi Juan!");
        puts("...");
        puts("Working late?");
    }else
    {
        printf("Good ");
        if(hour < 12)
            printf("morning");
        else if(hour < 17)
            printf("afternoon");
        else
            printf("evening");

        if(argc > 1)
            printf(", %s!", argv[1]);

        putchar('\n');
    }
    printf("\n%s", time_string_buffer);
    JUMP
    JUMP

    return 0;
}
