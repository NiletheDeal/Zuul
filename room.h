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
  //constructors
  Room(char* newName, char* newDescription, bool status);

  //getters
  char* getDescription();
  char* getName();
  vector<Item*>* getRoomInventory(); 
  map<char*, Room*>* getExits();
  bool getStatus();

  //setters and editors
  void setExits(map<char*, Room*> newExit);
  void setItem(Item* newItem);
  void removeItem(vector<Item*>::iterator oldItem);
  void clearRoom(char* newDescription);
private://varialbes
  char* description;
  map<char*, Room*> exits;
  char* name;
  vector<Item*> roomInventory;
  bool clearStatus;
};
#endif
