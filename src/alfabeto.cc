/*
 * Autor: Ángel Julián Bolaño Campos
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Editor: Visual Studio Code
 * Estilo Google C++ Style Guide
 * Práctica 6: Busqueda de patrones
 * 
*/

#include "alfabeto.h"


Alphabet::Alphabet() {
  // InsertAlphabetACII();

}
Alphabet::Alphabet( const Alphabet& rhs) {
  alfa_ = rhs.alfa_;
}


void Alphabet::InsertAlphabetACII() {
  //Inserta los valores de la tabla ASCII
  for (size_t i = 97; i < 123; i++) {
    alfa_.Insert(i);
  }
}


std::string Alphabet::PrintAlphabet() {
  return alfa_.toString();
  
}

void Alphabet::InsertSymbol( char symbol) {
  alfa_.Insert((int)symbol);
}

bool Alphabet::FindSymbol(char symbol) {
  return alfa_.Find((int)symbol);
}

bool Alphabet::IsInAlphabeth(std::string string_to_analize) {
  int i = 0;
  
  while (alfa_.IsBelonging((int)string_to_analize[i])) {
    i++;
  }

  if (i == (int)string_to_analize.size()) {
    //std::cout << string_to_analize << "->ω ∊ ∑ " << std::endl;
    return true;
  } else {
    // std::cout << string_to_analize << "-> ω ∉ ∑ " << std::endl;
    return false;
  }
}

Alphabet& Alphabet::operator=(const Alphabet& rhs) {
  alfa_ = rhs.alfa_;
  return *this;
}