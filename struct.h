#ifndef _STRUCT_
#define _STRUCT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef union Componente{
    char *regiao;
    int nrCasos; 
}Componente; 


typedef struct Localidade{
    Componente c;
    struct Localidade *next;
}Localidade;

typedef struct Localidades{
    struct Localidade *prefixo;
    struct Localidades *next;
}Localidades;


#endif
