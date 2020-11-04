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
#include "set.h"
#include <fstream>
#include <string>


class Alfabeto {
 private:
  Set alfa_;

 public:

  Alfabeto();
  ~Alfabeto() {}
  Alfabeto( const Alfabeto& rhs);

  void InsertSymbol( char symbol);
  void InsertFromFile();
  bool FindSymbol(char sym);
  // std::set<caracter_t>::iterator end();
  // bool pertenece( caracter_t caracter);
  bool IsInAlphabeth(std::string expresion);
  
  Alfabeto& operator=(const Alfabeto& rhs);

};