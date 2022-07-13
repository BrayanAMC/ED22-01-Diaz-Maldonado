#include <iostream>
#include "LinkedList.hpp"
#include "Nodo.hpp"
using std::endl;
using std::cout;
LinkedList::LinkedList(){
    first = NULL;
    size = 0;
}
void LinkedList::insertarPrimer(Persona* p){
    Nodo* nodo = new Nodo(p);//creamos un nodo con la persona
    nodo->setNext(first);
    first = nodo;
    size++;
    cout << "(se ha ingresado un nodo a la linked list)" << endl;
    
          
}
Nodo* LinkedList::getFirst(){//se obtiene el primer elemento de la lista
    return first;
}
int LinkedList::getSize(){//se obtiene el tamaño de la lista
    return size;
}
void LinkedList::eliminarNodo(int id){
    //recorrer la lista enlazada comparando id
    //si concuerdan, eliminar el nodo con nodo aux
    
}