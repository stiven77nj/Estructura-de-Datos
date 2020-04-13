#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#include<string.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
	Nodo *anterior;
}*inicial;

void agregar();
void mostrar();
void eliminar();
void buscar();
Nodo *buscarUltimo();
Nodo *buscarLista(int);

int main(){
	int opc, dato;

	do{
		cout<<"\n.:Lista Circular Enlazada:.";
		cout<<"\n1.Agregar";
		cout<<"\n2.Mostrar";
		cout<<"\n3.Buscar";
    cout<<"\n4.Eliminar";
		cout<<"\n5.Salir";
		cout<<"\nOpcion: "; cin>>opc;

		switch(opc){
			case 1:
				agregar();
				cout<<"\n";
				system("pause");
				break;

			case 2:
			    cout<<"\nMostrando lista";
			    cout<<"\n";
			    mostrar();
			    cout<<"\n";
			    system("pause");
				break;

			case 3:
				buscar();
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

void mostrar(){
	Nodo *apun;
	if(inicial == NULL){
		cout<<"La lista esta vacia"<<endl;
	}
	else{
		apun = inicial;
		do{
			cout<<apun->dato<<" -> ";
			apun = apun->siguiente;
		}while(apun != inicial);
	}
	cout<<"\n";
}

void agregar(){
    bool band = false;
	Nodo *nuevo, *anterior;

	nuevo = new Nodo();

	cout<<"\nDigite el elemento que desea agregar a la lista: "; cin>>nuevo->dato;

	if(inicial == NULL){
		inicial = nuevo;
		nuevo->siguiente = nuevo;
	}
	else{
		anterior = buscarLista(nuevo->dato);
		if(anterior == NULL){
			Nodo *ultimo;
			ultimo = buscarUltimo();
			ultimo->siguiente = nuevo;
			nuevo->siguiente = inicial;
			inicial = nuevo;
		}
		else{
			nuevo->siguiente = anterior->siguiente;
			anterior->siguiente = nuevo;
		}
	}
	cout<<"\nEl elemento "<<nuevo->dato<<" fue agregado a la lista\n";
}

void buscar(){
	bool band = false;
	Nodo *actual = new Nodo();
	actual = inicial;
	int n;

	cout<<"\nIngrese el elemento que desea buscar: ";
	cin>>n;

	if(inicial != NULL){
		do{
			if(actual->dato == n){
				band = true;
			}
			actual = actual->siguiente;
		}while(actual != inicial);
		cout<<"\n";
	}
	if(band == true){
		cout<<"\nElemento "<<n<<" fue encontrado\n"<<endl;
	}
	else{
		cout<<"\nElemento "<<n<<" no existe en la lista\n"<<endl;
	}
}

void eliminar(){
	bool band = false;
	Nodo *actual = new Nodo();
	Nodo *anterior = new Nodo();
	Nodo *ultimo;
	anterior = NULL;
	actual = inicial;
	int n;


	cout<<"\nIngrese el elemento que desea eliminar: "; cin>>n;

	if(inicial != NULL){
		do{
			if(actual->dato == n){
				band = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual != inicial);
		cout<<"\n";
	}

	if(band == true){
		ultimo = buscarUltimo();
		if(actual == inicial){
			inicial = inicial->siguiente;
			ultimo->siguiente = inicial;
		}
		else if(actual == ultimo){
			anterior->siguiente = inicial;
			ultimo = anterior;
		}
		else{
			anterior->siguiente = actual->siguiente;
		}
		cout<<"\nElemento "<<n<<" eliminado"<<endl;
	}
	else{
		cout<<"\nElemento "<<n<<" no existe en la lista"<<endl;
	}
}

Nodo *buscarUltimo(){
	Nodo *ultimo;
	ultimo = inicial;

	while(ultimo->siguiente != inicial){
		ultimo = ultimo->siguiente;
	}
	return ultimo;
}

Nodo *buscarLista(int clave){
	Nodo *anterior = NULL;

	if(clave <= inicial->dato){
		return anterior;
	}
	else{
		anterior = inicial;
		while((clave > anterior->siguiente->dato) && (anterior->siguiente != inicial)){
			anterior = anterior->siguiente;
		}
		return anterior;
	}
}
