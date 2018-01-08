#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMN_LEN 100 //length of the terminal command

int main(int argc, char *argv[])
{
    char cmd[MAX_CMN_LEN] = "", **p;

    if (argc < 2) { /*no command specified*/
      fprintf(stderr, "Usage: ./cam terminal_command ..."); //raspistill -o test.jpg -t 1000
      exit(EXIT_FAILURE);
    }
    else {
      strcat(cmd, argv[1]);
      for (p = &argv[2]; *p; p++) {
        strcat(cmd, " ");
        strcat(cmd, *p);
      }
      system(cmd);
    }
    return 0;
}
