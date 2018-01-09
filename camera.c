#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void takePic();
void openPic();
void saveName();
void getName();// to be used in openPic to check if the name is in the list.

int main(){
  //greeting and menu options
  char opt;
  printf("Please enter A to take a picture or B to open a picture\n");

  if(opt ==A || opt == a){
    takePic();
    return 0;
  }
  else if(opt ==B || opt == b){
    openPic();
    return 0;
  }
  else{
    printf("Opps. that is not a valid option.\n");
    return 1;
  }
}


void takePic(){

  char cmd[50];
  char name[10];
  char format[5]=".jpg";

  printf("Please enter the name of the picture you are about to take.\n");

  scanf("%s", name);

  if(strlen(name)>10){
    printf("The name is too long, please try again\n");
    exit(EXIT_FAILURE);//replace with return to menu
  }
  else{
    saveName(name);//saves name to the linked list.
    strcat(name, format);
    strcpy(cmd, "raspistill -o ");
    strcat(cmd, name);
    system(cmd);
  }
}

// To do:

void openPic(){
  //check for existance on name in the list using getName()
  //if it exists open the picture using EOG in a system call passing the name of the picture.
  //if it does not exist print a message.
}

void saveName(){
  //add name to linked list as the data in node.
}
void getName(){

}
