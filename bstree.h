#ifndef BINARY_SEARCH_Tree
#define BINARY_SEARCH_Tree
#include <iostream>
#include <stack>
using namespace std;
// Nodos del arbol:
template <typename T>
class node{
   public:
		// Esta clase es usada por otras clases.
		// Para mayor eficiencia, los atributos se hacen publicos.
		T key;
		node<T> *p, *left, *right;

		// Constructor por omision
		node(){
		};
		
		// Constructor por copia. Copia el nodo y sus hijos.
		node(const node<T> * obj, node<T> * padre){
		}

        // Inicializacion de datos miembro
		node(const T& k, node<T> *w = NULL, node<T> *y = NULL, node<T> *z = NULL):key(k), p(w), left(y), right(z){};
		
		~node(){
		}
};

// Arbol:
template <typename T>
class tree{
	public:
		tree(){
                    root = nullptr;
		};
			// Constructor. Crea un arbol vacio

		tree(const tree<T>& obj){
                    root=nullptr;
                    copiarArbol(obj->getRoot());
		};
			// Constructor copia

		~tree(){
                    borrarArbol(root);
		};
                
                void copiarArbol(node<T> * x){
                    node<T> *p = new node<T>(x->key);
                    treeInsert(p);
                    if(x->left!=nullptr){
                    copiarArbol(x->left);
                    }
                    if(x->right!=nullptr){
                    copiarArbol(x->right);
                    }
                }
                
                void borrarArbol(node<T>* x){
                    if(x!=nullptr){
                        if(x->left!=nullptr){
                            borrarArbol(x->left);
                        }
                        if(x->right!=nullptr){
                            borrarArbol(x->right);
                        }
                        delete x;
                    }
                }
			// Destructor (borra el arbol)
			
		void inorderTreeWalk(node<T>* x, stack<T> & pila){
                    if(x->left){
                        inorderTreeWalk(x->left,pila);
                    }
                    pila.push(x->key);
                    if(x->right){
                        inorderTreeWalk(x->right,pila);
                    }
                   
		};

            // Efectua un recorrido en orden del sub‡rbol cuya raiz es apuntada
            // por x, guardando en cada visita la llave de cada nodo en la pila.
            // Es decir, cada vez que se llega a un nodo se hace
            // pila.push(x->key). Si se hace correctamente, al finalizar el 
            // metodo la pila debe contener las llaves de los nodos del 
            // subarbol ordenadas de mayor a menor.
			
		
		node<T>* treeSearch(const T& k){
                    recSearch(k,root);
		};
                
                node<T>* recSearch(const T& k,node<T> *x){
                    node<T> *ind = x;
                    if(!x || k==ind->key){
                        return ind;
                    }
                    if(k<ind->key){
                        ind = ind->left;
                        recSearch(k,ind);
                    } else {
                        ind = ind->right;
                        recSearch(k,ind);
                    }
                    
                }
			// Busca la llave recursivamente; si la encuentra, devuelve un 
            // apuntador al nodo que la contiene, sino devuelve NULL

		node<T>* iterativeTreeSearch(const T& k){
                    node<T> *ind = root;
                    while(ind&&(ind->key!=k)){
                        if(k<ind->key){
                            
                                ind = ind->left;
                            
                                
                        } else {
                            
                            ind = ind->right;
                            
                        }
                        
                    }
                    return ind;
		};
			// Lo mismo que en el anterior pero usando un procedimiento 
			// iterativo
			
		node<T>* treeMinimum(){
                    node<T> *ind = root;
                    while(ind->left!=nullptr){
                        ind=ind->left;
                    }
                    return ind;
		};
			// Devuelve el nodo que tiene la llave menor.
            // Si el arbol est‡ vacio devuelve NULL.

		node<T>* treeMaximum(){
                    node<T> *ind = root;
                    while(ind->right!=nullptr){
                        ind=ind->right;
                    }
                    return ind;
		};
			// Devuelve el nodo que tiene la llave mayor.
            // Si el arbol esta vacio devuelve NULL.

		node<T>* treeSuccessor(const node<T>* x){
                    if(x->right!=nullptr){
                        return minizq(x->right);
                    }else if(x->p->left!=nullptr){
                        return x->p;
                    } else {
                        return x->p->p;
                    }
		};
                
                node<T>* minizq(node<T>* x){
                    node<T> *ind = x;
                    while(ind->left!=nullptr){
                            ind=ind->left;
                        }
                    return ind;
                }
			// Devuelve el nodo cuya llave es la que le sigue a la
            // del nodo x. Si no existe tal nodo devuelve NULL.

		void treeInsert(node<T>* z){
                    node<T> *a = nullptr;
                    node<T> *p = root;
                    while(p!=nullptr){
                        a = p;
                        if(z->key<=p->key){
                            p=p->left;
                        } else if(z->key>=p->key){
                            p=p->right;
                        }
                    }
                    if(a==nullptr){
                       root =z;
                    } else if(z->key<=a->key){
                        z->p = a;
                        a->left = z;
                    } else {
                        z->p = a;
                        a->right = z;
                    }
                    
		};
                
                void insertarDerecha(node<T>* z,node<T> * p){
                    p->p = z;
                    z->right = p;
                }
		// Inserta el nodo z en la posicion que le corresponde en el arbol.
			
		node<T>* treeDelete(node<T>* z){
                    node<T> *p = treeSearch(z->key);
                    if(p!=nullptr){
                        if(p->left==nullptr&&p->right==nullptr){
                            if(p->p->left==z){
                                p->p->left=nullptr;
                                
                            } else {
                                p->p->right=nullptr;
                                
                            }
                        } else if((p->left!=nullptr&&p->right==nullptr)||(p->left==nullptr&&p->right!=nullptr)){
                            if(p->p->left==z){
                                p->p->left=p->left;
                            } else {
                                p->p->right=p->right;
                                
                            }
                        } else if(p->left!=nullptr&&p->right!=nullptr){
                            node<T> *s = treeSuccessor(z);
                            p->key=s->key;
                            if(s->left==nullptr&&s->right==nullptr){
                                if(s->p->left==s){
                                    s->p->left=nullptr;
                                } else {
                                    s->p->right=nullptr;
                                }
                            } else if(s->right!=nullptr){
                                s->p->right=s->right;
                            }
                        }
                            
                    }
		}
             
			// Saca del arbol la llave contenida en el nodo apuntado por z.
			// Devuelve la direccion del nodo eliminado para que se pueda 
			// disponer de ella.
	
		node<T> * getRoot() const{
			return this->root;
		};
		// Devuelve la raiz del arbol. (Para efectos de revisi—n de la tarea).
	
	private:
		node<T> *root;	// root of the Tree

};
#endif	// BINARY_SEARCH_Tree
