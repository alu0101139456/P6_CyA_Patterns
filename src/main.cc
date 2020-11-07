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
// #include "set.h"
// #include "alfabeto.h"
#include "pattern_search.h"


void help();



int main(int argc, char *argv[]) {

  if ( argc == 3 ) {
    PatternSearch( argv[1], argv[2],"output.txt" );
  }
  else if ( argc == 4) {
    PatternSearch( argv[1], argv[2], argv[3]);
  }
  else {
    help();
  }
    
}



void help() {
  system("clear");
  std::cout << "\nHELP";
  std::cout << "\nDESCRIPTION     \n";
  std::cout << "fibonacci_words [FILE INPUT] [FILE_OUTPUT]     \n";
  std::cout << "fibonacci_words [FILE INPUT] \n";
  std::cout << "Default: output.txt";

  std::cout << "\n";
}
