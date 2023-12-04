#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main {
  vector<room*> rooms;
  item* sword = new item("Sword")
  room* entrance = new room("Dungeon Entrance", "You are at the Dungeon Entrance. You must clear the dungeon to escape!")
  bool stillPlaying = true;
  while (stillPlaying == true) {
    
