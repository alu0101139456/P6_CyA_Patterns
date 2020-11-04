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
  InsertAlphabet();

}


void Alphabet::InsertAlphabet() {
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