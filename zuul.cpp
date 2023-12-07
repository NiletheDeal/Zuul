#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main {
  vector<room*> roomsList;
  vector<Item*> Inventory;
  setRoom(&roomsList);
  
  
  bool stillPlaying = true;
  char[10] command;
  char[10] commandInput;
  char[80] currentRoom = "Dungeon Entrance.";
  
  
  cout << "Welcome to Dungeon Destroyer! You are trapped in a dungeon and you must collect all the items, have them in certain rooms to traverse through the dungeon. If you reach the boss room with all the items necessary (sword, shield, bow, potion)" << endl;
  cout << "The commands available to you are GO, GET, DROP, INVENTORY, QUIT." << endl;
  while (stillPlaying == true) {
    
    
    
  }
}
void setRoom(vector<room*>* rooms) {
  char* north = (char*)("north");
  char* east = (char*)("east");
  char* south = (char*)("south");
  char* west = (char*)("west");
  map<char*, room*> tempMap;
  
  item* sword = new item("Sword")
  room* entrance = new room("Dungeon Entrance", "You must clear the dungeon to escape!", true);
  entrance->setItem(sword);
  
  room* tunnel1 = new room("Tunnel", "Continue ahead in your journey!", true);
  
  room* specialTunnel = new room("Tunnel", "There is a blocked entrance to the East if only you could blow up the blockade!", false);

  room* tunnel2 = new room("Tunnel", "Continue ahead in your journey!", true);

  room* tunnel3 = new room("Tunnel", "Continue ahead in your journey!", true);

  room* tunnel4 = new room("Tunnel", "Continue ahead in your journey!", true);

  room* tunnel5 = new room("Tunnel", "Continue ahead in your journey!", true);

  room* tunnel6 = new room("Tunnel", "Continue ahead in your journey!", true);

  room* laboratory = new room("Laboratory", "The laboratory is overrun with zombies, if you have a sword you could clear the room!", false);
  item* bomb = new item("Bomb");
  laboratory->setItem(bomb);

  room* targetRange = new room("Shooting Range", "There is a large chasm with targets on the other side. If you had a bow you could shoot the targets and open the secret exit.", false);

  room* storageRoom = new room("Store Room", "Its old and musty, but their could be something valueable if you looked around.", true);
  item* shield = new item("Shield");
  storageRoom1->setItem(shield);

  room* graveyard = new room("Graveyard", "It's overrun by skeletons! If you had a shield to block the arrows you could clear out the room." false);
  item* bow = new item("Bow");
  graveyard->setItem(bow);

  room* shrine = new room("Shrine", "It's a safe Haven!", true);
  item* potion = new item("Potion");
  shrine->setItem(potion);

  room* emptyRoom = new room("Empty Room", "It just an empty room. Why is this here. Its almost as if this is just here to complete a requirement of the dungen creation", true);

  room* bossRoom = new room("Boss Room", "You need all the weapons you have collected on your journey to beat the boss and escape!", false);

  tempMap.insert(south, tunnel1);
  entrance->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, entrance);
  tempMap.insert(south, specialTunnel);
  tunnel1->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, tunnel1);
  tempMap.insert(south, tunnel2);
  specialTunnel->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, specialTunnel);
  tempMap.insert(south, laboratory);
  tunnel2->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, tunnel2);
  laboratory->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, tunnel3);
  tempMap.insert(south, tunnel4);
  targetRange->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, storageRoom);
  tempMap.insert(south, targetRange);
  tunnel3->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(south, tunnel3);
  storageRoom->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, targetRange);
  tempMap.insert(south, graveyard);
  tunnel4->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, tunnel4);
  graveyard->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, shrine);
  tempMap.insert(south, emptyRoom);
  tempMap.insert(east, tunnel6);
  tunnel5->setExits(tempmap*);
  tempMap.clear();

  tempMap.insert(south, tunnel5);
  shrine->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(north, tunnel5);
  emptyRoom->setExits(tempMap*);
  tempMap.clear();

  tempMap.insert(west, tunnel5);
  tempMap.insert(east, bossRoom);
  tunnel6->setExits(tempMap*);
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
}
void printRoom(vector<room*>* rooms, char currentRoom[]) {
  vector<Room*>::iterator room;
  for(room = rooms->begin(); room != rooms->end(); room++) {
    if(currentRoom == (*room)->getName()) {
      cout << "You are in the " << (*room)->getName() << endl;
      cout << (*room)->getDescription() << endl;
      map<char*, room*>::iterator exit;
      for(exit = (*room)->getExits()->begin(); exit != (*room)->getExits()->end(); exit++) {
	cout << exit->first << " ";
      }
      cout << endl;

      cout << " Items in this room: ";
      int itemCount = 0;
      vector<item*>::iterator items;
      for(items = (*room)->getRoomInventory()->begin(); items != (*room)->getRoomInventory()->end(); items++){
	cout <<(*item)->getItemName();
	itemCount++;
      }
      if (itemCount == 0) {
	cout << "No items in this room." << endl;
      }
      else {
	cout << endl;
      }
    }
  }
}
void printInventory(vector<item*>* playerInventory) {
  vecotr<item*>::iterator inven;
  for(inven = (*playerInventory)->begin(); inven != (*playerInventory)->end(); inven++) {
    cout << (*inven)->getItemName() << " ";
  }
  cout << endl;
}
void getItem(vector<room*>* rooms, char currentRoom[], char itemName[], vector<item*>* playerInventory) {
  vector<Room*>::iterator room;
  for(room = rooms->begin(); room != rooms->end(); room++) {
    if(currentRoom == (*room)->getName()) {
      vector<item*>::iterator roomInven;
      for(roomInven = (*room)->getRoomInventory()->begin(); roomInven != (*room)->getRoomInventory()->end(); roomInven++) {
	if(itemName == (*roomInven)->getItemName()) {
	  playerInventory->push_back(roomInven);
	  (*room)->roomInventory.erase(roomInven);
	  return;
	}
      }
    }
  }
  cout << "That item is not here." << endl;
}
void dropItem(vector<room*>* rooms, char currentRoom[], char itemName[], vector<item*>* playerInventory) {
 vector<Room*>::iterator room;
  for(room = rooms->begin(); room != rooms->end(); room++) {
    if(currentRoom == (*room)->getName()) {
      vector<item*>::iterator playerInven;
      for(playerInven = (*playerInventory)->begin(); playerInven != (*playerInventory)->end(); roomInven++) {
	if(itemName == (playerInven)->getItemName()) {
	  (*room)->roomInventory.push_back(playerInven);
	  playerInventory->erase(roomInven);
	  return;
	}
      }
    }
  }
  cout << "You do not have that Item." << endl;
} 
void move(vector<room*>* rooms, int currentRoom, char direction[]) {
  vector<room*>::iterator move;
  for(move = rooms->begin(); move != rooms->end(); move++) {
    
