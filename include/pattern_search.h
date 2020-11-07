/*
 * Autor: Ángel Julián Bolaño Campos
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Editor: Visual Studio Code
 * Estilo Google C++ Style Guide
 * Práctica 6: Busqueda de patrones
 * 
*/

#pragma once

#include <iostream>
#include <fstream>
#include "alfabeto.h"


class PatternSearch {
 private:
  Alphabet alphabet_;
  std::string pattern_;
  std::ifstream file_input_;
  std::ofstream file_output_;


 public:

  PatternSearch() {}
  ~PatternSearch();
  // PatternSearch( const PatternSearch& rhs);
  PatternSearch( std::string , std::string , std::string );

  bool PatternBelongsAlphabet(std::string);




};