#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>

class Set {
 private:
  unsigned number_sets_;            
  unsigned max_of_elemts_;          
  const unsigned bits_per_set_ = sizeof(long) * 8;
  std::vector<unsigned long> set_;  
  unsigned long mask_;              

 public:
  Set();
  explicit Set(const int);
  Set(const Set&);
  std::vector<unsigned long> get_set(void) const;

  Set operator +(const Set&);    
  Set operator *(const Set&);    
  Set operator !() const;        
  Set operator -(const Set&);    
  void operator =(const Set&);   
  bool operator ==(const Set&);
  void Add(const int);           
  void AddAndResize(const int);
  void Remove(const int);        
  void Clear();                  
  bool IsEmpty() const;
  bool IsBelonging(const int) const;

  std::string toString();
  void print() {
    for (unsigned long elements : set_)
    std::cout << elements << " ";
    std::cout << std::endl;
  }
};

std::ostream& operator <<(std::ostream& , const Set);
