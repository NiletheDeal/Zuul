#include <iostream>
#include <cstring>
#include "item.h"

using namepsace std;

Item::Item(char Name, int newID) {
  for (int i = 0; i<30; i++) {
    title[i] = '\0';
  }
  strcpy(name, Name);
  ID = newID;
}
char* Item::getName() {
  return name*;
}

int Item::getID() {
  return ID;
}
