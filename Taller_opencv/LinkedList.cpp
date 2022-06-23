#include <iostream>
#include "LinkedList.hpp"
#include "Nodo.hpp"

LinkedList::LinkedList(){
    first = NULL;
    size = 0;
}
void LinkedList::insertarPrimer(Persona* p){
    Nodo nodo = new Nodo(p);//creamos un nodo con la persona
    nodo->setNext(first);
    first = nodo;
    size++;
}
Nodo LinkedList::getFirst(){
    return first;
}
int LinkedList::getSize(){
    return size;
}
void LinkedList::eliminarNodo(int id){
    //recorrer la lista enlazada comparando id
    //si concuerdan, eliminar el nodo con nodo aux
}