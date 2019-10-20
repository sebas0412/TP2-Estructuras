/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: schav
 *
 * Created on October 14, 2019, 3:41 PM
 */

#include <ctime>
#include <cstdlib>
#include "llist.h"
#include "bstree.h"

#define Seconds 10

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    clock_t inicio;
    clock_t inicio2;
    clock_t inicioArbol;
    clock_t inicioArbol2;
    double duracionAleatoria;
    int successfulRandom=0;
    int failedRandom = 0;
    double duracionLineal;
    int successfulOrdered=0;
    int failedOrdered = 0;
    double duracionArbolAleatoria;
    int successfulRandomTree=0;
    int failedRandomTree = 0;
    double duracionArbolLineal;
    int successfulOrderedTree=0;
    int failedOrderedTree = 0;
    
    llist<int> *lista = new llist<int>();
    llist<int> *lista2 = new llist<int>();
    srand (time(NULL));
    
    //Busquedas para lista aleatoria
    int numero;
    //int arr[400000];
    for(int i =0;i<1000000;i++){
        numero=rand() % 2000000 + 1;
      llnode<int> *nodo = new llnode<int>(numero);
      lista->listInsert(nodo);
    }
    
    inicio = clock();
	duracionAleatoria = 0;
	while(duracionAleatoria < 10){
    
        numero = rand() % 2000000+1;
        if(lista->listSearch(numero)!=nullptr){
            successfulRandom++;
        }else{
            failedRandom++;
        }
            
    
    duracionAleatoria = (clock() - inicio) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas aleatorias(Lista): "<<successfulRandom<<endl;
    cout<<"Fallidas aleatorias(Lista): "<<failedRandom<<endl;
    cout<<"Duracion(Lista): "<<duracionAleatoria<<endl;
    
    //Busquedas para lista ordenada
    int numero2;
    //int arr[400000];
    for(int i =0;i<1000000;i++){
        numero2=i;
      llnode<int> *nodo = new llnode<int>(numero2);
      lista2->listInsert(nodo);
    }
    
    inicio2 = clock();
	duracionLineal = 0;
	while(duracionLineal < 10){
    
        numero2 = rand() % 2000000+1;
        if(lista2->listSearch(numero2)!=nullptr){
            successfulOrdered++;
        }else{
            failedOrdered++;
        }
            
    
    duracionLineal = (clock() - inicio2) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas ordenadas(Lista): "<<successfulOrdered<<endl;
    cout<<"Fallidas ordenadas(Lista): "<<failedOrdered<<endl;
    cout<<"Duracion(Lista): "<<duracionAleatoria<<endl;
    
    //Busquedas para arbol aleatorio
    
    tree<int> *arbolRandom = new tree<int>();
    int numero3;
    for(int i =0;i<1000000;i++){
        numero3=rand() % 2000000 + 1;
      node<int> *nodo = new node<int>(numero3);
      arbolRandom->treeInsert(nodo);
    }
    
    inicioArbol = clock();
	duracionArbolAleatoria = 0;
	while(duracionArbolAleatoria < 10){
    
        numero3 = rand() % 2000000+1;
        if(arbolRandom->treeSearch(numero3)!=nullptr){
            successfulRandomTree++;
        }else{
            failedRandomTree++;
        }
            
    
    duracionArbolAleatoria = (clock() - inicioArbol) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas aleatorias(Arbol): "<<successfulRandomTree<<endl;
    cout<<"Fallidas aleatorias(Arbol): "<<failedRandomTree<<endl;
    cout<<"Duracion(Arbol): "<<duracionArbolAleatoria<<endl;
    
    //Busquedas para arbol ordenado
    tree<int> *arbolOrdenado = new tree<int>();
    int numero4;
    //int arr[400000];
    node<int> *nodo0 = new node<int>(0);
    arbolOrdenado->treeInsert(nodo0);
    node<int> *nodoRaiz = arbolOrdenado->getRoot();
    for(int i =1;i<1000000;i++){
        node<int> *nodo = new node<int>(i);
        arbolOrdenado->insertarDerecha(nodoRaiz,nodo);
        nodoRaiz=nodo;
    }
    
    inicioArbol2 = clock();
	duracionArbolLineal = 0;
	while(duracionArbolLineal < 10){
    
        numero4 = rand() % 2000000+1;
        if(arbolOrdenado->iterativeTreeSearch(numero4)!=nullptr){
            successfulOrderedTree++;
        }else{
            failedOrderedTree++;
        }
            
    
    duracionArbolLineal = (clock() - inicioArbol2) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas ordenadas(Lista): "<<successfulOrderedTree<<endl;
    cout<<"Fallidas ordenadas(Lista): "<<failedOrderedTree<<endl;
    cout<<"Duracion(Lista): "<<duracionArbolLineal<<endl;
     
    /*
     llist<int> *lista = new llist<int>();
    llnode<int> *nodo = new llnode<int>(5);
    llnode<int> *nodo2 = new llnode<int>(7);
    llnode<int> *nodo3 = new llnode<int>(8);
    llnode<int> *nodo4 = new llnode<int>(6);
    llnode<int> *nodo5 = new llnode<int>(2);
    llnode<int> *nodo6 = new llnode<int>(1);
    lista->listInsert(nodo);
    lista->listInsert(nodo2);
    lista->listInsert(nodo3);
    lista->listInsert(nodo4);
    lista->listInsert(nodo5);
    lista->listInsert(nodo6);
    cout<<lista->getNil()->next->key<<endl;
    cout<<lista->getNil()->next->next->key<<endl;
    cout<<lista->getNil()->next->next->next->key<<endl;
    cout<<lista->getNil()->next->next->next->next->key<<endl;
    cout<<lista->getNil()->next->next->next->next->next->key<<endl;
    cout<<lista->getNil()->next->next->next->next->next->next->key<<endl;
   */
    
    /*stack<int> pila;
    tree<int> *arbol = new tree<int>();
    node<int> *nodo = new node<int>(8);
    node<int> *nodo2 = new node<int>(5);
    node<int> *nodo3 = new node<int>(11);
    node<int> *nodo4 = new node<int>(12);
    node<int> *nodo5 = new node<int>(15);
    node<int> *nodo6 = new node<int>(1);
    node<int> *nodo7 = new node<int>(2);
    arbol->treeInsert(nodo3);
    arbol->treeInsert(nodo2);
    arbol->treeInsert(nodo);
    arbol->treeInsert(nodo4);
    arbol->treeInsert(nodo5);
    arbol->treeInsert(nodo6);
    arbol->treeInsert(nodo7);
    //arbol->~tree();
    arbol->inorderTreeWalk(nodo3,pila);
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    //cout<<arbol->treeSuccessor(nodo4)<<endl;
    arbol->treeDelete(nodo4);
    arbol->treeDelete(nodo);
    arbol->treeDelete(nodo5);
    arbol->inorderTreeWalk(nodo3,pila);
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
    pila.pop();
    cout<<pila.top()<<endl;
     * */
    return 0;
}

