#ifndef LINKED_LIST_2401_HEADER
#define LINKED_LIST_2401_HEADER 1

/************************************************************************/
// DEFINED


#define NAME_LENGTH 10


/************************************************************************/
// STRUCTURES

typedef struct  picInfo {
        struct picInfo *next;
        char picName[NAME_LENGTH];
} PicInfo;

#endif
