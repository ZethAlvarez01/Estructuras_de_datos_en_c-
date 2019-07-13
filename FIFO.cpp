#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

/*  FIFO
    First in, firts out
    Esta es una cola.
    El primer elemento en entrar es el primero en salir.
 */

struct nodo{             // Estructura basica de un nodo
    nodo* arriba;        // Apuntador al dato de arriba
    string data;         // Elemento/Valor/Dato que guarda el nodo
};

typedef nodo* Nodo;     // Cambiamos la declaracion de un apuntador nodo* por Nodo (Solo le cambiamos el nombre)

/* Funcion PUSH 
   Sacar un elemento en la cola
*/
void push(Nodo &inicio,Nodo &final,string data){    // Recibe por REFERENCIA el INICIO, FINAL y el dato de la cola
    Nodo nuevo=new nodo();                          // Instancia de un nuevo nodo
    nuevo->data=data;                               // Guardamos el dato que querramos en el nuevo nodo
    nuevo->arriba=NULL;                             // Se asigna el valor de NULL al puntero arriba del nuevo nodo
    if(inicio==NULL && final==NULL){                // Si la cola esta vacia
        inicio=nuevo;                               // INICIO el igual al nuevo nodo
    }else{                                          // Si no esta vacia
        final->arriba=nuevo;                      // FINAL->ARRIBA apunta al nuevo nodo creado 
    }
    final=nuevo;                                    // Y final apunta a nuevo (Siempre pasa)
    cout<<"Push: "<<data<<endl;
}

/* Funcion PUSH 
   Sacar un elemento en la cola
*/
string pop(Nodo &inicio,Nodo &final){               // Recibe por REFERENCIA el INICIO y FINAL de la cola
    string data;
    if(inicio==NULL && final==NULL){                // Si la cola esta vacia
        return "Cola vacia";                        // Regresa que esta vacia
    }else{
        data=inicio->data;                          // El valor que este en el primer nodo pasa a DATA
        if(inicio == final){                        // Si solo hay un nodo en la cola   
            inicio=NULL;                            // INICIO y FINAL se vuelven nulos 
            final=NULL;
            return data;                            // Regreso DATA
        }else{                                      // Si existen mas nodos en la cola
            inicio=inicio->arriba;                  // INICIO se convierte en el valor siguente al que apunta INICIO->ARRIBA
            return data;                            // Regreso DATA
        }           
    }
}

/* Funcion SIZE
   Cuenta los elementos en la cola
*/
void size(Nodo inicio){                             // Recibe por valor el INICIO de la cola
    int elementos=0;                                // Contador
    while(inicio!=NULL){                            // Este ciclo recorre toda la cola hasta encontrar el ultimo elemento
        inicio=inicio->arriba;                      // Cada que encuentra un elemento cambia el valor de inicio por el proximo elemento
        elementos++;                                // Y aumenta el el numero de elementos existentes
    }
    cout<<"Elementos en la cola: "<<elementos<<endl;
}


int main(){
    Nodo inicio = NULL;                             // Apuntador al inicio de la cola
    Nodo final = NULL;                              // Apuntador al final de la cola

    size(inicio);
    push(inicio,final,"Primero");
    push(inicio,final,"Segundo");
    push(inicio,final,"Tercero");
    size(inicio);

    cout<<pop(inicio,final)<<endl;
    cout<<pop(inicio,final)<<endl;
    cout<<pop(inicio,final)<<endl;
    cout<<pop(inicio,final)<<endl;
    push(inicio,final,"Cuarto");
    push(inicio,final,"Quinto");
    size(inicio);
    cout<<pop(inicio,final)<<endl;
    cout<<pop(inicio,final)<<endl;
    cout<<pop(inicio,final)<<endl;
    size(inicio);

    return 0;
}