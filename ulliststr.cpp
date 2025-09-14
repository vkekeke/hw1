#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
  if( empty() ) { // if empty list
    head_ = new Item;
    tail_ = head_;
    head_->val[head_->last] = val;
    head_->last++;
  } else if( tail_->last < ARRSIZE ) { // if current item has space
    tail_->val[tail_->last] = val;
    tail_->last++;
  } else { // create new Item at the back
    Item* newItem = new Item;
    newItem->val[newItem->last] = val;
    newItem->last++;
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  if( empty() ) {
    head_ = new Item;
    tail_ = head_;
    head_->val[head_->last] = val;
    head_->last++;
  } else if( head_->first != 0 ) {
    head_->val[head_->first - 1] = val;
    head_->first--;
  } else { // create new Item at the front
    Item* newItem = new Item;
    newItem->val[ARRSIZE-1] = val;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
  }
  size_++;
  
}

void ULListStr::pop_back() {
  if( empty() ) {
    return;
  } 
  tail_->last--;
  size_--;
  if( tail_->last == tail_->first ) { // delete the Item
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
  }
  if( empty() ) { // if the last Item has been deleted
    head_ = nullptr;
    return;
  }
  tail_->next = nullptr;
}

void ULListStr::pop_front() {
  if( empty() ) {
    return;
  }
  head_->first++;
  size_--;
  if( head_->last == head_->first ) { // delete the Item
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
  }
  if( empty() ) { // if the last Item has been deleted
    tail_ = nullptr;
    return;
  }
  head_->prev = nullptr;

}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if( loc >= size_) {
    return nullptr;
  }
  Item* temp = head_;

  size_t curr_size = temp->last - temp->first;
  
  while( curr_size < loc+1 ) {
    temp = temp->next;
    curr_size += temp->last - temp->first;
  }
  int locBack = curr_size - loc;
  int locInArr = temp->last - locBack;
  std::string* valLoc = temp->val + locInArr;
  return valLoc;
}
// End of the Answer



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
