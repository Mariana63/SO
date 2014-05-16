SRC = readFile.c servidor.c biblioteca.c
CCFLAGS = -O3 -Wall -Wextra
CCC = gcc
FILE = SO

$(FILE): $(SRC:.c=.o)
	$(CCC) -o $(FILE) $(CCFLAGS) $(SRC)
