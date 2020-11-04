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
#include "alfabeto.h"


int main() {

  Alphabet alfabeto;

  std::cout << alfabeto.PrintAlphabet();
  
  alfabeto.InsertSymbol('A');
    
  std::cout << alfabeto.PrintAlphabet();
}