#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

struct Nodo{
	Nodo *derecho;
	char dato;
	Nodo *izquierdo;
};
void menu();
Nodo *nDinamico(char dato);
void inNodo(Nodo *&,char);
void imprimirDatos(Nodo *,int);
char caracterRepetido(char [],char&,int);

int main(){
	Nodo *arbol = NULL;
	char opcion;
	char *caracter;
	char auxCaracter;
	int numDatos;
	
	do{
		int contador=0;
		int contador2=0;
		menu();
		cin>>opcion;
		fflush(stdin);
		switch(opcion){
			case '1':
				cout<<"\nCuantos caracteres desea ingresar? "; cin>>numDatos;
				caracter = new char[numDatos];
				for(int i=0; i<numDatos; i++){
					cout<<"\nIngresar caracter "<<i+1<<": "; cin>>caracter[i];
					auxCaracter=caracter[i];
					contador2+=1;
					caracter[i]=caracterRepetido(caracter,auxCaracter,contador2);
					auxCaracter=caracter[i];
					nDinamico(auxCaracter);
					inNodo(arbol,auxCaracter);
				}
				delete[] caracter;
				break;
			case '2':
				cout<<"\n2.Mostrar datos."<<endl;
				imprimirDatos(arbol,contador);
				cout<<endl;
				break;
			case '3':
				cout<<"\nSalio del programa..."<<endl;
				break;
			default:
				cout<<"\nOpcion invalida..."<<endl;
				break;
		}
		cout<<"\nPresione una tecla para continuar..."<<endl;
		getch();
		system("cls");
	}while(opcion !='3');
	return 0;
}

void menu(){
	cout<<"\tMENU"<<endl
	    <<"1.Ingresar datos tipo caracter."<<endl
	    <<"2.Mostrar datos."<<endl
	    <<"3.Salir."<<endl
	    <<"Ingresar el numero de opcion que desea ejecutar: ";
}

char caracterRepetido(char caracter[],char &auxCaracter,int contador){
	
	if(contador>1){
		for(int i=0; i<contador-1;i++){
			if(caracter[i]==auxCaracter){
				cout<<"\nEl numero "<<caracter[i]<<" es igual al caracter "<<auxCaracter<<endl
				    <<"Ingresar un caracter diferente: "; cin>>auxCaracter;
				    caracterRepetido(caracter,auxCaracter,contador);
			}
		}
	}else{
		return auxCaracter;
	}
	return auxCaracter;
}

Nodo *nDinamico(char dato){
    Nodo *nNodo = new Nodo();
    //Los nodos hijos estaran vacion en el nuevo nodo
	nNodo->dato = dato;//Nodo raiz
	nNodo->derecho = NULL;//Nodo hijo
	nNodo->izquierdo = NULL;//Nodo hijo
	
	return nNodo;//Retornando el nuevo nodo con su nuevo valor
}

void inNodo(Nodo *&arbol,char dato){
	
	if(arbol==NULL){
		Nodo *nNodo = nDinamico(dato);
		arbol = nNodo;
	}else{
		if(dato < arbol->dato){
			inNodo(arbol->izquierdo,dato);
		}else{
			inNodo(arbol->derecho,dato);
		}
	}
}

void imprimirDatos(Nodo *arbol,int contador){
	
	if(arbol == NULL){
		return;
	}else{
		imprimirDatos(arbol->derecho,contador+1);
		for(int i=0; i<contador; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		imprimirDatos(arbol->izquierdo,contador+1);
	}
	
}
