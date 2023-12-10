#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

Item::Item(char* Name) {
  for (int i = 0; i<30; i++) {
    name[i] = '\0';
  }
  name = Name;
}
char* Item::getItemName() {
  return name;
}
