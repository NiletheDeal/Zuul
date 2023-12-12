#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

Item::Item(char* Name) {//item constructor
  name = new char[10];
  strcpy(name, Name);
}
char* Item::getItemName() {//name getter
  return name;
}
