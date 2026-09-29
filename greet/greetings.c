#include <stdio.h>
#include <time.h>

int moon_phase(int, int, int);

int main(int argc, char *argv[])
{
    time_t now;
    struct tm *clock;
    char time_string_buffer[64];

    time(&now);
    clock = localtime(&now);

    strftime(time_string_buffer, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);


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
    

    for (int i = 0; i < 8; i++)
    {
      printf("%s\n", moon_phase_ascii[0][i]);
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
