#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item(char* Name);
  char* getItemName();
 private:
  char name[30];
};
#endif
