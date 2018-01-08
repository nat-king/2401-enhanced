#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  char cmd[50];
  char name[10];
  char format[5]=".jpg";
  char message[100]="Please enter the name of the picture you are about to take.";
  printf("%s\n", message);
  scanf("%s", name);

  if(strlen(name)>10){
    printf("The name is too long\n");
    exit(EXIT_FAILURE);
  }
  else{
    strcat(name, format);
    strcpy(cmd, "raspistill -o ");
    strcat(cmd, name);
    system(cmd);
  }
  return 0;
}
