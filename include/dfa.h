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

class Dfa {
 private:
  Alphabet al_;
  std::set<State> states_dfa_;

 public:
  Dfa() {}
  ~Dfa() {}

  //ITERATORS
  std::set<State>::iterator Begin();
  std::set<State>::iterator End();
  std::set<State>::iterator FindStateName(std::string&);
  std::set<State>::iterator FindStateId(unsigned&);

  //SETTERS
  void SetAlphabet(const Alphabet alphabet) { al_ = alphabet; }
  
  //GETTERS
  std::set<State> GetStates();
  unsigned GetSize() { return states_dfa_.size(); }
  std::vector<std::string> GetAceptStates();
  std::string GetStartState();

  void InsertState( State estado);  
  
  void UpdateState(std::set<State>::iterator&,const State&);
  
  void GenerateDfaWithPattern(std::string);

  bool SearchPatternInString(std::string);


 private:  
  //DEBUGGER FUNTIONS
  void SeeWhat(State state_to_see);

};

