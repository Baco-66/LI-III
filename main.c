#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NRCLIENTES 20000

// clientes[indice][numero]

void readFileClientes (FILE* fclientes,char **clientes){
	int size = 6;
	char nrcliente[size];
	int i = 0; int aux = 0;
	printf("%d\n",i);
	while(fgets(nrcliente, size, fclientes) && aux < 10){
		printf("%d\n", i);
		clientes[i] = strdup(nrcliente);
		printf("%d ----- %s", i ,clientes[i]);
		i++; 

	}
	printf("%d\n", i);
}


int main(){
	FILE* fclientes = fopen("Clientes.txt", "r");

	char* clientes [NRCLIENTES];

	readFileClientes(fclientes, clientes);
	
	for(int indice = 0; indice < NRCLIENTES; indice++){
		printf("%s\n", clientes[indice]);
	}
}