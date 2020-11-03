#include <set.h>

Set::Set() {
  max_of_elemts_ = bits_per_set_;
  set_.assign(1, 0);
  mask_ = ~0;
  number_sets_ = 1;
}



Set::Set(const int size) {
  assert(size > 0);
  max_of_elemts_ = size;
  int size_of_vector = size / bits_per_set_;
  if (size % bits_per_set_) {
    size_of_vector++;
  }
  set_.assign(size_of_vector, 0);
  mask_ = ~0;
  int number_elemnts_left = size % bits_per_set_;
  int how_much_to_move = bits_per_set_ - number_elemnts_left;
  mask_ = mask_ >> how_much_to_move;
  number_sets_ = size_of_vector;
}



Set::Set(const Set& SecondSet) {
  max_of_elemts_ = SecondSet.max_of_elemts_;
  set_ = SecondSet.set_;
  mask_ = SecondSet.mask_;
  number_sets_ = SecondSet.number_sets_;
}



std::vector<unsigned long>
Set::get_set(void) const {
  return set_;
}



Set Set::operator +(const Set& SecondSet) {
  Set Result(*this);
  unsigned min_size = SecondSet.max_of_elemts_;
  unsigned long temp_mask = mask_;
  if (SecondSet.max_of_elemts_ > max_of_elemts_) {
    Result = SecondSet;
    min_size = max_of_elemts_;
    temp_mask = SecondSet.mask_;
  }
  int condition = min_size / bits_per_set_
                  - ((min_size % bits_per_set_) ? 0 : 1);
  for (int position = 0; position <= condition; position ++) {
    Result.set_.at(position) = set_.at(position) | SecondSet.set_.at(position);
  }
  
  *(Result.set_.end()-1) = temp_mask & *(Result.set_.end()-1);
  return Result;
}



Set Set::operator *(const Set& SecondSet) {
  Set Result(SecondSet);
  unsigned min_size = SecondSet.max_of_elemts_;
  unsigned long temp_mask = SecondSet.mask_;
  if (SecondSet.max_of_elemts_ > max_of_elemts_) {
    Result = *this;
    min_size = max_of_elemts_;
    temp_mask = mask_;
  }
  int condition = min_size / bits_per_set_
                  - ((min_size % bits_per_set_) ? 0 : 1);
  for (int position = 0; position <= condition; position ++) {
    Result.set_.at(position) = set_.at(position) & SecondSet.set_.at(position);
  }
  /** Habría que comprobar que el vector no está vacío, pero no es posible
   *  crear un vector vacío por el constructor
   */
  *(Result.set_.end()-1) = temp_mask & *(Result.set_.end()-1);
  return Result;
  }


Set Set::operator !() const {
  Set Result(max_of_elemts_);
  for (unsigned position = 0; position < set_.size(); position++)
    Result.set_.at(position) = ~set_.at(position);
  /** Habría que comprobar que el vector no está vacío, pero no es posible
   *  crear un vector vacío por el constructor
   */
  Result.set_.back() = mask_ & Result.set_.back();
  return Result;
}



Set Set::operator -(const Set& SecondSet) {
  Set dummy = !SecondSet;
  Set biggest_set = *this;
  Set smalest_set = dummy;
  if (dummy.set_.size() > set_.size()) {
    biggest_set = dummy;
    smalest_set = *this;
  }
  Set Result(biggest_set.number_sets_);
  for (unsigned v_position = 0; v_position < biggest_set.number_sets_;
       v_position++) {
    if (v_position < smalest_set.number_sets_)
    Result.set_.at(v_position) = set_.at(v_position)
                                 & dummy.set_.at(v_position);
  }
  return Result;
}


void Set::operator =(const Set& SecondSet) {
  number_sets_ = SecondSet.number_sets_;
  max_of_elemts_ = SecondSet.max_of_elemts_;
  set_.resize(number_sets_);
  for (unsigned position = 0; position < number_sets_; position++) {
    set_.at(position) = SecondSet.set_.at(position);
  }
  mask_ = SecondSet.mask_;
}



bool Set::operator ==(const Set& SecondSet) {
  bool is_equal = 1;
  Set biggest_set = *this;
  Set smalest_set = SecondSet;
  if (SecondSet.set_.size() > set_.size()) {
    biggest_set = SecondSet;
    smalest_set = *this;
  }
  for (unsigned position = 0; position < number_sets_; position ++) {
    if (set_.at(position) != SecondSet.set_.at(position)) {
      is_equal = 0;
    }
  }
  return is_equal;
}



void Set::Add(const int number_to_add) {
  assert(number_to_add > 0);
  unsigned position_of_vector = number_to_add / bits_per_set_;
  if (number_to_add % bits_per_set_ == 0) {
    position_of_vector--;
  }
  long temp_number = 1;
  temp_number = temp_number << (number_to_add % bits_per_set_ - 1);
  set_.at(position_of_vector) = set_.at(position_of_vector) | temp_number;
  if (position_of_vector >= number_sets_) {
    set_.at(position_of_vector) &= mask_;
  }
}



void Set::AddAndResize(const int number_to_add) {
  if (number_to_add > max_of_elemts_) {
    int new_size = number_to_add / bits_per_set_;
    if (number_to_add % bits_per_set_ != 0) {
      new_size++;
    }
    set_.resize(new_size, 0);
  }
  Add(number_to_add);
}



void Set::Remove(const int number_to_remove) {
  assert(number_to_remove > 0);
  int position_of_vector = number_to_remove / bits_per_set_;
  if (number_to_remove % bits_per_set_ == 0) {
    position_of_vector--;
  }
  int dummy = number_to_remove;
  int total_move = dummy % bits_per_set_ - 1;
  long temp_number = ~1;
  for (int how_much_move = total_move; how_much_move > 0; how_much_move--) {
    temp_number = temp_number << 1;
    temp_number++;
  }
  set_.at(position_of_vector) = set_.at(position_of_vector) & temp_number;
  if (position_of_vector >= number_sets_) {
    set_.at(position_of_vector) &= mask_;
  }
}


void Set::Clear() {
  for (unsigned position = 0; position < set_.size(); position++)
    set_.at(position) = 0;
}



bool Set::IsEmpty() const {
  for (unsigned position = 0; position < set_.size() ; position++) {
    if (set_.at(position) != 0) {
      return false;
    }
  }
  return true;
}



bool Set::IsBelonging(const int number_to_prove) const {
  bool is_belonging = 0;
  int position_of_vector = number_to_prove / bits_per_set_;
  if (number_to_prove % bits_per_set_ == 0) {
    position_of_vector--;
  }
  long temp_set = 1;
  temp_set = temp_set << (number_to_prove % bits_per_set_ - 1);
  temp_set = temp_set & set_.at(position_of_vector);
  if (temp_set != 0)
    is_belonging = 1;
  return is_belonging;
}



std::string Set::toString() {
  std::stringstream output;
  output << "{";
  std::vector<int> set_elements;
  std::vector<unsigned long> dummy_set = set_;
  for (unsigned position = 0; position < dummy_set.size(); position++) {
    for (unsigned value = 1; value <= (sizeof(long) * 8); value++) {
      if ((dummy_set.at(position) % 2) == 1) {
        set_elements.push_back(value + (position * (sizeof(long) * 8)));
        dummy_set.at(position) = dummy_set.at(position) >> 1;
      } else {
        dummy_set.at(position) = dummy_set.at(position) >> 1;
      }
    }
  }
  for (unsigned elements = 0; elements < set_elements.size(); elements++) {
    if (elements < set_elements.size() - 1)
      output << set_elements.at(elements) << ", ";
    if (elements == set_elements.size() - 1)
      output << set_elements.at(elements);
  }
  output << "}";
  return output.str();
}



std::ostream&
operator <<(std::ostream& output, Set Set_write) {
  return output << Set_write.toString();
}
