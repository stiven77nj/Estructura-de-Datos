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
}*cima;

void insertar();
void desplegar();
void quitar();
int tope();

int main() {

  int opc;

  do{
    cout<<".:Menu Pila:."<<endl;
    cout<<"1.Insertar"<<endl;
    cout<<"2.Desplegar"<<endl;
    cout<<"3.Quitar"<<endl;
    cout<<"4.Toper"<<endl;
    cout<<"5.Salir"<<endl;
    cout<<"Opcion: "; cin>>opc;

    switch(opc){

      case 1:
        insertar();
        cout<<"\n";
        system("pause");
        break;

      case 2:
        cout<<"\nMostrando Elementos\n";
        desplegar();
        cout<<"\n";
        system("pause");
        break;

      case 3:
        quitar();
        cout<<"\n";
        system("pause");
        break;

      case 4:
        cout<<"\nLa cima de la pila es: "<<tope()<<endl;
        cout<<"\n";
        system("pause");
        break;

      case 5:
        cout<<"\n";
        system("pause");
    }
    system("cls");
  }while(opc != 5);
}

void insertar(){
  Nodo *nuevo = new Nodo();

  cout<<"\nIngrese un elemento: "; cin>>nuevo->dato;

  nuevo->sig = cima;
  cima = nuevo;

  cout<<"\nElemento ingresado"<<endl;
}

void desplegar(){
  Nodo *actual = new Nodo();
  actual = cima;

  if(cima != NULL){
    while(actual!=NULL){
      cout<<actual->dato<<" -> ";
      actual = actual->sig;
    }
  }
  else{
    cout<<"\nLa pila esta vacia\n"<<endl;
  }
}

void quitar(){
  Nodo *aux = cima;

  if(cima == NULL){
    cout<<"\nPila vacia\n";
  }
  else{
    cout<<"\nEliminado elemento de la cima\n\n";
    cima = aux->sig;
    delete aux;
  }
}

int tope(){
  return cima->dato;
}
