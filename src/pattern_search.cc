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


PatternSearch::PatternSearch( std::string pattern_to_make, std::string name_file_input, std::string name_file_output) {

  alphabet_.InsertAlphabetACII(); //El Alfabeto lo genera el objeto segun opcion
  if (StringBelongsAlphabet(pattern_to_make)) {
    pattern_ = pattern_to_make;
    file_input_.open(name_file_input);
    file_output_.open(name_file_output);
    MakeDFA();
    ReadFromFile();
  } else {
    std::cerr << "El patron no pertenece al alfabeto." << std::endl;
  }

}
PatternSearch::~PatternSearch() { //Cierra los ficheros si estan abiertos
  if (file_input_.is_open()) {
    file_input_.close();
  }
  if (file_output_.is_open()) {
    file_output_.close();
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
          if(SearhPattern(aux)) {
            file_output_ << "SI\"" << aux <<"\"\n";
          } else {
            file_output_ << "NO \"" << aux <<"\"\n";
          }
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
  dfa_.SetAlphabet(alphabet_);
  dfa_.GenerateDfaWithPattern(pattern_);
}

bool PatternSearch::SearhPattern(std::string string_to_analize) {
  return dfa_.SearchPatternInString(string_to_analize);
}