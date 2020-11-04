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

class State {
 private:
  unsigned id_;
  std::string name_state_;
  bool acept_state_;
  bool start_state_ = false;
  std::pair<char,unsigned> transition_;

 public:
  State() {}
  ~State() {}
  State(std::string name): name_state_(name) {}
  State(unsigned id, std::string name):
    id_(id),
    name_state_(name)
  {}
  State(const State&);
  State(unsigned id, std::string name_state, bool acept, bool start):
    id_(id),
    name_state_(name_state),
    acept_state_(acept),
    start_state_(start){}

  void CleanData();
  void InsertTransition(std::pair<char,unsigned> aux);
  void PrintTransition() const;


  //GETTERS
  inline unsigned int GetId() const { return id_; }
  inline std::string GetName() const {return name_state_;}
  inline bool IsAceptState() const { return acept_state_; }
  inline int IsStartState() const { return start_state_; }



  //SETTERS
  inline void SetAceptState(bool is_acept_state) { acept_state_ = is_acept_state; }
  inline void SetTransition(std::pair<char,unsigned> transition_in) { transition_ = transition_in; }
  inline void SetStartState(bool is_start) { start_state_ = is_start; }
  inline void SetId(unsigned id) { id_ = id; }
  inline void SetName(std::string name) { name_state_ = name; }

  //OPERATORS
  bool operator<(const State& rhs) const {
    return (this->GetId() < rhs.GetId());}
  
  bool operator==(const State& rhs) const {
    return (this->GetName() == rhs.GetName()); }
  
  State& operator=(const State& rhs);
};