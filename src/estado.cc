/*
 * Autor: Ángel Julián Bolaño Campos
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Editor: Visual Studio Code
 * Estilo Google C++ Style Guide
 * Práctica 6: Busqueda de patrones
 * 
*/

#include "estado.h"

void State::CleanData() {
  id_ = 0;
  name_state_.clear();
  acept_state_= false;
  start_state_ = false;
  std::pair<char,unsigned> aux;
  transition_ = aux; 
  
}


void State::InsertTransition(std::pair<char,unsigned> new_transition) {
  SetTransition(new_transition);
}


void State::PrintTransition() const {
   std::cout << GetName() << '\n';
   std::cout << "Con: " << transition_.first << " a estado " << transition_.second << '\n' << std::endl;

}



State::State(const State& rhs) {
  this->id_= rhs.id_;
  this->name_state_ = rhs.name_state_;
  this->acept_state_ = rhs.acept_state_;
  this->transition_ =rhs.transition_;
  this->start_state_ = rhs.start_state_;
}


State& State::operator=(const State& rhs) {
  this->id_ = rhs.id_;
  this->name_state_ = rhs.name_state_;
  this->acept_state_ = rhs.acept_state_;
  this->transition_ =rhs.transition_;
  this->start_state_ = rhs.start_state_;
  return *this;
}