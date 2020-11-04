#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

/* Listas doblemente enlazadas

*/

struct nodo{
	nodo* arriba;
	nodo* abajo;
	int dato;
};

typedef nodo* Nodo;

void push(Nodo &,int);
void pop(Nodo &,int);
void mostrarArribaAbajo(Nodo);
void mostrarAbajoArriba(Nodo);
int tamano(Nodo);
void buscar(Nodo, int);


int main(){

    	Nodo lista = NULL;

    	cout<<"\n--Añadir--"<<endl<<endl;

    	push(lista,5);
    	push(lista,1);
    	push(lista,3);
    	push(lista,-2);
    	push(lista,2);
    	push(lista,0);
    	push(lista,3);
    	push(lista,4);

    	cout<<"\n--Mostrar--"<<endl<<endl;
    	mostrarArribaAbajo(lista);

    	cout<<"\n--Buscar--"<<endl<<endl;

    	buscar(lista,3);
    	buscar(lista,0);
    	buscar(lista,-2);
   	buscar(lista,5);
    	buscar(lista,8);

    	cout<<"\nTamaño: "<<tamano(lista)<<endl;

    	cout<<"\n--Eliminar--"<<endl;

    	pop(lista,3);

    	cout<<"\nMostrar"<<endl;
    	mostrarArribaAbajo(lista);

    	pop(lista,5);

    	cout<<"\nMostrar"<<endl;
    	mostrarArribaAbajo(lista);

    	pop(lista,9);

    	cout<<"\nMostrar"<<endl;
    	mostrarArribaAbajo(lista);


    	return 0;
}

void push(Nodo &lista, int dato){
	
	Nodo nuevo = new nodo();
	nuevo->dato = dato;

	if(lista == NULL){
		lista = nuevo;
		cout<<"Lista estaba vacia"<<endl;
		cout<<"Elemento "<<dato<< "añadido"<<endl;
	}else{
		Nodo siguiente = lista;

		while(siguiente->abajo != NULL){
			siguiente = siguiente->abajo;
		}

		siguiente->abajo = nuevo;
		nuevo->arriba = siguiente;

		cout<<"Elemento "<<dato<<" añadido"<<endl;
	}

}

void pop(Nodo &lista,int dato){

	Nodo aux = lista;							// Un solo apuntador auxiliar apuntando a Lista

	if(lista == NULL){
		cout<<"\nLista vacia"<<endl;
	}else{
		while(( aux->abajo != NULL ) && ( aux->dato != dato )){		// Se busca el elemento
			aux = aux->abajo;	
		}	

		if(( aux->abajo == NULL ) && ( aux->dato != dato )){ 		// El elemento no existe

			cout<<"\nElemento "<<dato<<" no existe"<<endl;
			 
		}else{
			if(aux->arriba == NULL){
				lista = lista->abajo;
				lista->arriba = NULL;
			}else if(aux->abajo == NULL){
			 	aux = aux->arriba;
				aux->abajo = NULL;
			}else{
				Nodo aux2 = aux;
				aux = aux->arriba;
				aux->abajo = aux2->abajo;
				aux2 = aux2->abajo;
				aux2->arriba = aux;
			}
			cout<<"Elemento "<<dato<<" eliminado"<<endl;
		}
	}
}

void mostrarArribaAbajo(Nodo lista){
	Nodo siguiente = lista;

	if(lista == NULL){
		cout<<"Lista vacia"<<endl;
	}else{
		while(siguiente->abajo != NULL){
			cout<<siguiente->dato<<endl;
			siguiente = siguiente->abajo;
		}
		cout<<siguiente->dato<<endl;
	}
}

void mostrarAbajoArriba(Nodo lista){
	Nodo siguiente = lista;
	
	if(lista == NULL){
		cout<<"Lista vacia"<<endl;
	}else{
		while(siguiente->abajo != NULL){
			siguiente = siguiente->abajo;
		}

		while(siguiente->arriba != NULL){
			cout<<siguiente->dato<<endl;
			siguiente = siguiente->arriba;
		}
		cout<<siguiente->dato<<endl;
	}
}


int tamano(Nodo lista){                                     // Paso por valor
	Nodo aux=lista;                          // Apuntador auxiliar que comienza donde inicia la lista (No es necesario XD trabaja con     lista)
	int pos=0;
	while(aux->abajo!=NULL){                            // Mientras aux->siguiente sea diferente de nulo (Recorre toda la lista)
		aux=aux->abajo;                                 // Aumenta el numero de elementos y pasa al siguiente
		pos++;
	}
	pos++;                                                  // Ultimo elemento
	
	return pos;
}


void buscar(Nodo lista,int buscar){                         // Paso por valor
    if(lista==NULL){
        cout<<"Lista vacia"<<endl;
    }else{
        int flg=0;
        int pos=0;                                          // Posicion en la que va
        Nodo aux=lista;                                     // (No es necesario XD trabaja con lista)
        while(aux->abajo!=NULL){                        // Mientras aux->siguiente sea diferente de nulo (recorre toda la lista) va a imprimir el elemento
            if(aux->dato==buscar){                          // Ya lo encontro
                cout<<"Encontrado (arriba hacia abajo)"<<buscar<<" en la posicion "<<pos<<endl; 
                flg++;
                aux=aux->abajo;                         // Pero sigue buscando
                pos++;
            }else{
                aux=aux->abajo;                         // No lo encontro pero siguie buscando
                pos++;
            }
        }

        if(aux->abajo==NULL && aux->dato==buscar){                          // Checa el ultimo elemento
            cout<<"Encontrado (arriba hacia abajo)"<<buscar<<" en la posicion "<<pos<<endl;
            flg++;
        }

        if(flg==0){                                                             // No encontro el elemento
            cout<<"Elemento (arriba hacia abajo)"<<buscar<<" no existe "<<endl;
        }
    }
}





























