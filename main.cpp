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
#include "rbtree.h"
#include "hasht.h"

#define Seconds 10
#define SIZE 1000000

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //hasht<int> tabla = hasht<int>(SIZE);
    //tabla.insert(8);
    //tabla.search(444);
    /*
    //Arbol Rojinegro
    //Duracion aleatoria
    rbtree<int> *arbolrn = new rbtree<int>();
    
    clock_t inicio;
    double duracionAleatoria;
    int successfulRandom=0;
    int failedRandom = 0;
    srand (time(NULL));
    
    int numero;
    for(int i =0;i<1000000;i++){
        numero=rand() % 2000000 + 1;
      rbnode<int> *nodorb = new rbnode<int>(numero);
      arbolrn->treeInsert(nodorb);
    }
    
     inicio = clock();
	duracionAleatoria = 0;
	while(duracionAleatoria < 10){
        numero = rand() % 2000000+1;
        if(arbolrn->treeSearch(numero)!=nullptr){
            successfulRandom++;
        }else{
            failedRandom++;
        }
    duracionAleatoria = (clock() - inicio) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas aleatorias(ArbolRB): "<<successfulRandom<<endl;
    cout<<"Fallidas aleatorias(ArbolRB): "<<failedRandom<<endl;
    cout<<"Duracion(ArbolRB): "<<duracionAleatoria<<endl;
  
    //Duracion lineal
    
    rbtree<int> *arbolrn2 = new rbtree<int>();
    
    clock_t inicio2;
    double duracionLineal;
    int successfulOrdered=0;
    int failedOrdered = 0;
    srand (time(NULL));
    
    int numero2;
    for(int i =0;i<1000000;i++){
        numero2=i;
      rbnode<int> *nodorb = new rbnode<int>(numero2);
      arbolrn2->treeInsert(nodorb);
    }
    
     inicio2 = clock();
	duracionLineal = 0;
	while(duracionLineal < 10){
        numero2 = rand() % 2000000+1;
        if(arbolrn2->iterativeTreeSearch(numero2)!=nullptr){
            successfulOrdered++;
        }else{
            failedOrdered++;
        }
    duracionLineal = (clock() - inicio2) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas lineal(ArbolRB): "<<successfulOrdered<<endl;
    cout<<"Fallidas lineal(ArbolRB): "<<failedOrdered<<endl;
    cout<<"Duracion(ArbolRB): "<<duracionLineal<<endl;
    */
    //Tabla de hash
    //Duracion aleatoria
    hasht<int> tabla = hasht<int>(SIZE);
    
    clock_t inicio3;
    double duracionTablaAleatoria;
    int successfulRandomTable=0;
    int failedRandomTable = 0;
    srand (time(NULL));
    
    int numero3;
    for(int i =0;i<1000000;i++){
        numero3=rand() % 2000000 + 1;
      tabla.insert(numero3);
    }
    
     inicio3 = clock();
	duracionTablaAleatoria = 0;
	while(duracionTablaAleatoria < 10){
        numero3 = rand() % 2000000+1;
        if(tabla.search(numero3)!=nullptr){
            successfulRandomTable++;
        }else{
            failedRandomTable++;
        }
    duracionTablaAleatoria = (clock() - inicio3) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas aleatorias(Tabla): "<<successfulRandomTable<<endl;
    cout<<"Fallidas aleatorias(Tabla): "<<failedRandomTable<<endl;
    cout<<"Duracion(Tabla): "<<duracionTablaAleatoria<<endl;

    //Duracion lineal
    
    hasht<int> tabla2 = hasht<int>(SIZE);
    
    clock_t inicio4;
    double duracionTablaLineal;
    int successfulOrderedTable=0;
    int failedOrderedTable = 0;
    srand (time(NULL));
    
    int numero4;
    for(int i =0;i<1000000;i++){
        numero4=i;
      tabla.insert(numero4);
    }
    
     inicio4 = clock();
	duracionTablaLineal = 0;
	while(duracionTablaLineal < 10){
        numero4 = rand() % 2000000+1;
        if(tabla.search(numero4)!=nullptr){
            successfulOrderedTable++;
        }else{
            failedOrderedTable++;
        }
    duracionTablaLineal = (clock() - inicio4) / (double) CLOCKS_PER_SEC;
        }
    cout<<"Exitosas lineal(Tabla): "<<successfulOrderedTable<<endl;
    cout<<"Fallidas lineal(Tabla): "<<failedOrderedTable<<endl;
    cout<<"Duracion(Tabla): "<<duracionTablaLineal<<endl;
    
    /*
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
    */
    
    return 0;
}

