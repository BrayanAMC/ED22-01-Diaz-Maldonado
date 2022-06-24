//#ifndef NODO_H
//#define NODO_H
#pragma once
#include <iostream>
#include "Persona.hpp"
using namespace cv;
class Nodo{

private:
    Persona* persona;
    int id;
    int vistas;
    Nodo *next;

public:
    Nodo(Persona *p);
    int getId();
    int getVistas();//contara las veces que no se ha visto la persona para saber si ha desaparecido la persona del rango de la camara del video
    void setId(int id);
    void setVistas(int vistas);
    Nodo* getNext();
    void setNext(Nodo* n);
    Persona* getPersona();
};
