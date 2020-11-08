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
  if (StringBelongsAlphabet(pattern_to_make)) {
    pattern_ = pattern_to_make;
    file_input_.open(name_file_input);
    file_output_.open(name_file_output);
    ReadFromFile();
  } else {
    std::cerr << "El patron no pertenece al alfabeto." << std::endl;
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

bool PatternSearch::StringBelongsAlphabet(std::string pattern) {
  return alphabet_.IsInAlphabeth(pattern);
}

void PatternSearch::ReadFromFile() {
  std::string aux;
  int i=0;
  try {
    if(file_input_.is_open() && file_input_) {
      while( !file_input_.eof()) {
        file_input_ >> aux;
        if( file_input_.eof()) break;
        if (StringBelongsAlphabet(aux)) {

        }
        i++;
      }
    }
    else {
      std::cerr << "Nombre de fichero erroneo. " << std::endl;
    }
       
  }
  catch ( std::exception& e) {
    std::cout << "Failed to read file" << e.what() << std::endl;
  }  
}

void PatternSearch::MakeDFA() {
  dfa_.GenerateDfaWithPattern(pattern_);
}