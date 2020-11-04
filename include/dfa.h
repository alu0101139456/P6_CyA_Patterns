/*
 * Autor: Ángel Julián Bolaño Campos
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Editor: Visual Studio Code
 * Estilo Google C++ Style Guide
 * Práctica 6: Busqueda de patrones
 * 
*/


#include<set>
#include<iostream>
#include<fstream>
#include<vector>
#include "alfabeto.h"
#include "estado.h"

class DFA {
 private:
  Alphabet Al_;
  std::set<State> states_dfa_;

 public:
  DFA() {}
  ~DFA() {}
  void InsertState( State estado);
  std::set<State>::iterator Begin();
  std::set<State>::iterator End();
  std::set<State> GetStates();
  std::set<State>::iterator FindStateName(std::string&);
  std::set<State>::iterator FindStateId(unsigned&);
  void UpdateState(std::set<State>::iterator&,const State&);
  
  unsigned get_size() { return states_dfa_.size(); }

  std::vector<std::string> GetAceptStates();
  std::string GetStartState();
};
