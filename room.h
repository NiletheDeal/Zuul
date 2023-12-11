#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class Room {
 public:
  Room(char* newName, char* newDescription, bool status);
  char* getDescription();
  char* getName();
  vector<Item*>* getRoomInventory(); 
  map<char*, Room*>* getExits();
  bool getStatus();

  void setExits(map<char*, Room*> newExit);
  void setItem(Item* newItem);
  void removeItem(vector<Item*>::iterator oldItem);
  void clearRoom(char* newDescription);
 private:
  char* description;
  map<char*, Room*> exits;
  char* name;
  vector<Item*> roomInventory;
  bool clearStatus;
};
#endif
