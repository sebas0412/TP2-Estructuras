#ifndef RED_BLACK_rbtree
#define RED_BLACK_rbtree
#include <stack>

enum colors {RED, BLACK};

// Nodos del arbol:
template <typename T>
class rbnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia se hacen los atributos publicos.
		T key;
		rbnode<T> *p, *left, *right;
		enum colors color;

		// Constructor por omision.
		rbnode(){
		};
		
		// Constructor por copia del nodo.
		rbnode(const rbnode<T> * obj, const rbnode<T> * objNil, rbnode<T> * parent, rbnode<T> * nilPtr){
		}

      // Inicializacion de datos miembro.
		rbnode (const T& k, rbnode<T> *w = NULL, rbnode<T> *y = NULL, 
				 rbnode<T> *z = NULL, enum colors c = RED):
					key(k), p(w), left(y), right(z), color(c)
		{};
		
		~rbnode(){

		}
};

// Arbol:
template <typename T>
class rbtree{
	public:
		rbtree(){
                    this->root= new rbnode<T>(NULL, NULL, NULL, NULL, BLACK);
                    this->nil = root;
		};
			// Constructor (crea un arbol vacio)

		rbtree(const rbtree<T>& obj){ 
		};
			// Constructor copia

		~rbtree(){
                    borrarArbol(root);
                    delete nil;
		};
                
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
			
		void inorderTreeWalk(rbnode<T>* x, stack<T> & pila){
                    if(x->left){
                        inorderTreeWalk(x->left,pila);
                    }
                    pila.push(x->key);
                    pila.push(x->color);
                    if(x->right){
                        inorderTreeWalk(x->right,pila);
                    }
		};
            // Efectua un recorrido en orden del subarbol cuya ra’z es apuntada
            // por x. En cada visita apila la llave de cada nodo y su color.
            // Es decir, cada vez que se llega a un nodo se ejecutan las 
            // instrucciones pila.push(x->key); y luego pila.push(colorDeX).
            // Para efectos de la tarea, si el color del nodo es rojo, 
            // ponga en la pila un 0, y si es negro, ponga un 1.
            // Si se hace correctamente, al finalizar el mŽtodo la pila deber’a 
            // contener las llaves de los nodos del sub‡rbol (y su color) 
            // ordenadas de mayor a menor.
		
		rbnode<T>* treeSearch(const T& k){
                    recSearch(k,root);
		};
                
                rbnode<T>* recSearch(const T& k,rbnode<T> *x){
                    rbnode<T> *ind = x;
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
                
                
			// Busca la llave recursivamente, si la encuentra devuelve un 
            // puntero al nodo que la contiene, sino devuelve NULL.

		rbnode<T>* iterativeTreeSearch(const T& k){
                    rbnode<T> *ind = root;
                    while(ind&&(ind->key!=k)){
                        if(k<ind->key){
                                ind = ind->left;
                        } else {
                            ind = ind->right;
                        }
                    }
                    return ind;
		};
			// Igual que en el anterior pero usa un procedimiento iterativo.
			
		rbnode<T>* treeMinimum(){
                    rbnode<T> *ind = root;
                    while(ind->left!=nullptr){
                        ind=ind->left;
                    }
                    return ind;
		};
			// Devuelve el nodo con la llave menor.
            // Si el arbol esta vacio devuelve NULL.

		rbnode<T>* treeMaximum(){
                    rbnode<T> *ind = root;
                    while(ind->right!=nullptr){
                        ind=ind->right;
                    }
                    return ind;
		};
			// Devuelve el nodo con la llave mayor.
            // Si el arbol esta vacio devuelve NULL.

		rbnode<T>* treeSuccessor(const rbnode<T>* x){
                    if(x->right!=nullptr){
                        return minizq(x->right);
                    }else if(x->p->left!=nullptr){
                        return x->p;
                    } else {
                        return x->p->p;
                    }
		};
                
                rbnode<T>* minizq(rbnode<T>* x){
                    rbnode<T> *ind = x;
                    while(ind->left!=nullptr){
                            ind=ind->left;
                        }
                    return ind;
                }
			// Devuelve el nodo cuya llave es la siguiente mas grande que 
            // la del nodo x. Si no existe tal nodo devuelve NULL.

		void treeInsert(rbnode<T>* z){ //aux es y, actual es x.
                    rbnode<T> *a = nil;
                    rbnode<T> *p = root;
                    while(p!=nil){
                        a = p;
                        if(z->key<=p->key){
                            p=p->left;
                        } else if(z->key>=p->key){
                            p=p->right;
                        }
                    }
                    if(a==nil){
                        z->left=nil;
                        z->right=nil;
                        z->color=BLACK;
                        z->p = nil;
                        root =z;
                    } else if(z->key<=a->key){
                        z->p = a;
                        z->left=nil;
                        z->right=nil;
                        a->left = z;
                        rotacion(z);
                        
                    } else {
                        z->p = a;
                        z->left=nil;
                        z->right=nil;
                        a->right = z;
                        rotacion(z);
                    }
                    root->color=BLACK;
		};
			// Inserta el nodo z en la posicion que le corresponde en el arbol.
                
                void rotacion(rbnode<T> * x){
                    //rbnode<T> *p = x->p;
                    //rbnode<T> *g = x->p->p;
                    while(x->p!=nil&&x->p->color==RED){
                        if(x->p == x->p->p->left){
                            
                        if(tio(x)->color==RED){
                                x->p->p->color=RED;
                                x->p->p->left->color= BLACK;
                                x->p->p->right->color=BLACK;
                                x=x->p->p;
                            } else{
                            //Left left
                                if(x == x->p->right){
                                    x = x->p;
                                    leftRotation(x);
  				}
  				x->p->color = BLACK;
  				x->p->p->color = RED;
  				rightRotation(x->p->p);
                            }
                        } else {
                            if(tio(x)->color==RED){
                                x->p->p->color=RED;
                                x->p->p->left->color= BLACK;
                                x->p->p->right->color=BLACK;
                                x=x->p->p;
                            } else {
                                if(x == x->p->left){
  				x = x->p;
  				rightRotation(x);
  				}
  				x->p->color = BLACK;
  				x->p->p->color = RED;
  				leftRotation(x->p->p);
                            }
                        }
                    }
                    root->color=BLACK;
                }
                
                rbnode<T>* tio(rbnode<T> * x){
                    if(x->p==x->p->p->left){
                        return x->p->p->right;
                    } else {
                        return x->p->p->left;
                    }
                }
                
                void rightRotation(rbnode <T> * x){
  			rbnode<T> * y = x->left;
  			x->left = y->right;
  			if(y->right != nil){
                            y->right->p = x;
                        }
  			y->p = x->p;
  			if(x->p == nil){
                            root = y;
                        } else if( x == x->p->right){
                            x->p->right = y;
                        }else{
                            x->p->left = y;
                        }
  			y->right = x;
  			x->p = y;
  		}
                
                void leftRotation(rbnode <T> * x){
  			rbnode<T> * y = x->right;
  			x->right = y->left;
  			if(y->left != nil){
                            y->left->p = x;
                        }
  			y->p = x->p;
  			if(x->p == nil){
                            root = y;
                        }else if(x == x->p->left){
                            x->p->left = y;
                        }else{
                            x->p->right = y;
                        }
  			y->left = x;
  			x->p = y;
  		}
			
		node<T>* treeDelete(node<T>* z){
		};
			// Saca del arbol la llave contenida en el nodo apuntado por z.
			// Devuelve la direccion del nodo eliminado para que se pueda 
			// disponer de el.
	
		rbnode<T> * getRoot() const{
			return this->root;
		};
		
		// Devuelve la raiz del arbol. (Para efectos de revision de la tarea).
		
		rbnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve T.nil. (Para efectos de revision de la tarea).
			
		private:
	
		rbnode<T> *root;	// raiz del arbol
		rbnode<T> *nil;	    // nodo nil (hoja) del arbol

};

#endif	// RED_BLACK_rbtree
