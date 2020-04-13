#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

using namespace std;

struct Nodo{
  int dato;
  Nodo *sig;
  Nodo *anterior;
}*inicial;

void agregar();
void mostrar();
void eliminar();
void buscar();
Nodo *buscarLista(int);

int main(){
	int opc;

	do{
		cout<<".:Lista Doblemente Enlazada:."<<endl;
		cout<<"1.Agregar"<<endl;
		cout<<"2.Mostrar"<<endl;
		cout<<"3.Buscar"<<endl;
		cout<<"4.Eliminar"<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"Opcion: "; cin>>opc;

		switch(opc){
			case 1:
				agregar();
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"\nMostrando lista\n";
				mostrar();
				cout<<"\n";
				system("pause");
				break;

			case 3:
				buscar();
				cout<<"\n";
				system("pause");
				break;

			case 4:
				eliminar();
				cout<<"\n";
				system("pause");
				break;

			case 5:
				cout<<"\n";
				system("pause");
				break;
	    }
	    system("cls");
	}while(opc != 5);
}

void agregar(){
	Nodo *nuevo, *anterior;
	nuevo = new Nodo();
	bool band = false;

	cout<<"\nDigite el elemento que desea agregar a la lista: "; cin>>nuevo->dato;

	if(inicial != NULL){
    Nodo *aux;
		aux = inicial;
	  while(aux != NULL){
		   if(aux->dato == nuevo->dato){
		    	aux = NULL;
			    band = true;
		    }
		    else{
			   	aux = aux->sig;
			}
		}
	}

	if(band == true){
		cout<<"\nElemento ya se encuentra en la lista\n";
	}
	else{
		if(inicial == NULL){
		    inicial = nuevo;
		    nuevo->anterior = NULL;
		    nuevo->sig = NULL;
	    }
	    else{
	    	anterior = buscarLista(nuevo->dato);
		    if(anterior == NULL){
			    nuevo->sig = inicial;
			    nuevo->anterior = inicial->anterior;
			    inicial->anterior = nuevo;
			    inicial = nuevo;
		    }
		    else{
			    if(anterior->sig != NULL){
				    nuevo->sig = anterior->sig;
				    nuevo->anterior = anterior;
				    anterior->sig->anterior = nuevo;
				    anterior->sig = nuevo;
			    }
			    else{
				    nuevo->sig = anterior->sig;
				    nuevo->anterior = anterior;
				    anterior->sig = nuevo;
			    }
		    }
	    }
	    cout<<"\nElemento fue agregado a la lista\n";
	}
}

void buscar(){
	bool band = false;
	int n = 0;
	Nodo *actual = new Nodo();
	actual = inicial;

	cout<<"\nIngrese el elemento que desea buscar: ";	cin>>n;

	while((actual!= NULL) && (actual->dato <= n)){
		if(n == actual->dato){
			band = true;
		}
		actual = actual->sig;
	}
	if(band == true){
		cout<<"\nElemento encontrado en la lista\n";
	}
	else{
		cout<<"\nElemento no existe en la lista\n";
	}
}

void eliminar(){
	Nodo *actual = new Nodo();
	actual = inicial;
	Nodo *anterior = new Nodo();
	anterior = NULL;
	bool encontrado = false;
	int n;

	cout<<"\nIngrese el dato que desea eliminar: ";
	cin>>n;

	if(inicial != NULL){

		while(actual != NULL && encontrado != true){

			if(actual->dato == n){
				if(actual==inicial){
					inicial = inicial->sig;
					inicial->anterior = NULL;
				}
				else if(actual->sig = NULL){
					anterior->sig = NULL;
					actual->sig = anterior;
				}
				else{
					anterior->sig = actual->sig;
					actual->sig->anterior = anterior;
				}
				cout<<"\nElemento Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->sig;
		}

		if(!encontrado){
			cout<<"\nElemento no fue encontrado\n";
		}

	}else{
		cout<<"\nLa lista se encuentra vacia\n";
	}
}

void mostrar(){
	if(inicial == NULL){
		cout<<"\nLa lista esta vacia\n";
	}
	else{
		Nodo *apunt;
		apunt = inicial;
		while(apunt != NULL){
			cout<<apunt->dato<<" -> ";
			apunt = apunt->sig;
		}
	}
}

Nodo *buscarLista(int clave){
	Nodo *anterior;
	anterior = NULL;

	if(clave <= inicial->dato){
	    return anterior;
    }
    else{
	    anterior = inicial;
	    while((anterior->sig != NULL) && (clave > anterior->sig->dato)){
		    anterior = anterior->sig;
        }
        return anterior;
	}
}
