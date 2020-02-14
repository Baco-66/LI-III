#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NRCLIENTES 16384
#define MAX 10


void readFileClientes (FILE* fclientes,char **clientes){
	int size = 8;
	char nrcliente[size];
	int i = 0;
	printf("ANTES DO WHILE: %d\n",i);
	while(fgets(nrcliente, size, fclientes)){
		printf("Iteração nº: %d\n", i);
		printf("Antes do strdup: %s", nrcliente);
		clientes[i++] = strdup(nrcliente);
		printf("%d ----- %s\n", i ,clientes[i-1]);	
	}
	fclose(fclientes);
}


int main(){
	FILE* fclientes = fopen("Clientes.txt", "r");

	char* clientes [NRCLIENTES];

	readFileClientes(fclientes, clientes);
	
	for(int indice = 0; indice < NRCLIENTES; indice++){
		printf("%d : %s", indice,clientes[indice]);
	}

	fclose(fclientes);
	return 0;
}