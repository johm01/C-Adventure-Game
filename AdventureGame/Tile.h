#pragma once
#include <vector>
#include <string>
#include "Tile.h"
#include "Mob.h"
#include "Vendor.h"
#include "Item.h"
#include "BattleSystem.h"
#include "Player.h"

using namespace std;

class Tile {
	public:
		
		// Leave for now, used for tile map testing 
		Tile(string type, bool f, string tm, Item ti) { this->tileType = type; this->tileFound = f; this->tileMsg = tm; this->tileItem = ti; };
		Tile() = default;

		bool getFound() { return this->tileFound; };
		string getTileIcon();
		void vendorEvent(Vendor v);
		void bossEvent();
		void lootEvent(Item i,Player p);
		void setFound(bool b) {  this->tileFound = b; };
		void battleEvent(Player p, BattleSystem bs,Mob* m);
		string getTileType() { return this->tileType; };
		void setTileType(string t) { this->tileType = t; };
		void emptyTile(string msg);
		string getMsg() { return this->tileMsg; };
		Item getItem() { return this->tileItem; };

	private:
		string tileName;
		string tileType;
		string tileMsg;
		Item tileItem;
		bool tileFound;

};

void Tile::battleEvent(Player p, BattleSystem b,Mob* m) {
	if(this->getTileType() == "Mob_B1") {
		b.battle(p,m);
	}
}

void Tile::vendorEvent(Vendor v) {

}

void Tile::lootEvent(Item i,Player p) {
	// if item isnt a place holder item add it to the players inventory
	if (i.getName() != "NULL") {
		p.addItem(i);
	}
}

void Tile::bossEvent() {

}

void Tile::emptyTile(string msg) {
	cout << msg << endl;
}

string Tile::getTileIcon() {
	if (this->tileFound == true) {
		return "y";
	}
	else if(this->tileFound == false){
		return "0";
	}
}
