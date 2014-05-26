#include "readFile.h"
#include "struct.h"


Registo *loc;

void novoReg() {
    loc = (Registo*) malloc(sizeof (Registo));
    loc->root = NULL;


}

void printEstruturas() {

    Distrito *a = loc->root;
    while (a != NULL) {
        printf("Distrito:%s: \n", a->d);
        Concelho *b = a->c;
        while (b != NULL) {
            printf("concelho : %s:\n", b->concelho);
            Freguesia *c = b->f;

            while (c != NULL) {
                printf("freg : %s", c->freguesia);
                c = c->next;
            }
            b = b->next;
        }


        a = a->next;
    }


}

void populaEstruturas(char* distrito, char* concelho, char* freguesia, int nrComponentes, int nrCasos) {
    Distrito *d = (Distrito*) malloc(sizeof (Distrito));
    Distrito *a = loc->root;
    int f = 0, g = 0, h = 0;


    while (a != NULL && f != 1) {

        if (!strcmp(a->d, distrito) && nrComponentes >= 1) {
              
            a->casos += nrCasos;
            f = 1;
            Concelho *b = a->c;

            while (b != NULL && g != 1) {
                if (!strcmp(b->concelho, concelho) && nrComponentes >= 2) {
                   
                    g = 1;
                    b->casos += nrCasos;
                    Freguesia *c = b->f;
                    while (c != NULL && h != 1) {
                        if (!strcmp(c->freguesia, freguesia) && nrComponentes >= 3) {
                             
                            h = 1;
                            c->casos += nrCasos;
                        } else {

                            c = c->next;
                        }
                    }
                    if (c == NULL && h == 0&& nrComponentes>2) {
                     
                        Freguesia *nf = (Freguesia*) malloc(sizeof (Freguesia));
                        nf->freguesia = strdup(freguesia);

                        nf->casos = nrCasos;
                        nf->next = b->f;
                        b->f = nf;


                    }
                } else {


                    b = b->next;
                }

            }
            if (b == NULL && g == 0) {

                Concelho *nc = (Concelho*) malloc(sizeof (Concelho));
                nc->concelho = strdup(concelho);
                if (nrComponentes > 2) {
                    Freguesia *nf = (Freguesia*) malloc(sizeof (Freguesia));
                    nf->freguesia = strdup(freguesia);
                    nc->f = nf;
                    nf->next = NULL;
                    nf->casos = nrCasos;
                } else {
                    nc->f = NULL;
                }


                nc->casos = nrCasos;


                nc->next = a->c;
                a->c = nc;

            }
        } else {
            a = a->next;
        }



    }
    if (a == NULL && f == 0) {
      
        d->d = strdup(distrito);
        d->casos = nrCasos;


        Concelho *nc = (Concelho*) malloc(sizeof (Concelho));
        nc->concelho = strdup(concelho);
        if (nrComponentes > 2) {
            Freguesia *nf = (Freguesia*) malloc(sizeof (Freguesia));
            nf->freguesia = strdup(freguesia);
            nc->f = nf;
            nf->next = NULL;
            nf->casos = nrCasos;
        } else {
            nc->f = NULL;
        }
        nc->casos = nrCasos;

        nc->next = NULL;
        d->c = nc;
        d->next = loc->root;
        loc->root = d;
    } else free(d);



}

void trataLinha(char* linha) {
    char *distrito, *concelho, *freguesia;
    int nrCasos = 0;
    char palavra[N];
    memset(&palavra, 0, N);
    int i = 0, j = 0, nrComponentes = 0;

    while (linha[i] != '\n') {
        if (linha[i] == ':') {
            nrComponentes++;


            if (nrComponentes == 1) {
                distrito = strdup(palavra);
            }
            if (nrComponentes == 2) {
                concelho = strdup(palavra);
            }
            if (nrComponentes == 3) {
                freguesia = strdup(palavra);
            }
            memset(&palavra, 0, N);
            j = 0;
            i++;
        } else {
            palavra[j] = linha[i];
            i++;
            j++;
        }
    }
    nrCasos = atoi(palavra);
    
    populaEstruturas(distrito, concelho, freguesia, nrComponentes, nrCasos);
}

void readFile(char* fileName) {
    char linha[N];
    novoReg();
    FILE* f = fopen(fileName, "r");


    if (f != NULL) {
        while (fgets(linha, N, f)) {
            trataLinha(linha);
        }
    }
    fclose(f);
}





