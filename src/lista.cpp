#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipos de Funciones
void Menu();
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);
void eliminarElemento(Nodo *&,int);
void eliminarLista(Nodo *&, int &);

//variable global
Nodo *lista=NULL;
//principal
int main()
{
    Menu();
    return 0;
}

void Menu(){
    int opcion,dato;
    
    do{
        cout<<"\t.:MENU:.\n";
        cout<<"1. Insertar elementos a la lista\n";
        cout<<"2. Mostrar elementos de la lista\n";
        cout<<"3. Buscar un elemento\n";
        cout<<"4. Quitar un elemento\n";
		cout<<"5. Vaciar lista\n";
        cout<<"6. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;
        
        switch(opcion){
            case 1: 
					cout<<"Digite un numero: ";
                    cin>>dato;
                    insertarLista(lista,dato);
                    cout<<"\n";
                    system("pause");
                    break;
            case 2: 
					mostrarLista(lista);
                    cout<<"\n";
                    system("pause");
                    
                    break;
            case 3:
            		cout<<"Ingrese elemento a buscar:";
            		cin>>dato;
            		buscarLista(lista,dato);
            		cout<<"\n";
					system("pause");
            		break;
            case 4:
            		cout<<"Ingrese elemento a eliminar:";
            		cin>>dato;
            		eliminarElemento(lista,dato);
            		cout<<"\n";
					system("pause");
            		break;
            case 5:
            		while(lista!=NULL){
            			eliminarLista(lista,dato);
            			cout<<dato<<" -> ";
					}
					cout<<"\n";
					system("pause");
					break;
        }
        system("cls");
    }while(opcion!=6);
}

void insertarLista(Nodo *&lista,int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato=n;
    
    Nodo *aux1=lista;
    Nodo *aux2;

 //Lista ordenada   
    while((aux1!=NULL) && (aux1->dato<n)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    
    if(lista==aux1){
        lista=nuevo_nodo;
    }
    else{
        aux2->siguiente=nuevo_nodo;
    }
    //   * -> * -> *
    
    nuevo_nodo->siguiente=aux1;
    cout<<"\t Elemento "<<n<<" insertado a la lista correctamente\n";
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual=lista;

    while(actual != NULL){
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;
	}
}

void buscarLista(Nodo *lista, int n){
	bool bandera=false;
	Nodo *actual=new Nodo();
	actual=lista;
	//Recorrer la lista y activar bandera para identificar si el elemnto se ha encontrado
	while((actual!=NULL) && (actual->dato<=n)){
		if(actual->dato==n){
			bandera=true;
		}
		actual=actual->siguiente;
	}
	if(bandera==true){
		cout<<"Elemento "<<n<<" Si se encuentra en la lista\n";
	}
	else{
		cout<<"Elemento "<<n<<" No se encuentra en la lista\n";		
	}
}

void eliminarElemento(Nodo *&lista,int n){
	if(lista!=NULL){
		Nodo *aux_borrar;
		Nodo *anterior=NULL;
		aux_borrar=lista;
		//Recorrer la lista
		while((aux_borrar !=NULL) && (aux_borrar->dato !=n)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		//El elemento no ha sido encontrado
		if(aux_borrar==NULL){
			cout<<"El elemento no existe";
		}
		//El primer elemento es el que se elimina
		else if(anterior==NULL){
			lista=lista->siguiente;
			delete aux_borrar;
			cout<<"El elemento "<<n<< " se ha eliminado con exito";
		}
		//El elemento se ha encontrado y se eliminara
		else{
			anterior->siguiente =aux_borrar->siguiente;
			delete aux_borrar;
			cout<<"El elemento "<<n<< " se ha eliminado con exito";
		}
	}
}

void eliminarLista(Nodo *&lista,int &n){
	Nodo *aux=lista;
	n=aux->dato;
	lista=aux->siguiente;
	delete aux;
}
