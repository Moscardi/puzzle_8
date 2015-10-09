#include "tabuleiro.h"

/*Essa biblioteca foi criada para servir como uma interface 
para usaro tabuleiro*/

int verifica_tabuleiro(int *tabuleiro);

void free_matriz(char **lixo);

char ** create_matriz();

int compara_tabuleiros(int* tab1, int* tab2);

void copia_tabuleiro(int *info, int *copia);