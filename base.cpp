#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

/* Listas

*/

struct nodo{
	nodo* siguente;
	int dato;
};

typedef nodo* Nodo;

//Operaciones

void push(Nodo &,int);
void pop(Nodo &,int);
void mostrar(Nodo);
int tamano(Nodo);
void buscar(Nodo, int);

int main(){

	Nodo lista = NULL;


    	return 0;
}



