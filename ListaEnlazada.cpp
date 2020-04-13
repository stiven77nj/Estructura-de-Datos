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
}*inicio;

void agregar();
void mostrar();
void eliminar(int);
void buscarElemento(int);
Nodo *buscar(int);

int main(){
  int opc;
  int dato;

  do{
    cout<<".:Lista Enlazada:."<<endl;
    cout<<"1.Agregar"<<endl;
    cout<<"2.Mostrar"<<endl;
    cout<<"3.Eliminar"<<endl;
    cout<<"4.Buscar"<<endl;
    cout<<"5.Salir"<<endl;
    cout<<"Opcion: "; cin>>opc;

    switch(opc){
      case 1:
        agregar();
        cout<<"\n";
        system("pause");
        break;

      case 2:
      cout<<"\nMostrando Cola\n";
        mostrar();
        cout<<"\n";
        system("pause");
        break;

      case 3:
        cout<<"\nDigite el elemento que desea eliminar de la lista: "; cin>>dato;
				eliminar(dato);
				cout<<"\n";
				system("pause");
				break;

      case 4:
        cout<<"\nDigite el elemento que desea buscar en la lista: "; cin>>dato;
        buscarElemento(dato);
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
  Nodo *nuevo = new Nodo();
  Nodo *anterior;
  bool band = false;

  cout<<"\nDigite el elemento que desea ingresar: "; cin>>nuevo->dato;

  if(inicio != NULL){
    Nodo *aux;
    aux = inicio;

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
    if(inicio == NULL){
      inicio = nuevo;
      nuevo->sig = NULL;
    }
    else{
      anterior = buscar(nuevo->dato);
      if(anterior == NULL){
        nuevo->sig = inicio;
        inicio = nuevo;
      }
      else{
        if(anterior->sig != NULL){
          nuevo->sig = anterior->sig;
          anterior->sig = nuevo;
        }
        else{
          nuevo->sig = NULL;
          anterior->sig = nuevo;
        }
      }
    }
  cout<<"\nElemento agregado a la lista\n";
  }
}

void mostrar(){
  if(inicio == NULL){
    cout<<"\nLista vacia\n";
  }

  Nodo *apun = inicio;
  while(apun != NULL){
    cout<<apun->dato<<" -> ";
    apun = apun->sig;
  }
  cout<<"\n";
}

void buscarElemento(int n){
	Nodo *actual = new Nodo();
  bool band = false;
	actual = inicio;

	while((actual != NULL) && (actual->dato <= n)){
		if(actual->dato == n){
			band = true;
		}
		actual = actual->sig;
	}
	if(band == true){
		cout<<"\nElemento encontrado en la lista\n";
	}
	else{
		cout<<"\nElemento no ha sido encontrado en la lista\n";
	}
	cout<<"\n";
}

void eliminar(int n){
	if(inicio != NULL){
		Nodo *aux_borrar = inicio;
		Nodo *anterior;

		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
		}
		if(aux_borrar == NULL){
			cout<<"\nElemento no existe\n";
		}
		else if(anterior == NULL){
			inicio = inicio->sig;
			delete aux_borrar;
		}
		else{
			anterior->sig = aux_borrar->sig;
			delete aux_borrar;
		}
	}
	else{
		cout<<"\nLa lista esta vacia";
	}
	cout<<"\n";
}

Nodo *buscar(int clave){
	Nodo *anterior = NULL;

	if(clave <= inicio->dato){
		return anterior;
	}
	else{
		anterior = inicio;
		while((anterior->sig != NULL) && (clave > anterior->sig->dato)){
			anterior = anterior->sig;
		}
		return anterior;
	}
}
