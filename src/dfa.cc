/*
 * Autor: Ángel Julián Bolaño Campos
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Editor: Visual Studio Code
 * Estilo Google C++ Style Guide
 * Práctica 6: Busqueda de patrones
 * 
*/

#include "dfa.h"


void DFA::InsertState(State new_state) {
  states_dfa_.insert(new_state);
}


//Busca entre los estados el que tiene mismo nombre y devuelve el iterador
std::set<State>::iterator DFA::FindStateName(std::string& name_to_find){
  std::set<State>::iterator it;
  for(it = states_dfa_.begin(); it != states_dfa_.end(); ++it) {
    if(it->GetName() == name_to_find ) 
      return it;
  }
  return it;
}

void DFA::UpdateState(std::set<State>::iterator& it,const State& nuevo) {
  std::cout << it->GetName() << '\n';
  if (it != states_dfa_.end()){
    states_dfa_.erase(it);
    states_dfa_.insert(nuevo);
  }
}

std::set<State> DFA::GetStates() {
 return states_dfa_;

}

std::set<State>::iterator DFA::Begin() {
  return states_dfa_.begin();
}

std::set<State>::iterator DFA::End() {
  return states_dfa_.end();
}


std::vector<std::string> DFA::GetAceptStates() {
  std::vector<std::string> aux;
  for(auto it=states_dfa_.begin() ; it != states_dfa_.end(); ++it) {
    if(it->IsAceptState())
      aux.push_back("\""+it->GetName()+"\"");
  }
  return aux;
}

std::string DFA::GetStartState() {
  for(auto it=states_dfa_.begin() ; it != states_dfa_.end(); ++it) {
    if(it->IsStartState())
      return ("\""+it->GetName()+"\"");
  }
  return "--";
}


