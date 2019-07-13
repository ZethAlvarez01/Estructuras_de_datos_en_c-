#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

/*  LIFO
    Last in, firts out
    Esta es una pila.
    El ultimo elemento en entrar es el primero en salir.
 */

struct nodo{              // Estructura basica de un nodo
    struct nodo* sig;     // Apuntador al dato de abajo/siguiente por sacar
    string data;          // Elemento/Valor/Dato que guarda el nodo
};

typedef nodo* Nodo;       // Cambiamos la declaracion de un apuntador nodo* por Nodo (Solo le cambiamos el nombre)

/* Funcion PUSH 
   Colocar un elemento en la pila
*/
void push(Nodo &pila,string data){    // Recibe por REFERENCIA pila y el dato
    Nodo nuevo=new nodo();            // Instancia de un nuevo nodo

    nuevo->data=data;                 // Guardamos el dato que querramos en el nuevo nodo
    nuevo->sig=pila;                  // El valor de sig va a apuntar a donde en este momento este apuntando la pila
    pila=nuevo;                       // Pila cambia su valor al del nuevo nodo

    cout<<"Elemento -"<<nuevo->data<<"- agregado"<<endl;
}

/* Funcion PUSH 
   Sacar un elemento en la pila
*/
string pop(Nodo &pila){                // Recibe por REFERENCIA pila
    string data;                       
    if(pila==NULL){                    // Comprueba si la pila esta vacia
        return "Pila vacia";
    }else{
        Nodo aux=pila;                 // Se crea un nodo auxiliar con el valor de pila

        data=aux->data;                // Se extrae el dato del nodo y se asigna a una variable
        pila=aux->sig;                 // pila toma el valor del nodo de abajo/siguente
        delete aux;                    // Limpiamos memoria eliminando el nodo auxiliar
        cout<<"Elemento -"<<data<<"- removido"<<endl;
        return data;                   // Regresamos el dato extraido
    }
    
}

/* Funcion SIZE
   Cuentas los elementos de la pila
*/
int size(Nodo pila){            // Recibe por VALOR la pila
    int i=0;                    // contador de elementos
    while(pila!=NULL){          // Ciclo que recorre toda la pila
        i++;                    // Aumenta cada que sig tenga un elemento nodo atado
        pila=pila->sig;         // Cambiamos al siguiente nodo
    }
    return i;                   // Regresamos el numero de elementos
}

int main(){
    string elemento;
    
    Nodo pila = NULL ;      // Apuntador al tope de la pila o la pila en si

    push(pila,"Primero");
    push(pila,"Segundo");
    push(pila,"Tercero");

    cout<<"Tamaño: "<<size(pila)<<endl;

    pop(pila);
    pop(pila);

    push(pila,"Cuarto");
    push(pila,"Quinto");
    push(pila,"Sexto");
    push(pila,"Septimo");

    pop(pila);

    cout<<"Tamaño: "<<size(pila)<<endl;

    return 0;
}