#include "estrutura.h"

/*Essa é uma biblioteca ultilitaria e agrupa um conjunto de funções uteis
para o funcionamento do programa, porém, não se encaixam  nas funções TADs.
Dessa forma para uma melhor organização de código essa biblioteca foi criada*/

int verifica_dados(char** dados);

int verifica_tabuleiro(char **tabuleiro);

Pilha* entrada_dados(void);

void free_matriz(char **lixo);