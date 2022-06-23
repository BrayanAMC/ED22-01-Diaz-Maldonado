#program once
#include <iostream>
#include "Nodo.hpp"

class LinkedList{
private:
    Nodo* first;
    int size;

public:
    LinkedList();
    void insertarPrimer(Persona* persona);
    Nodo* getFirst();
    int getSize();
    void eliminarNodo(int id);//se eliminara el nodo con el id suministrado

}


