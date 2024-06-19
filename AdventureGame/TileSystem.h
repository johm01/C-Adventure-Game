#pragma once

#include "Tile.h"
#include <vector>
#include <string>

using namespace std;

class TileSystem {
	public:
		void drawTileMap();
		void addTile(Tile t);
		void MapLogic(Player p, BattleSystem b, Vendor v);
		Tile getTile(int t);
		vector<Tile> getTileMap() { return this->tileMap; };

	private:
		vector<Tile> tileMap;
		
};

void TileSystem::addTile(Tile t) {
	this->tileMap.push_back(t);
}

void TileSystem::drawTileMap() {
	// output tile map 
	for (int i = 0; i <= this->tileMap.size() - 1; i++) {
		if (i % 5 == 1 and i != 1) {
			cout << endl;
		}
		
		cout <<  this->tileMap[i].getTileIcon() ;
		
	}
}

// Figure out how to clean this up better 
void TileSystem::MapLogic(Player p,BattleSystem b,Vendor v) {
	// Checking what type of tile we are on and starting the according event 
	if (this->getTile(p.getCurrTile()).getTileType() == "Mob_B1") {
		// Check what tile it is depending on that a certain mob will spawn
		Mob* mptr;
		mptr = new Mob();
		mptr->setHP(12.0);
		mptr->setDmg(2.5);
		mptr->setName("Trench Goblin");
		this->getTile(p.getCurrTile()).battleEvent(p, b, mptr);
	}
	else if (this->getTile(p.getCurrTile()).getTileType() == "Vendor") {
		v.entershop(p);
	}
	else if (this->getTile(p.getCurrTile()).getTileType() == "Item_Found") {
		string option;
		cout << "You enter the room and find a item on the floor do you pick it up? " << endl;
		cin >> option;
		if (option == "yes") {
			this->getTile(p.getCurrTile()).lootEvent(this->getTile(p.getCurrTile()).getItem(), p);
			this->getTile(p.getCurrTile()).setTileType("Item_Looted");
		}
	}
	else if (this->getTile(p.getCurrTile()).getTileType() == "Empty") {
		this->getTile(p.getCurrTile()).emptyTile(this->getTile(p.getCurrTile()).getMsg());
	}
	else if (this->getTile(p.getCurrTile()).getTileType() == "Boss") {
		Mob* mptr;
		mptr = new Mob();
		mptr->setName("BossBattle");
	}
	else if (this->getTile(p.getCurrTile()).getTileType() == "Item_Looted") {
		cout << "Floor has already been looted" << endl;
	}
}

Tile TileSystem::getTile(int t) {
	Tile tr;
	for (int i = 0; i <= this->tileMap.size() - 1; i++) {
		if (t == i) {
			tr = this->getTileMap()[i];
		}
	}
	return tr;
}