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


void Dfa::InsertState(State new_state) {
  states_dfa_.insert(new_state);
}


//Busca entre los estados el que tiene mismo nombre y devuelve el iterador
std::set<State>::iterator Dfa::FindStateName(std::string& name_to_find){
  std::set<State>::iterator it;
  for(it = states_dfa_.begin(); it != states_dfa_.end(); ++it) {
    if(it->GetName() == name_to_find ) 
      return it;
  }
  return it;
}

void Dfa::UpdateState(std::set<State>::iterator& it,const State& nuevo) {
  std::cout << it->GetName() << '\n';
  if (it != states_dfa_.end()){
    states_dfa_.erase(it);
    states_dfa_.insert(nuevo);
  }
}

std::set<State> Dfa::GetStates() {
 return states_dfa_;

}

std::set<State>::iterator Dfa::Begin() {
  return states_dfa_.begin();
}

std::set<State>::iterator Dfa::End() {
  return states_dfa_.end();
}


std::vector<std::string> Dfa::GetAceptStates() {
  std::vector<std::string> aux;
  for(auto it=states_dfa_.begin() ; it != states_dfa_.end(); ++it) {
    if(it->IsAceptState())
      aux.push_back("\""+it->GetName()+"\"");
  }
  return aux;
}

std::string Dfa::GetStartState() {
  for(auto it=states_dfa_.begin() ; it != states_dfa_.end(); ++it) {
    if(it->IsStartState())
      return ("\""+it->GetName()+"\"");
  }
  return "--";
}

void Dfa::GenerateDfaWithPattern(std::string pattern) {

  
}
