#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <conio.h>
#include "linked_list.h"

static const char FORMAT[]=".jpg";

void takePic(char name[]);
void openPic(PicInfo *head, char name[]);
PicInfo *saveName(PicInfo **head, char *name);
int getName(PicInfo *head, char name[]);// to be used in openPic to check if the name is in the list.
int menu();


int main(){

  menu();
}

int menu(){
  PicInfo *empHead = NULL;   //head node
  char name[10];
  char opt= 'Y';
  int option;

  do {

  printf("Please enter 1 to take a picture, 2 to open a picture, or 3 to quit.\n");
  scanf ("%d", &option);

  switch (option){
    case 1:
    printf("Please enter the name of the picture you want to take\n");
    scanf("%s", name);
    takePic(name);
    saveName(&empHead, name);
    break;
    case 2:
    printf("Please enter the name of the picture you want to open\n");
    scanf("%s", name);
    openPic(empHead, name);
    break;
    case 3:
    printf("See you next time!\n");
    exit(0);
    default:
    printf("Opps. that is not a valid option, try again!\n");
  }
  printf("\n\n Do you want to continue? Y/N \n");
  scanf("%c", &opt);
} while(opt == 'Y');
scanf("%c", &opt);
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

void openPic(PicInfo *head, char name[]){
  char cmd[50];
  //check for existance on name in the list using getName()
  if(getName(head, name) == 1){ //if it exists open the picture using EOG in a system call passing the name of the picture.
    strcat(name, FORMAT);
    strcpy(cmd, "eog ");
    strcat(cmd, name);
    system(cmd);
  }
  else {//if it does not exist print a message.
    printf("That picture has not been taken yet.\n");
  }

}

PicInfo *saveName(PicInfo **head, char *name){
  //add name to linked list as the data in node.
  PicInfo *temp = (PicInfo*)malloc(sizeof(struct picInfo)); //allocate memory for a new node
  strcpy(temp->picName, name);

  //if the list is empty
  if(*head == NULL) {
    temp->next = *head;
    *head = temp;
    return temp;
  }

  PicInfo *temp1 = *head; // get the reference of head
  while(temp1->next != NULL){
    temp1 = temp1->next; //travaser to the end of the list
  }
  temp->next = NULL;
  temp1->next = temp;
  return temp;
}


int getName(PicInfo *head, char name[]){
  PicInfo *node;
  node = head; //get reference of head

  while(node!= NULL && node->next != NULL){
    if(strcmp(node->picName, name) == 0){
      return 1;  // if found the name in the list
    }else return 0;
  }
}
