#ifndef LINKED_LIST_2401_HEADER
#define LINKED_LIST_2401_HEADER 1

/************************************************************************/
// DEFINESD


#define NAME_LENGTH 32


/************************************************************************/
// STRUCTURES

typedef struct  picInfo {
        struct picInfo *next;
        char picName[NAME_LENGTH];
} picInfo;

#endif

