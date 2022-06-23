#include <iostream>
#include "Nodo.hpp"


Nodo::Nodo(Persona p){
    vistas=0;

}
int Nodo::getVistas(){
    return vistas;
}
int Nodo::getId(){
    return id;
}
void Nodo::setId(int id){
    this->id = id;

}
void Nodo::setVistas(int vistas){
    this->vistas = vistas;
}
