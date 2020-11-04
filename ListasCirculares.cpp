#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

/* Listas Circulares

*/

struct nodo{
	nodo* siguiente;
	int dato;
};

typedef nodo* Nodo;

//Operaciones

void push(Nodo &,int);
int pop(Nodo &,int);
void mostrar(Nodo);
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
    	mostrar(lista);

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
    	mostrar(lista);

   	pop(lista,5);

    	cout<<"\nMostrar"<<endl;
    	mostrar(lista);

    	pop(lista,9);

    	cout<<"\nMostrar"<<endl;
    	mostrar(lista);

	pop(lista,-2);
	cout<<"\nMostrar"<<endl;
	mostrar(lista);

    	return 0;
}

void push(Nodo &lista, int dato){
	Nodo nuevo = new nodo();
	nuevo->dato = dato;

	if(lista == NULL){
		cout<<"Listas vacia"<<endl;
		lista = nuevo;
		cout<<"Elemento "<<dato<<" añadido"<<endl;
		lista->siguiente = lista;
	}else{
		Nodo aux = lista;
		while(aux->siguiente != lista){
			aux = aux->siguiente;
		}

		aux->siguiente = nuevo;
		nuevo->siguiente = lista;
		
		cout<<"Elemento "<<dato<<" añadido"<<endl;
	}
}


int pop(Nodo &lista,int dato){
    if(lista==NULL){
        cout<<"\nLista vacia"<<endl;
    }else{
        Nodo sig=lista->siguiente;                                     // Dos apuntadores auxiliares
        Nodo actual=lista;                                  // Uno a el elemento actual y otro al siguiente (mayor y menor)
        
	while(actual->siguiente != lista && sig->dato != dato){
		sig = sig->siguiente;
		actual = actual->siguiente;
	}
	if(actual->siguiente == lista && sig->dato == dato){
		lista = sig->siguiente;
		actual->siguiente = lista;
		cout<<"Elemento "<<dato<<" eliminado"<<endl;
	}else if(sig->dato == dato){
		actual->siguiente = sig->siguiente;
		cout<<"Elemento "<<dato<<" eliminado"<<endl;
	}else{
		cout<<"Elemento "<<dato<<" no existe"<<endl;
	}

    }
}


int tamano(Nodo lista){                                     // Paso por valor
    Nodo aux=lista;                                         // Apuntador auxiliar que comienza donde inicia la lista
    int pos=0;
    while(aux->siguiente!=lista){                            // Mientras aux->siguiente sea diferente de nulo (Recorre toda la lista)
        aux=aux->siguiente;                                 // Aumenta el numero de elementos y pasa al siguiente
        pos++;
    }
    pos++;                                                  // Ultimo elemento
    
    return pos;
}

void mostrar(Nodo lista){
	Nodo aux = lista;
	while(aux->siguiente != lista){
		cout<<aux->dato<<endl;
		aux = aux->siguiente;
	}
	cout<<aux->dato<<endl;

}

void buscar(Nodo lista,int buscar){                         // Paso por valor
    if(lista==NULL){
        cout<<"Lista vacia"<<endl;
    }else{
        int flg=0;
        int pos=0;                                          // Posicion en la que va
        Nodo aux=lista;                                     
        while(aux->siguiente!=lista){                        // Mientras aux->siguiente sea diferente de nulova a imprimir el elemento
            if(aux->dato==buscar){                          // Ya lo encontro
                cout<<"Encontrado "<<buscar<<" en la posicion "<<pos<<endl; 
                flg++;
                aux=aux->siguiente;                         // Pero sigue buscando
                pos++;
            }else{
                aux=aux->siguiente;                         // No lo encontro pero siguie buscando
                pos++;
            }
        }

        if(aux->siguiente==lista && aux->dato==buscar){                          // Checa el ultimo elemento
            cout<<"Encontrado "<<buscar<<" en la posicion "<<pos<<endl;
            flg++;
        }

        if(flg==0){                                                             // No encontro el elemento
            cout<<"Elemento "<<buscar<<" no existe "<<endl;
        }
    }
}










