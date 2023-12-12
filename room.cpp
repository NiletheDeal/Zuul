#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(char* newName, char* newDescription, bool status) {//save name, description, and clear state
  name = new char[20];
  strcpy(name, newName);
  description = new char[200];
  strcpy(description, newDescription);
  clearStatus = status;
}

char* Room::getDescription() {
  return description;
}

map<char*, Room*>* Room::getExits() {
  return &exits;
}

char* Room::getName() {
  return name;
}
bool Room::getStatus() {
  return clearStatus;
}

vector<Item*>* Room::getRoomInventory() {
  return &roomInventory;
}

void Room::setExits(map<char*, Room*> newExit) {//assigns exits to room
  exits = newExit;
}
void Room::setItem(Item* newItem) {//assigns items to room
  roomInventory.push_back(newItem);
}
void Room::removeItem(vector<Item*>::iterator oldItem) {//remove item from room
  roomInventory.erase(oldItem);
}
void Room::clearRoom(char* newDescription) {//change description and change clear status
  strcpy(description, newDescription);
  clearStatus = true;
}
