#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(char* newName, char* newDescription, bool status) {
  name = newName;
  description = newDescription;
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

vector<Item*>* Room::getRoomInventory() {
  return &roomInventory;
}

void Room::setExit(map<char*, Room*> newExit) {
  exits = newExit;
}
void Room::setItem(Item* newItem) {
  roomInventory.push_back(newItem);
}
void Room::addExit(char* direction, Room* destination) {
  exits.insert(*direction, *destination);
}
