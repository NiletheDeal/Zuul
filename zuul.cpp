#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main {
  char* north = (char*)("north");
  char* east = (char*)("east");
  char* south = (char*)("south");
  char* west = (char*)("west");
  map<char*, char*> tempMap;
  vector<room*> rooms;
  item* sword = new item("Sword")
  room* entrance = new room("Dungeon Entrance.", "You must clear the dungeon to escape!", true);
  tempMap.insert(
  entrance->setItem(sword);
  room* tunnel1 = new room("Tunnel.", "Continue ahead in your journey!", true);
  room* specialTunnel = new room("Tunnel.", "There is a blocked entrance to the East if only you could blow up the blockade!", false);
  room* tunnel2 = new room("Tunnel.", "Continue ahead in your journey!", true);
  room* tunnel3 = new room("Tunnel.", "Continue ahead in your journey!", true);
  room* tunnel4 = new room("Tunnel.", "Continue ahead in your journey!", true);
  room* tunnel5 = new room("Tunnel.", "Continue ahead in your journey!", true);
  room* tunnel6 = new room("Tunnel.", "Continue ahead in your journey!", true);
  room* laboratory = new room("Laboratory.", "The laboratory is overrun with zombies, if you have a sword you could clear the room!", false);
  item* bomb = new item("Bomb");
  laboratory->setItem(bomb);
  room* targetRange = new room("Shooting Range.", "There is a large chasm with targets on the other side. If you had a bow you could shoot the targets and open the secret exit.", false);
  room* storageRoom = new room("Store Room.", "Its old and musty, but their could be something valueable if you looked around.", true);
  item* shield = new item("Shield");
  storageRoom1->setItem(shield);
  room* graveyard = new room("Graveyard.", "It's overrun by skeletons! If you had a shield to block the arrows you could clear out the room." false);
  item* bow = new item("Bow");
  graveyard->setItem(bow);
  room* shrine = new room("Shrine.", "It's a safe Haven!", true);
  item* potion = new item("Potion");
  shrine->setItem(potion);
  room* emptyRoom = new room("Empty Room.", "It just an empty room. Why is this here. Its almost as if this is just here to complete a requirement of the dungen creation", true);
  room* bossRoom = new room("Boss Room.", "You need all the weapons you have collected on your journey to beat the boss and escape!", false);

  
  
  
  bool stillPlaying = true;
  while (stillPlaying == true) {
    
