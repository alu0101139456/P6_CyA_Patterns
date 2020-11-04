/*
 * Autor: Ángel Julián Bolaño Campos
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Editor: Visual Studio Code
 * Estilo Google C++ Style Guide
 * Práctica 6: Busqueda de patrones
 * 
*/

#include <iostream>
#include "set.h"


int main() {
  Set test;

for (size_t i = 1; i < 100; i++) {
    if ( !(i%2) ) {
      test.Insert(i);
    }
  }

  std::vector<int> aux = test.toVectorInt();

  for (size_t i = 0; i < aux.size(); i++) {
    std::cout << aux[i] << " ";
  }

  std::cout << test.Find(2);


    
    
}