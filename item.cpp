#include <iostream>
#include <cstring>
#include "item.h"

using namepsace std;

Item::Item(char Name) {
  for (int i = 0; i<30; i++) {
    title[i] = '\0';
  }
  strcpy(name, Name);
}
char* Item::getItemName() {
  return name*;
}
