/*
 * Autor: Ángel Julián Bolaño Campos
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Editor: Visual Studio Code
 * Estilo Google C++ Style Guide
 * Práctica 6: Busqueda de patrones
 * 
*/

#include "pattern_search.h"


PatternSearch::PatternSearch( std::string pattern_to_make, std::string         name_file_input, std::string name_file_output) {
  if (PatternBelongsAlphabet(pattern_to_make)) {
    pattern_ = pattern_to_make;
    file_input_.open(name_file_input);
    file_output_.open(name_file_output);
    if (file_input_.is_open() && file_output_.is_open()) {
      std::cout << "Ficheros abiertos" << std::endl;
    }
  } else {
    std::cout << "No pertenece al alfabeto el patron" << std::endl;
  }
}
PatternSearch::~PatternSearch() {
  if (file_input_.is_open()) {
    file_input_.close();
    std::cout << "Fichero de entrada cerrado" << std::endl;
  }
  if (file_output_.is_open()) {
    file_output_.close();
    std::cout << "Fichero de salida cerrado." << std::endl;
  }
}

bool PatternSearch::PatternBelongsAlphabet(std::string pattern) {
  return alphabet_.IsInAlphabeth(pattern);
}