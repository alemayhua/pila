#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	nodo *siguiente;
};

void inicializar(nodo *&frente);
void agregar(nodo *&frente, int numero);
void eliminar(nodo *&frente);
void listar(nodo *&frente);


int main(){
	int cantidad, dato;
	nodo *frente;
	inicializar(frente);
	printf("Ingrese cantidad de datos a cargar en la pila: ");
	scanf("%d", &cantidad);
	for(int i = 0; i < cantidad; i++){
		printf("Ingrese dato %d: ", i);
		scanf("%d", &dato);
		agregar(frente, dato);
	}
	eliminar(frente);
	listar(frente);
	system("pause");
	return (0);
}

void inicializar(nodo *&frente){
	frente = NULL;
}

void agregar(nodo *&frente, int numero){
	nodo *nuevo_nodo = new nodo;
	nuevo_nodo -> dato = numero;
	nuevo_nodo -> siguiente = frente;
	frente = nuevo_nodo;
}

void eliminar(nodo *&frente){
	if(frente != NULL){
		int numeroEliminado;
		nodo *auxiliar = frente;
		numeroEliminado = frente -> dato;
		frente = frente -> siguiente;
		delete auxiliar;
		printf("\nDato del frente de la pila %d eliminado\n", numeroEliminado);
	}else{
		printf("\nLa pila esta vacia\n");
	}
}

void listar(nodo *&frente){
	printf("LISTANDO PILA\n");
	nodo *auxiliar = frente;
	while(auxiliar != NULL){
		printf("Dato: %d\n", auxiliar -> dato);
		auxiliar = auxiliar -> siguiente;
	}
}