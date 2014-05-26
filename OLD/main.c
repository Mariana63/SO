
#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"
#include "struct.h"




int main(int argc, char** argv) {
    readFile("info.txt");
    printEstruturas();
   
    return (EXIT_SUCCESS);
}

