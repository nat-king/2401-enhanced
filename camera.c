#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

static const char FORMAT[]=".jpg";

void takePic(char name[]);
void openPic(char name[]);
void saveName(char name[]);
int getName(char name[]);// to be used in openPic to check if the name is in the list.

int main(){
  char name[10];
  //greeting and menu options
  char opt;
  printf("Please enter A to take a picture or B to open a picture\n");
  scanf("%c", &opt);
  if(opt == 'A'){
    printf("Please enter the name of the picture you want to take\n");
    scanf("%s", name);
    takePic(name);
    return 0;
  }
  else if(opt == 'B'){
    printf("Please enter the name of the picture you want to open\n");
    scanf("%s", name);
    openPic(name);
    return 0;
  }
  else{
    printf("Opps. that is not a valid option.\n");
    return 1;
  }
  return 0;
}


void takePic(char name[]){

  char cmd[50];

  if(strlen(name)>10){
    printf("The name is too long, please try again\n");
    exit(EXIT_FAILURE);//replace with return to menu
  }
  else{
    //saveName(name);//saves name to the linked list.
    strcat(name, FORMAT);
    strcpy(cmd, "raspistill -o ");
    strcat(cmd, name);
    system(cmd);
  }
}

// To do:

void openPic(char name[]){
  char cmd[50];
  //check for existance on name in the list using getName()
  if(getName(name) == 1){ //if it exists open the picture using EOG in a system call passing the name of the picture.
    strcat(name, FORMAT);
    strcpy(cmd, "eog ");
    strcat(cmd, name);
    system(cmd);
  }
  else {//if it does not exist print a message.
    printf("That picture has not been taken yet.\n");
  }

}

void saveName(char name[]){
  //add name to linked list as the data in node.
  

}
int getName(char name[]){
  return 1; //return 1 if true
 //retunr 0 if false
}
