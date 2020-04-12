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
}*inicio, *final;

void agregar();
void mostrar();
void quitar();

int main(){
  int opc;

  do{
    cout<<".:Menu Cola:."<<endl;
    cout<<"1.Insertar"<<endl;
    cout<<"2.Mostrar"<<endl;
    cout<<"3.Quitar"<<endl;
    cout<<"4.Salir"<<endl;
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
        quitar();
        cout<<"\n";
        system("pause");
        break;

      case 4:
        cout<<"\n";
        system("pause");
        break;
    }
    system("cls");
  }while(opc != 4);
}

void agregar(){
  Nodo *nuevo = new Nodo();

  cout<<"\nDigite el elemento que desea agregar: "; cin>>nuevo->dato;

  if(inicio == NULL){
    inicio = nuevo;
    inicio->sig = NULL;
    final = inicio;
  }
  else{
    final->sig = nuevo;
    nuevo->sig = NULL;
    final = nuevo;
  }
}

void mostrar(){
  Nodo *actual = new Nodo();
  actual = inicio;

  if(inicio != NULL){
    do{
      cout<<actual->dato<<" -> ";
      actual = actual->sig;
    }while(actual != NULL);
  }
  else{
    cout<<"\nLa cola esta vacia\n"<<endl;
  }
}

void quitar(){
  Nodo *aux = inicio;

  if(inicio != NULL){
    cout<<"\nEliminando Cabeza de la Cola\n";
    inicio = aux->sig;
    delete aux;
  }
  else{
    cout<<"\nCola vacia\n"<<endl;
  }
}
