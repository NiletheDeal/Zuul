#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(char newName, char newDescription) {
  strcmp(name, newName);
  strcmp(description, newDescription);
  
}

char* Room::getDescription() {
  return description*;
}

map<int, char*>* getExits() {
  return exits;
}

char* getName() {
  return name*;
}

vector<item*>* getRoomInventory() {
  return roomInventory*;
}

void setExit(map<int, char*> newExit) {
  exits = newExit;
}
void setItem(Item* newItem) {
  roomInventory.push_back(newItem);
