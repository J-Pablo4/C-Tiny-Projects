#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define JUMP printf("\n");


// Prototipado de funciones
// Funcion para determinar las fases de la luna
int moon_phase(int, int, int);


int main(int argc, char *argv[])
{
    time_t now;
    struct tm *clock;
    int hour;
    int mp;
    char time_string_buffer[64];

    char moon_phase_ascii[8][8][15] = {
      {
        "     _..._     ",
        "   .::::. `.   ",
        "  :::::::.  :  ",
        "  ::::::::  :  ",
        "  `::::::' .'  ",
        "    `'::'-'    ",
        "               ",
        "WAXING CRESCENT"
      },
      {
        "    _..._    ",
        "  .::::  `.  ",
        " ::::::    : ",
        " ::::::    : ",
        " `:::::   .' ",
        "   `'::.-'   ",
        "             ",
        "FIRST QUARTER"
      },
      {
        "     _..._    ",
        "   .::'   `.  ",
        "  :::       : ",
        "  :::       : ",
        "  `::.     .' ",
        "    `':..-'   ",
        "              ",
        "WAXING GIBBOUS"
      },
      {
        "   _..._   ",
        " .'     `. ",
        ":         :",
        ":         :",
        "`.       .'",
        "  `-...-'  ",
        "           ",
        " FULL MOON "
      },
      {
        "     _..._    ",
        "   .'   `::.  ",
        "  :       ::: ",
        "  :       ::: ",
        "  `.     .::' ",
        "    `-..:''   ",
        "              ",
        "WANING GIBBOUS"
      },
      {
        "    _..._   ",
        "  .'  ::::. ",
        " :    ::::::",
        " :    ::::::",
        " `.   :::::'",
        "   `-.::''  ",
        "            ",
        "LAST QUARTER"
      },
      {
        "     _..._     ",
        "   .' .::::.   ",
        "  :  ::::::::  ",
        "  :  ::::::::  ",
        "  `. '::::::'  ",
        "    `-.::''    ",
        "               ",
        "WANING CRESCENT"
      },
      {
        "   _..._   ",
        " .:::::::. ",
        ":::::::::::",
        ":::::::::::",
        "`:::::::::'",
        "  `':::''  ",
        "           ",
        "  NEW MOON "
      }
    };

    time(&now);
    clock = localtime(&now);

    mp = moon_phase(clock->tm_year+1900, clock->tm_mon, clock->tm_mday);

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

    puts("Moon phase:");

    for (int i = 0; i < 8; i++)
    {
      printf("%s\n", moon_phase_ascii[mp][i]);
      usleep(300000);
    }

    return 0;
}

int moon_phase(int year, int month, int day)
{
    int d,g,e;

    d = day;
    if(month == 2)
        d += 31;
    else if(month > 2)
        d += 59 + (month - 3) * 30.6 + 0.5;
    
    g = (year - 1900) % 19;
    e = (11 * g + 29) % 30;
    if(e == 25 || e ==24)
        ++e;
    return (((e + d) * 6 + 5) % 177) / 22 & 7;
}
