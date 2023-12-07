#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"

using namespace std;

class Room {
 public:
  Room(char newName, char newDescription);
  char* getDescription();
  char* getName();
  vector<item*>* getRoomInventory(); 
  map<int, char*>* getExits();

  void setExit(map<int, char*> newExit);
  void setItem(Item* newItem);

  void addExit(char* direction, room* destination);
 private:
  char description[1000];
  map<int, char*> exits;
  char name[80];
  vector<item*> roomInventory;
};
#endif
