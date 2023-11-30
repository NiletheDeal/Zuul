#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>

using namespace std;

class Room {
 public:
  Room(char* newDescription, int newID, int newItem);
  char* getDescription();
  int getID();
  int getItem();
  map<int, char*>* getExits();

  void setExit(map<int, char*>);
 private:
  char* description;
  map<int, char*> exits;
  int ID;
  int item;
};
#endif
