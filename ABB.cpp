#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

using namespace std;

struct Nodo{
  int dato;
  Nodo *der;
  Nodo *izq;
  Nodo *padre;
};

Nodo *crearNodo(int, Nodo *);
void agregar(Nodo *&, int, Nodo *);
void mostrar(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruir(Nodo *);

Nodo *arbol = NULL;
int main(){
  int opc, dato, cont = 0;

  do{
    cout<<".:ABB:."<<endl;
    cout<<"1.Agregar"<<endl;
    cout<<"2.Mostrar"<<endl;
    cout<<"3.Buscar"<<endl;
    cout<<"4.Recorrido PreOrden"<<endl;
    cout<<"5.Recorrido InOrden"<<endl;
    cout<<"6.Recorrido PostOrden"<<endl;
    cout<<"7.Eliminar"<<endl;
    cout<<"8.Salir"<<endl;
    cout<<"Opcion: "; cin>>opc;

    switch(opc){
      case 1:
        cout<<"\nDigite un elemento: "; cin>>dato;
        agregar(arbol,dato,NULL);
        cout<<"\n";
        system("pause");
        break;

      case 2:
      cout<<"\nMostrando Arbol\n";
        mostrar(arbol,cont);
        cout<<"\n";
        system("pause");
        break;

      case 3:
        cout<<"\nIngrese elemento que desea buscar: "; cin>>dato;
        if(busqueda(arbol,dato) == true){
          cout<<"\nElemento encontrado\n";
        }
        else{
          cout<<"\nElemento no encontrado\n";
        }
        cout<<"\n";
        system("pause");
        break;

      case 4:
        cout<<"\nMostrando arbol en PreOrden\n";
        preOrden(arbol);
        cout<<"\n";
        system("pause");
        break;

      case 5:
        cout<<"\nMostrando arbol en InOrden\n";
        inOrden(arbol);
        cout<<"\n";
        system("pause");
        break;

      case 6:
        cout<<"\nMostrando arbol en PostOrden\n";
        postOrden(arbol);
        cout<<"\n";
        system("pause");
        break;

      case 7:
        cout<<"\nDigite el elemento que desea eliminar: "; cin>>dato;
        eliminar(arbol,dato);
        cout<<"\n";
        system("pause");
        break;

      case 8:
        cout<<"\n";
        system("pause");
        break;

    }
    system("cls");
  }while(opc != 8);
}

Nodo *crearNodo(int n, Nodo *padre){
  Nodo *nuevo = new Nodo();

  nuevo->dato = n;
  nuevo->der = NULL;
  nuevo->izq = NULL;
  nuevo->padre = padre;

  return nuevo;
}

void agregar(Nodo *&arbol, int n, Nodo *padre){
  if(arbol == NULL){
    Nodo *nuevo = crearNodo(n,padre);
    arbol = nuevo;
  }
  else{
    int valorRaiz = arbol->dato;
    if(n < valorRaiz){
      agregar(arbol->izq,n,arbol);
    }
    else{
      agregar(arbol->der,n,arbol);
    }
  }
}

void mostrar(Nodo *arbol, int cont){
  if(arbol == NULL){
    return;
  }
  else{
    mostrar(arbol->der,cont+1);
    for(int i=0;i<cont;i++){
      cout<<"   ";
    }
    cout<<arbol->dato<<endl;
    mostrar(arbol->izq,cont+1);
  }
}

bool busqueda(Nodo *arbol, int n){
  if(arbol == NULL){
    return false;
  }
  else if(arbol->dato == n){
    return true;
  }
  else if(n < arbol->dato){
    return busqueda(arbol->izq,n);
  }
  else{
    return busqueda(arbol->der,n);
  }
}

void preOrden(Nodo *arbol){
  if(arbol == NULL){
    return;
  }
  else{
    cout<<arbol->dato<<" -> ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
  }
}

void inOrden(Nodo *arbol){
  if(arbol == NULL){
    return;
  }
  else{
    inOrden(arbol->izq);
    cout<<arbol->dato<<" -> ";
    inOrden(arbol->der);
  }
}

void postOrden(Nodo *arbol){
  if(arbol == NULL){
    return;
  }
  else{
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout<<arbol->dato<<" -> ";
  }
}

//Funcion para eliminar un nodo
void eliminar(Nodo *arbol, int n){
  if(arbol == NULL){
    return;
  }
  else if(n < arbol->dato){ // -> Si el valor es menor buscamos por la izquierda
    eliminar(arbol->izq,n);
  }
  else if(n > arbol->dato){ // -> Si el valor es mayor buscamos por la derecha
    eliminar(arbol->der,n);
  }
  else{
    eliminarNodo(arbol);
  }
}

//Funcion para determinar el nodo mas izquierdo posible
Nodo *minimo(Nodo *arbol){
  if(arbol == NULL){ // -> Si el arbol esta vacio, retornamos NULL
    return NULL;
  }
  if(arbol->izq){ // -> Si tiene hijo izquierdo, buscamos la parte mas izquierda posible
    return minimo(arbol->izq);
  }
  else{ // -> Si no tiene hijo izquierdo, retornamos el mismo nodo
    return arbol;
  }
}

//Funcion para reemplazar los nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
  if(arbol->padre){
    // arbol->padre hay que asignarle su nuevo hijo
    if(arbol->dato == arbol->padre->izq->dato){
      arbol->padre->izq = nuevoNodo;
    }
    else if(arbol->dato == arbol->padre->der->dato){
      arbol->padre->der = nuevoNodo;
    }
  }
  if(nuevoNodo){
    nuevoNodo = arbol->padre; // -> Asignamos su nuevo padre
  }
}

//Funcion para destruir un nodo
void destruir(Nodo *nodo){
  nodo->izq = NULL;
  nodo->der = NULL;
  delete nodo;
}

//Eliminar el nodo encontrado
void eliminarNodo(Nodo *eliminar){
  if(eliminar->izq && eliminar->der){ // -> Si tiene hijos
    Nodo *menor = minimo(eliminar->der);
    eliminar->dato = menor->dato;
    eliminarNodo(menor);
  }
  else if(eliminar->izq){ // -> Si tiene hijo izquierdo
    reemplazar(eliminar,eliminar->izq);
    destruir(eliminar);
  }
  else if(eliminar->der){ // -> Si Tiene un hijo derecho
    reemplazar(eliminar,eliminar->der);
    destruir(eliminar);
  }
  else{ // -> No tiene hijos
    reemplazar(eliminar,NULL);
    destruir(eliminar);
  }
}
