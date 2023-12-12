//Neel Madala
//12/11/2023
//This program is a simple word game called Zuul, you must collect all the items after exploring the dungeon to defeat the demon king and escape
//The user inputs commands and is able to control their player and move, pick up and drop items, and look at their inventory
//Map of the dungeon here: https://docs.google.com/drawings/d/1C4ZLu9F7oKjfm3mi2CtK-IYUhvED-5U-d5u6Iy6GvKo/edit?usp=sharing

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

void setRoom(vector<Room*> &rooms);
void printRoom(vector<Room*> &rooms, char* &currentRoom);
void printInventory(vector<Item*> &playerInventory);
void getItem(vector<Room*> &rooms, char* &currentRoom, char* &itemName, vector<Item*> &playerInventory);
void dropItem(vector<Room*> &rooms, char* &currentRoom, char* &itemName, vector<Item*> &playerInventory);
char* move(vector<Room*> &rooms, char* &currentRoom, char* &direction);
bool inventoryContains(vector<Item*> &playerInventory, char* &itemName);

int main() {
  vector<Room*> roomsList;
  vector<Item*> inventory;
  setRoom(roomsList);
  
  char* potentialDescription = new char[200];
  char* potentialItemName = new char[10];
  
  bool stillPlaying = true;
  char command[10];
  char* commandInput = new char[10];
  char* currentRoom = new char[25];
  strcpy(currentRoom, "Tunnel 6");
  
  cout << "Welcome to Dungeon Destroyer! You are trapped in a dungeon and you must collect all the items, have them in certain rooms to traverse through the dungeon. If you reach the boss room with all the items necessary (sword, bomb, shield, bow, potion)" << endl;
  cout << "The commands available to you are GO, GET, DROP, INVENTORY, QUIT." << endl;
  while (stillPlaying == true) {
    vector<Room*>::iterator room;
    for(room = roomsList.begin(); room != roomsList.end(); room++) {//find the room the player is in
      if(strcmp(currentRoom,(*room)->getName()) == 0) {//this is the room the player is in
	if(strcmp((*room)->getName(), "Laboratory") == 0 && (*room)->getStatus() == 0) {//if the room the player is in is the Laboratory and the laboratory isn't cleared
	  strcpy(potentialItemName, "Sword");
	  if(inventoryContains(inventory, potentialItemName) == true) {//if the player also has the sword, then they clear the room
	    strcpy(potentialDescription, "The Beheaded Corpses of Zombies slayed by your sword litter the floor, but the room is atleast safe.");
	    (*room)->clearRoom(potentialDescription);
	  }
	}
	else if(strcmp((*room)->getName(), "Graveyard") == 0 && (*room)->getStatus() == 0) {//if the room the player is in is the graveyard and the graveyard isn't cleared
	  strcpy(potentialItemName, "Shield");
	  if(inventoryContains(inventory, potentialItemName) == true) {//if the player also has the Shield, then they clear the room
	    strcpy(potentialDescription, "You block the arrows of the skeletons that occupy the graveyard and crush their bones to fine powder.");
	    (*room)->clearRoom(potentialDescription);//change description and clear the room
	  }
	}
	else if(strcmp((*room)->getName(), "Boss Room") == 0 && (*room)->getStatus() == 0) { //Boss Room Clear Condition
	  cout << inventory.size() << endl;
	  if(inventory.size() >= 5) {//if you have all the items
	    cout << "You block the demon lord's attack with your shield, throw the healing potion on it acting as poison on demons. You shoot a bomb arrow and slay the demon lord clearing the dungeon. Good Job!";
	    return 0;
	  }
	}
      }
    }
    printRoom(roomsList, currentRoom);//print the room data of the player
    cout << "What would you like to do? (GO, GET, DROP, INVENTORY, QUIT)" << endl;
    cin >> command;
    if(strcmp(command, "GO") == 0) {
      cout << "Which Direction would you like to go of the exits?" << endl;
      cin >> commandInput;
      char* destination = move(roomsList, currentRoom, commandInput);
      if(strcmp(destination, " ") != 0) {
	strcpy(currentRoom, destination);
      }
      else {
	cout << "There is no exit there unless you got some crazy super powers." << endl;
      }
    }
    else if(strcmp(command, "GET") == 0) {
      cout << "What Item would you like to pick up?" << endl;
      cin >> commandInput;
      getItem(roomsList, currentRoom, commandInput, inventory);
    }
    else if(strcmp(command, "DROP") == 0) {
     cout << "What Item would you like to drop?" << endl;
     cin >> commandInput;
     dropItem(roomsList, currentRoom, commandInput, inventory);
    }
    else if(strcmp(command, "INVENTORY") == 0) {
      printInventory(inventory);
    }
    else if(strcmp(command, "QUIT") == 0) {
      return 0;
    }
  }
}

void setRoom(vector<Room*> &rooms) {//intialize the rooms with their items and exits as well as names and description
  char* north = (char*)("north");
  char* east = (char*)("east");
  char* south = (char*)("south");
  char* west = (char*)("west");
  map<char*, Room*> tempMap;

  char* name = new char[25];
  strcpy(name, "Sword");
  Item* sword = new Item(name);
  strcpy(name, "Dungeon Entrance");
  char* description = new char[200];
  strcpy(description, "You must clear the dungeon to escape!");
  Room* entrance = new Room(name, description, true);
  entrance->setItem(sword);

  strcpy(name, "Tunnel 1");
  strcpy(description, "Continue ahead in your journey!");
  
  Room* tunnel1 = new Room(name, description, true);

  strcpy(name, "Tunnel 2");
  Room* tunnel2 = new Room(name, description, true);

  strcpy(name, "Tunnel 3");
  Room* tunnel3 = new Room(name, description, true);

  strcpy(name, "Tunnel 4");
  Room* tunnel4 = new Room(name, description, true);

  strcpy(name, "Tunnel 5");
  Room* tunnel5 = new Room(name, description, true);

  strcpy(name, "Tunnel 6");
  Room* tunnel6 = new Room(name, description, true);

  strcpy(name, "Special Tunnel");
  strcpy(description, "Don't forget to explore the southern path before taking the eastern path");
  Room* specialTunnel = new Room(name, description, true);

  strcpy(name, "Laboratory");
  strcpy(description, "The laboratory is overrun with zombies, if you have a sword you could clear the room!");
  Room* laboratory = new Room(name, description, false);
  strcpy(name, "Bomb");
  Item* bomb = new Item(name);
  laboratory->setItem(bomb);

  strcpy(name, "Shooting Range");
  strcpy(description, "Grab all the items on this level before going east");
  Room* targetRange = new Room(name, description, true);

  strcpy(name, "Store Room");
  strcpy(description, "Its old and musty, but their could be something valueable to you if you looked around.");
  Room* storageRoom = new Room(name, description, true);
  strcpy(name, "Shield");
  Item* shield = new Item(name);
  storageRoom->setItem(shield);

  strcpy(name, "Graveyard");
  strcpy(description, "It's overrun by skeletons! If you had a shield to block the arrows you could clear out the room.");
  Room* graveyard = new Room(name, description, false);
  strcpy(name, "Bow");
  Item* bow = new Item(name);
  graveyard->setItem(bow);

  strcpy(name, "Shrine");
  strcpy(description, "It's a safe Haven!");
  Room* shrine = new Room(name, description, true);
  strcpy(name, "Potion");
  Item* potion = new Item(name);
  shrine->setItem(potion);

  strcpy(name, "Empty Room");
  strcpy(description, "It just an empty room. Why is this here? Its almost as if this is just here to complete a requirement of the dungen creation.");
  Room* emptyRoom = new Room(name, description, true);

  strcpy(name, "Boss Room");
  strcpy(description, "You need all the weapons you have collected on your journey to beat the boss and escape!");
  Room* bossRoom = new Room(name, description, false);

  tempMap.insert(pair<char*, Room*>(south, tunnel1));
  entrance->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, entrance));
  tempMap.insert(pair<char*, Room*>(south, specialTunnel));
  tunnel1->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, tunnel1));
  tempMap.insert(pair<char*, Room*>(south, tunnel2));
  tempMap.insert(pair<char*, Room*>(east, targetRange));
  specialTunnel->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, specialTunnel));
  tempMap.insert(pair<char*, Room*>(south, laboratory));
  tunnel2->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, tunnel2));
  laboratory->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, tunnel3));
  tempMap.insert(pair<char*, Room*>(south, tunnel4));
  tempMap.insert(pair<char*, Room*>(west, specialTunnel));
  tempMap.insert(pair<char*, Room*>(east, tunnel5));
  targetRange->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, storageRoom));
  tempMap.insert(pair<char*, Room*>(south, targetRange));
  tunnel3->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(south, tunnel3));
  storageRoom->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, targetRange));
  tempMap.insert(pair<char*, Room*>(south, graveyard));
  tunnel4->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, tunnel4));
  graveyard->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, shrine));
  tempMap.insert(pair<char*, Room*>(south, emptyRoom));
  tempMap.insert(pair<char*, Room*>(east, tunnel6));
  tempMap.insert(pair<char*, Room*>(west, targetRange));
  tunnel5->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(south, tunnel5));
  shrine->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(north, tunnel5));
  emptyRoom->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(west, tunnel5));
  tempMap.insert(pair<char*, Room*>(east, bossRoom));
  tunnel6->setExits(tempMap);
  tempMap.clear();

  tempMap.insert(pair<char*, Room*>(west, tunnel6));
  bossRoom->setExits(tempMap);
  tempMap.clear();

  rooms.push_back(entrance);
  rooms.push_back(tunnel1);
  rooms.push_back(specialTunnel);
  rooms.push_back(tunnel2);
  rooms.push_back(laboratory);
  rooms.push_back(storageRoom);
  rooms.push_back(tunnel3);
  rooms.push_back(targetRange);
  rooms.push_back(tunnel4);
  rooms.push_back(graveyard);
  rooms.push_back(tunnel5);
  rooms.push_back(shrine);
  rooms.push_back(emptyRoom);
  rooms.push_back(tunnel6);
  rooms.push_back(bossRoom);
  cout << "Done intializing" << endl;
}
void printRoom(vector<Room*> &rooms, char* &currentRoom) {//prints the data of the room the player is currently in
  vector<Room*>::iterator room;
  for(room = rooms.begin(); room != rooms.end(); room++) {//goes through all rooms to find the room the player is in
    if(strcmp(currentRoom,(*room)->getName()) == 0) {//based on the name of rooms
      cout << "You are in the " << (*room)->getName() << "." << endl;
      cout << (*room)->getDescription() << endl;
      map<char*, Room*>::iterator exit;
      cout << endl;
      cout << "Exits:" << endl;
      for(exit = (*room)->getExits()->begin(); exit != (*room)->getExits()->end(); exit++) {//goes through the exit map of the room
	cout << " " << exit->first << endl;
      }
      cout << endl;

      cout << "Items in this room: " << endl;;
      int itemCount = 0;
      vector<Item*>::iterator items;
      for(items = (*room)->getRoomInventory()->begin(); items != (*room)->getRoomInventory()->end(); items++){//goes through the vector of the room
	cout << " " << (*items)->getItemName() << endl;
	itemCount++;
      }
      if (itemCount == 0) {//if no items
	cout << "No items in this room." << endl << endl;
      }
      else {
	cout << endl;
      }
    }
  }
}
void printInventory(vector<Item*> &playerInventory) {//prints out the player's inventory vector
  vector<Item*>::iterator inven;
  cout << "You Have: " << endl;
  for(inven = playerInventory.begin(); inven != playerInventory.end(); inven++) {
    cout << " " << (*inven)->getItemName() << endl;
  }
  cout << endl;
}
void getItem(vector<Room*> &rooms, char* &currentRoom, char* &itemName, vector<Item*> &playerInventory) {//finds current room and then compares what item the player asks for and the inventory of the room
  vector<Room*>::iterator room;
  for(room = rooms.begin(); room != rooms.end(); room++) {//find room
    if(strcmp(currentRoom,(*room)->getName()) == 0 && (*room)->getStatus() == 1) {//matches room and makes sure the room is clear
      vector<Item*>::iterator roomInven;
      for(roomInven = (*room)->getRoomInventory()->begin(); roomInven != (*room)->getRoomInventory()->end(); roomInven++) {//go through items of the room
	if(strcmp(itemName, (*roomInven)->getItemName()) == 0) {//if this item is the one the player wants
	  playerInventory.push_back(*roomInven);
	  (*room)->removeItem(roomInven);
	  return;
	}
      }
    }
    else if ((*room)->getStatus() == 0) {//if the room isn't clear block the player from picking up item
      cout << "You are unable to pickup any items without clearing the room of danger first." << endl;
      return;
    }
  }
  cout << "That item is not here." << endl;
}
void dropItem(vector<Room*> &rooms, char* &currentRoom, char* &itemName, vector<Item*> &playerInventory) {//same thing as getItem, but swap where item goes
 vector<Room*>::iterator room;
  for(room = rooms.begin(); room != rooms.end(); room++) {
    if(strcmp(currentRoom,(*room)->getName()) == 0) {
      vector<Item*>::iterator playerInven;
      for(playerInven = playerInventory.begin(); playerInven != playerInventory.end(); playerInven++) {
	if(strcmp(itemName, (*playerInven)->getItemName()) == 0) {
	  (*room)->setItem(*playerInven);
	  playerInventory.erase(playerInven);
	  return;
	}
      }
    }
  }
  cout << "You do not have that Item." << endl;
  return;
} 
char* move(vector<Room*> &rooms, char* &currentRoom, char* &direction) {//find current room through name and then go through the rooms exits and find the destination of the direction 
  vector<Room*>::iterator move;
  for(move = rooms.begin(); move != rooms.end(); move++) {
    if(strcmp(currentRoom, (*move)->getName()) == 0) {
      map<char*, Room*> exits;
      exits = *(*move)->getExits();
      map<char*, Room*>::const_iterator map;
      for(map = exits.begin(); map != exits.end(); ++map) {//go through exits
	if(strcmp(map->first, direction) == 0) {//matches which direction the player wants to go and the destination of that direction
	  char* destination;
	  destination = ((*map).second)->getName();
	  return destination;
	}
      }
    }
  }
  //returns set value if there is no destination
  char* empty = new char[2];
  strcpy(empty, " ");
  return empty;
}
bool inventoryContains(vector<Item*> &playerInventory, char* &itemName) {//checks player inventory for an item given by the game
  vector<Item*>::iterator playerInven;
  for(playerInven = playerInventory.begin(); playerInven != playerInventory.end(); playerInven++) {
    if(strcmp(itemName, (*playerInven)->getItemName()) == 0) {
      return true;
    }
  }
  return false;
}


