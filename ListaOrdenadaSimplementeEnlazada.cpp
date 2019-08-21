#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

/*  Lista ordenada simplemente enlazada

 */

struct nodo{
    nodo* siguiente;
    int dato;
};

typedef nodo* Nodo;

void push(Nodo &,int);
void pop(Nodo &,int);
void mostrar(Nodo);
int tamano(Nodo);
void buscar(Nodo ,int);

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
    
    return 0;
}

void push(Nodo &lista,int dato){                            // Paso por referencia
    Nodo nuevo=new nodo();                                  // nodo* nuevo=new nodo();
    nuevo->dato=dato;                                       // Asigno el valor al nuevo nodo de la lista

    if(lista==NULL){                                        // Si la lista esta vacia
        lista=nuevo;
        cout<<"Lista estaba vacia"<<endl;              
        cout<<"Elemento "<<dato<<" añadido"<<endl;
    }else{                                                  // Si no esta vacia                                  
        Nodo sig=lista;                                     // Dos apuntadores auxiliares
        Nodo actual=lista;                                  // Uno a el elemento actual y otro al siguiente (mayor y menor)
        
        while((sig!=NULL)&&(sig->dato<dato)){               // Busco en la lista la posicion en la que va nuevo (entre actual y sig)
            actual=sig;
            sig=sig->siguiente;
        }
                                                            // Si no entra al while o termina, ya encontro la posición en donde va nuevo (entre actual y sig) 
        if(actual==sig){                                    // Si actual y sig son iguales entonces nuevo va primero en la lista
            nuevo->siguiente=lista;                     
            lista=nuevo;    
        }else{
            actual->siguiente=nuevo;                        // En caso contrario va entre elementos y se inserta despues de actual y antes de siguiente
            nuevo->siguiente=sig;
        }
        cout<<"Elemento "<<dato<<" añadido"<<endl;
    }
}

void pop(Nodo &lista,int dato){
    if(lista==NULL){
        cout<<"\nLista vacia"<<endl;
    }else{
        Nodo sig=lista;                                     // Dos apuntadores auxiliares
        Nodo actual=lista;                                  // Uno a el elemento actual y otro al siguiente (mayor y menor)
        
        while((sig!=NULL)&&(sig->dato!=dato)){              // Busco en la lista la posicion en la que va nuevo (entre actual y sig)
            actual=sig;
            sig=sig->siguiente;
        }

        if(sig==NULL){                                              // Ultimo elemento y sin coincidencias
            cout<<"\nElemento "<<dato<<" no existe"<<endl;
        }

        if(actual==sig){                                            // El elemento a eliminar esta primero
            lista=sig->siguiente;
            cout<<"\nElemento "<<dato<<" eliminado"<<endl;
        }else{                                                      // El elemento a eliminar es cualquiera de los otros
            actual->siguiente=sig->siguiente;
            cout<<"\nElemento "<<dato<<" eliminado"<<endl;
        }
    }
}

void mostrar(Nodo lista){                                   // Paso por valor
    Nodo aux=lista;                                         // Apuntador auxiliar que comienza donde inicia la lista (No es necesario XD trabaja con lista)
    if(lista==NULL){
        cout<<"Lista vacia"<<endl;
    }else{
        while(aux->siguiente!=NULL){                        // Mientras aux->siguiente sea diferente de nulo va a imprimir el elemento
            cout<<aux->dato<<endl;
            aux=aux->siguiente;                             // Imprime y aux avanza al siguente
        }
        cout<<aux->dato<<endl;                              // Imprime el ultimo elemento de la lista
    }


}

int tamano(Nodo lista){                                     // Paso por valor
    Nodo aux=lista;                                         // Apuntador auxiliar que comienza donde inicia la lista (No es necesario XD trabaja con lista)
    int pos=0;
    while(aux->siguiente!=NULL){                            // Mientras aux->siguiente sea diferente de nulo (Recorre toda la lista)
        aux=aux->siguiente;                                 // Aumenta el numero de elementos y pasa al siguiente
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
        while(aux->siguiente!=NULL){                        // Mientras aux->siguiente sea diferente de nulo (recorre toda la lista) va a imprimir el elemento
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

        if(aux->siguiente==NULL && aux->dato==buscar){                          // Checa el ultimo elemento
            cout<<"Encontrado "<<buscar<<" en la posicion "<<pos<<endl;
            flg++;
        }

        if(flg==0){                                                             // No encontro el elemento
            cout<<"Elemento "<<buscar<<" no existe "<<endl;
        }
    }
}
