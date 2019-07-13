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
    nodo* abajo;          // Apuntador al dato de abajo
    string data;          // Elemento/Valor/Dato que guarda el nodo
};

typedef nodo* Nodo;       // Cambiamos la declaracion de un apuntador nodo* por Nodo (Solo le cambiamos el nombre)

/* Funcion PUSH 
   Colocar un elemento en la pila
*/
void push(Nodo &pila,string data){    // Recibe por REFERENCIA pila y el dato
    Nodo nuevo=new nodo();            // Instancia de un nuevo nodo

    nuevo->data=data;                 // Guardamos el dato que querramos en el nuevo nodo
    nuevo->abajo=pila;                // El valor de sig va a apuntar a donde en este momento este apuntando la pila
    pila=nuevo;                       // Pila cambia su valor al del nuevo nodo

    cout<<"Push: "<<data<<endl;
}

/* Funcion PUSH 
   Sacar un elemento en la pila
*/
string pop(Nodo &pila){                                 // Recibe por REFERENCIA pila
    string data;                       
    if(pila==NULL){                                     // Comprueba si la pila esta vacia
        return "Pila vacia";
    }else{
        Nodo aux=pila;                                  // Se crea un nodo auxiliar con el valor de pila
        data=aux->data;                                 // Se extrae el dato del nodo y se asigna a una variable
        pila=aux->abajo;                                // pila toma el valor del nodo de abajo
        delete aux;                                     // Limpiamos memoria eliminando el nodo auxiliar
        return data;                                    // Regresamos el dato extraido
    }
    
}

/* Funcion SIZE
   Cuentas los elementos de la pila
*/
void size(Nodo pila){              // Recibe por VALOR la pila
    int i=0;                      // contador de elementos
    while(pila!=NULL){            // Ciclo que recorre toda la pila
        i++;                      // Aumenta cada que abajo tenga un elemento nodo atado
        pila=pila->abajo;         // Cambiamos al siguiente nodo
    }
    cout<<"Elementos en la pila: "<<i<<endl;                   // Regresamos el numero de elementos
}

int main(){
    string elemento;
    
    Nodo pila = NULL ;      // Apuntador al tope de la pila o la pila en si

    size(pila);
    push(pila,"Primero");
    push(pila,"Segundo");
    push(pila,"Tercero");
    size(pila);

    cout<<pop(pila)<<endl;
    cout<<pop(pila)<<endl;
    cout<<pop(pila)<<endl;
    cout<<pop(pila)<<endl;
    push(pila,"Cuarto");
    push(pila,"Quinto");
    size(pila);
    cout<<pop(pila)<<endl;
    cout<<pop(pila)<<endl;
    cout<<pop(pila)<<endl;
    size(pila);

    return 0;
}