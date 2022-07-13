#include <iostream>
#include "Nodo.hpp"
#include "Persona.hpp"

Nodo::Nodo(Persona *p){
    vistas=0;
    this->persona = p;

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
void Nodo::setNext(Nodo* n){
    this->next = n;
}
Nodo* Nodo::getNext(){
    return next;
}
Persona* Nodo::getPersona(){
    return persona;
}
