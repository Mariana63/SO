#ifndef _STRUCT_
#define _STRUCT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct s_freguesia{
    char*freguesia;
    int casos;
    struct s_frefuesia *next;


}Freguesia;

typedef struct s_concelho{
    char *concelho;
    int casos;
    Freguesia *f;
    struct s_concelho *next;
}Concelho; 


typedef struct s_distrito{
    char* d;
    Concelho *c;
    struct s_distrito *next;
}Distrito;

typedef struct s_registo{
    Distrito *root;
}Registo;


#endif