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

#include <cstdlib>
#include "llist.h"
#include "bstree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*llist<int> *lista = new llist<int>();
    llnode<int> *nodo = new llnode<int>(5);
    llnode<int> *nodo2 = new llnode<int>(7);
    lista->listInsert(nodo);
    lista->listInsert(nodo2);
    cout<<lista->getNil()->next->key<<endl;
    cout<<lista->getNil()->next->next->key<<endl;
    */
    stack<int> pila;
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
    /*arbol->inorderTreeWalk(nodo3,pila);
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
    cout<<arbol->treeSuccessor(nodo7)<<endl;
    return 0;
}

