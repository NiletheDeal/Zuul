#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item(char Name, int ID);
  char* getName();
  int getID();
 private:
  char name[30];
  int ID;
};
#endif
