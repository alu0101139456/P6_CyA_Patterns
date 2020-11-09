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
  for (auto it=states_dfa_.begin() ; it != states_dfa_.end(); ++it) {
    if (it->IsStartState())
      return ("\""+it->GetName()+"\"");
  }
  return "--";
}

/* GenerateDfaWithPattern
Los estados de arranque e inicial se crean fuera del bucle para controlar sus
estados especiales de arranque y aceptación */
void Dfa::GenerateDfaWithPattern(std::string pattern) {
  //Contemplada posibilidad de patron de un simbolo
  if (pattern.size() > 1) {
    State aux(0, false, true);
    aux.InsertTransition(std::make_pair(pattern[0],1));
    states_dfa_.insert(aux);
    for (uint i = 1; i < pattern.size(); i++) {
      aux.CleanData(); 
      aux.SetId(i);
      aux.InsertTransition(std::make_pair(pattern[i], i+1));
      states_dfa_.insert(aux);

    }
    aux.CleanData();
    aux.SetId(pattern.size());
    aux.SetAceptState(true);
    states_dfa_.insert(aux);
    // SeeWhat(aux);
  } else {
    State aux(0, true, true);
  } 
  

}

/* SearchPatternInString
Se declara un uint, que será donde se guarde si hay cambio de estado.
Se crea un iterador que apunta al estado de arranque (Comienzo del set)
La función State::Transition busca el caracter que se le pasa entre las
transiciones que tiene y devuelve el estado al que debe transitar con ese simbolo. 
Si valor == -1 no encontro transicion y se reinicia el iterador al principio
Si valor != -1 it se queda apuntando en el siguiente estado para esperar el 
siguiente simbolo  */
bool Dfa::SearchPatternInString(std::string word) {
  bool get_acept_state = false;
  uint new_id;
  std::set<State>::iterator it = Begin();
  //Recorremos la cadena completa
  for (size_t i = 0; i < word.size(); i++) {
    if ((new_id = it->Transition(word[i])) == (uint)-1) {
      it = Begin();
    } else {
      it = states_dfa_.find(State(new_id, ""));
      get_acept_state = it->IsAceptState() || get_acept_state;
    }
  }
  return get_acept_state;
}




///////// DEBUGG AND TEST

void Dfa::SeeWhat(State state_to_see) {
  std::cout << "-----------------------------------------"<< std::endl;;
  std::cout << "Estado con id: " << state_to_see.GetId() << '\n';
  std::cout << "Estado de arranque: "<<state_to_see.IsStartState()<<"\n";
  std::cout << "Estado de aceptación: "<<state_to_see.IsAceptState();
  std::cout << "\nCon transiciones: ";
  state_to_see.PrintTransitions();
  
}