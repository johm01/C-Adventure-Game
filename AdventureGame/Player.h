#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "Move.h"

using namespace std;

class Player{

	private:
		float hp;
		int gold;
		string name;
		string charClass;
		float mana;
		float manaMod;
		float dmg;
		float dmgMod;
		float speed;
		float speedMod;
		int currentTile;
		vector<Item> inventory;
		vector<Move> Moves;
		vector<int> tilesFound;
		double maxHp;

	public:
		Player(string n, string c);
		Player() = default;

		// Use deconstructer to save data

		void setMax(double max) { this->maxHp = max; };
		int getMax() { return this->maxHp; };
		vector<Move> getMoves() { return this->Moves; };
		Move getMove(string m);

		void setCurrTile(int n) { this->currentTile = n; };
		int getCurrTile() { return this->currentTile; };

		// Player stats 
		int getGold() { return this->gold; };
		void setGold(int g) { this->gold = g; };

		float getHP() { return this->hp; };
		void setHP(float h) { this->hp = h; };

		string getName() { return this->name; };
		void setName(const string n) { this->name = n; };

		float getMana() { return this->mana; };
		void setMana(float m) { this->mana = m; };

		float getDmg() { return this->dmg; };
		void setDmg(float d) { this->dmg = d; };

		float getSpeed() { return this->speed; };
		void setSpeed(float s) { this->speed = s; };

		// Inventory Modification 
		void removeItem(const string item);
		void addItem(Item i);
		void setCharClass(string c);
		void subHP(float shp);
		void addHP(float shp);

		// Item Buffs
		void addBuffs();
		void removeBuffs();
		Item getItem(const string item);
		vector<Item> getInventory() { return this->inventory; };
};

void Player::subHP(float shp) {
	this->hp = shp;
}

void Player::addHP(float shp) {
	this->hp += shp;
}

void Player::setCharClass(string c) {
	this->charClass = c;
	if (this->charClass == "Warrior") {
		Move warAttack("Warrior_Attack", "Attack", 6.0, 0);
		Item i6("Sword", "Basic sword for a warrior", 0.0, 0.0, 5, 0.0);
		this->inventory.push_back(i6);
		this->Moves.push_back(warAttack);
		this->maxHp = 12.0;

	}
	else if (this->charClass == "Mage") {
		Move wizAttack("Wizard_Attack", "Attack", 7.0, 0);
		Item i7("Basic Wand", "A basic wizard wand with no power", 0.0, 0.0, 5, 0.0);
		this->inventory.push_back(i7);
		this->Moves.push_back(wizAttack);
		this->maxHp = 10.0;
	}

	Move regAttack("AttackOne", "Attack", 3.0, 0);
	Move heal("Heal", "Healing", 2.0, 0);

	this->Moves.push_back(heal);
	this->Moves.push_back(regAttack);
}


Player::Player(string cn,string cc){
	this->name = cn;
	this->charClass = cc;
	this->currentTile = 0;
}

void Player::addItem(Item item) {
	this->inventory.push_back(item);
}

void Player::removeItem(string const  item) {
	for (int i = 0; i <= this->inventory.size() - 1; i++) {
		if (item == this->inventory[i].getName()) {
			this->inventory.erase(this->inventory.begin()+i);
		}
	}
}

Move Player::getMove(string m) {
	Move ms;
	for (int i = 0; i < this->getMoves().size(); i++) {
		if (m == this->getMoves()[i].getName()) {
			ms = this->getMoves()[i];
			cout << ms.getMoveType();
		}
	}
	return ms;
}

Item Player::getItem(const string m) {
	Item ms;
	for (int i = 0; i <= this->inventory.size() - 1; i++) {
		if (m == this->inventory[i].getName()) {
			ms = this->inventory[i];
		}
	}
	return ms;
}