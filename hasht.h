#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <iostream>
#include <vector>

template <typename T>

class hasht{
	public:
		hasht(int nEntradas){
                    //tabla = new list<int>[numEntradas]; 
                    tabla.resize(nEntradas);
                    this->numEntradas = nEntradas;
		};
			// Constructor que especifica el numero de cubetas (entradas) 
			// en la tabla
			
		hash(const hash<T>& obj){ 
		};
			// Constructor copia

		~hasht(){
                    //delete tabla;
		};
			// Destructor (borra la tabla)

		T* search(const T& item){
                        int indice = hash(item);
			auto p = tabla[indice].begin();
			while(p !=  tabla[indice].end() && *p != item){
				++p;
			}
                        T* q;
                        if(*p==item){
                            q=&(*p);
                        } else {
                            q=nullptr;
                        }
			return q;
		};
			// Retorna un puntero a la llave o NULL si no se encuentra

		void insert(const T& item){
                    int i = hash(item);
                    tabla[i].push_back(item);
		};
			// Inserta el elemento en la tabla
                
                int hash(int x){
                    return (x % numEntradas); 
                }
	private:
		int numEntradas;
			// Nœmero de entradas en la tabla
                std::vector<std::list<T> > tabla;
			// La tabla es un vector de listas de STL
};
#endif
