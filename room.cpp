#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(char newName, char newDescription, bool status) {
  strcmp(name, newName);
  strcmp(description, newDescription);
  clearstatus = status;
}

char* Room::getDescription() {
  return description*;
}

map<char*, room*>* getExits() {
  return exits;
}

char* getName() {
  return name*;
}

vector<item*>* getRoomInventory() {
  return roomInventory*;
}

void setExit(map<char*, room*>* newExit) {
  exits = *newExit;
}
void setItem(Item* newItem) {
  roomInventory.push_back(newItem);
