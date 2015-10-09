
/*
 *Verifica se um tabuleiro está correto ou errado 
 */
int verifica_tabuleiro(int *tabuleiro){
	return (*tabuleiro == 123804765);
}

/*
 *Retira da memória uma determinada matrix 3x3
 */
void free_matriz(char **lixo){
	free(lixo[0]);
	free(lixo[1]);
	free(lixo[2]);
	free(lixo);
}

char ** create_matriz(){
	char **retorno = (char**)malloc(3*sizeof(char*));
	retorno[0] = (char*)malloc(3*sizeof(char));	
	retorno[1] = (char*)malloc(3*sizeof(char));
	retorno[2] = (char*)malloc(3*sizeof(char));
	return retorno;
}

/*
 *Verifica a igualdade de dois tabuleiros, retornando se são diferentes ou não.
 */
int compara_tabuleiros(int* tab1, int* tab2){
	return (*tab1 == *tab2);
}

/*
 *Faz a cópia exata de um estado do puzzle
 */
void copia_tabuleiro(int *info, int *copia){
	*copia = *info;
}