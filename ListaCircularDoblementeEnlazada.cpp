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
}*inicial,*ultimo;

Nodo *buscarLista(int);
void agregar();
void mostrar();
void buscar();
void eliminar();
void ordenar();

int main(){
	int opc;

	do{
		cout<<".:Lista Circular Doblemente Enlazada:."<<endl;
		cout<<"1.Ingresar"<<endl;
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

Nodo *buscarLista(int clave){
	Nodo *anterior;

	anterior = NULL;
	if(clave <= inicial->dato){
		return anterior;
	}
	else{
		anterior = inicial;
		while(clave > anterior->siguiente->dato && anterior->siguiente != inicial){
			anterior = anterior->siguiente;
		}
		return anterior;
	}
}

void agregar(){
	Nodo *nuevo, *anterior;
	nuevo = new Nodo();
	bool band = false;

	cout<<"\nDigite el elemento que desea ingresar a la lista: "; cin>>nuevo->dato;

	if(inicial != NULL){
		Nodo *aux;
        aux = inicial;
        while(aux != NULL){
            if(aux->dato == nuevo->dato){
            band = true;
            aux = NULL;
            }
            else{
                aux = aux->siguiente;
            }
            if(aux == inicial){
                aux = NULL;
            }
        }
    }

    if(band == true){
        cout<<"\nEl numero "<<nuevo->dato<<" ya se encuentra en la lista"<<endl;
    }
	else{
		if(inicial == NULL){
            inicial = nuevo;
            ultimo = nuevo;
            inicial->siguiente = inicial;
            inicial->anterior = ultimo;
            cout<<"\nElemento fue ingresado a lista\n";
    }
        else{
            ultimo->siguiente=nuevo;
            nuevo->anterior=ultimo;
            nuevo->siguiente=inicial;
            ultimo=nuevo;
            inicial->anterior=ultimo;
            cout<<"\nElemento fue ingresado a lista\n";
        }
	}
}

void eliminar(){
    Nodo *actual = new Nodo();
	actual = inicial;
	Nodo *anterior = new Nodo();
	anterior = NULL;
	Nodo *ultimo = new Nodo();
	ultimo = inicial->anterior;
	bool encontrado = false;
	int n;
	cout<<"\nIngrese el elemento que desea eliminar: ";
	cin>>n;
	if(inicial!=NULL){
		do{

			if(actual->dato==n){
				if(actual==inicial){
					inicial = inicial->siguiente;
					inicial->anterior = ultimo;
					ultimo->siguiente = inicial;
				}else if(actual==ultimo){
					ultimo = anterior;
					ultimo->siguiente = inicial;
					inicial->anterior = ultimo;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = anterior;
				}

				cout<<"\nElemento Eliminado\n";
				encontrado = true;
			}

			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=inicial && encontrado != true);

		if(!encontrado){
			cout<<"\nElemento no Encontrado\n";
		}

	}else{
		cout<<"\nLa lista se Encuentra Vacia\n";
	}
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

void mostrar(){
	int resp;
	Nodo *apunt;

	if(inicial == NULL){
		cout<<"\nLa lista esta vacia\n";
	}
	else{
		ordenar();
		cout<<"\n1.Desplegar la lista en sentido horario"<<endl;
		cout<<"2.Desplegar la lista en sentido anti-horario"<<endl;
		cout<<"Opcion: "; cin>>resp;
	}
	if(resp == 1){
		cout<<"\nSentido Horario\n";
		apunt = inicial;
		do{
			cout<<apunt->dato<<" -> ";
			apunt = apunt->siguiente;
		}while(apunt != inicial);
	}
	else if(resp == 2){
		cout<<"\nSentido Anti-Horario\n";
		apunt = inicial->anterior;
		do{
			cout<<apunt->dato<<" -> ";
			apunt = apunt->anterior;
		}while(apunt != inicial->anterior);
	}
	cout<<"\n";
}

void ordenar(){
	Nodo *aux, *aux2;
	int temp;

	aux = inicial;
	while(aux->siguiente != inicial){
		aux2 = aux->siguiente;
		while(aux2 != inicial){
			if(aux2->dato < aux->dato){
				temp = aux->dato;
				aux->dato = aux2->dato;
				aux2->dato = temp;
			}
			aux2 = aux2->siguiente;
		}
		aux = aux->siguiente;
	}
}
