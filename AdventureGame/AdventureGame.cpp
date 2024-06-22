#include <iostream>
#include "Player.h"
#include "Mob.h"
#include "Vendor.h"
#include "Item.h"
#include "Tile.h"
#include "TileSystem.h"
#include "set"
#include "BattleSystem.h"


// Ultil functions to fuck with
template <typename T> T getItem(vector<T> v, const string n) {
	T item;
	for (int i = 0; i <= v.size() - 1; i++) {
		if (n == v[i].getName()) {
			item = v[i];
		}
	}
	return item;
}

int main()
{

	set<string> aval_classes;
	aval_classes = { "Warrior", "Wizard" };

	Vendor v;

	// Vendor items and Vendor class 
	Item i1("Blood_Sword", "Cursed sword with magical properties,takes the life of the user boosting their dmg", 0.0, 0.0, 45, 0.0);
	Item i2("Acient_Book", "An acient book that holds magic only powerful wizards can harness", 0.0, 0.0, 45, 0.0);
	Item i3("Golden Goblet", "A goblet that appears to be made from pure gold", 0.0, 0.0, 15, 0.0);

	v.addItem(i1);
	v.addItem(i2);
	v.addItem(i3);

	// Creating global vars 
	BattleSystem bls(false);
	Player mainP(" ", " ");
	mainP.setHP(12.0);
	mainP.setDmg(6.0);
	bool run = true;
	bool startGame;
	startGame = false;
	Item placeHold;
	// Creating Tile system vars 
	// TILE INDEX: Tile name("TileType",Explored,FloorText,ItemOnFloor)
	TileSystem ts;
	Tile t1("Mob_B1", false, "", placeHold);
	Tile t2("Vendor", false, "", placeHold);
	Tile t3("Item_Found", false, "", placeHold);
	Tile t4("Mob_B1", false, "", placeHold);
	Tile t5("Empty", false, "Nothing on this floor keep moving on", placeHold);
	Tile t6("Empty", false, "Nothing on this floor but above you are feint footsteps what could it be ?", placeHold);
	Tile t7("Mob_B1", false, "", placeHold);
	ts.addTile(t1);
	ts.addTile(t2);
	ts.addTile(t3);
	ts.addTile(t4);
	ts.addTile(t5);
	ts.addTile(t6);
	ts.addTile(t7);

	// Main Game Loop
	while (run) {
		if (startGame) {

			// print player stats
			cout << "Player stats" << endl;
			cout << "HP: " << mainP.getHP() << endl;
			cout << "Gold: " << mainP.getGold() << endl;
			cout << "Dmg: " << mainP.getDmg() << endl;

			cout << endl;


			cout << "Would you like to move to the next floor ?" << endl;
			cout << "Floor Num: " << mainP.getCurrTile() << endl;

			string move;
			cin >> move;

			if (move == "Up") {
				ts.MapLogic(mainP, bls, v);
				ts.getTile(mainP.getCurrTile()).setFound(true);
				mainP.setCurrTile(mainP.getCurrTile() + 1);
				cout << "Floor Num: " << mainP.getCurrTile() << endl;
				ts.drawTileMap();
			}
			else if (move == "Down") {
				mainP.setCurrTile(mainP.getCurrTile() - 1);
				ts.MapLogic(mainP, bls, v);
				ts.getTile(mainP.getCurrTile()).setFound(true);
				cout << "Floor Num: " << mainP.getCurrTile() << endl;
				ts.drawTileMap();
			}

		}
		else {

			// Creating player
			// TODO Add wether or not we want to load a character or create a character 
			string name;
			string spec;
			cout << "Welcome to my adventure game please enter name and class you want you can pick between Wizard and a Warrior" << endl;
			cout << "Enter Name: ";
			cin >> name;
			cout << endl;
			cout << "Enter Class: ";
			cin >> spec;
			cout << endl;
			auto ps = aval_classes.find(spec);

			if (ps != aval_classes.end()) {
					cout << "You wake up in a dungeon with nothing on but prison garbs, you find that the cell block is open" << endl;
					cout << "Lies next to you is a skeleton with a prison guard outfit on with a map in his pocket you check said map" << endl;
					cout << "You find out you are in a dungeon inside of a tower with 25 floors, as you are checking your map you start coughing blood" << endl;
					cout << "Visons appear in your head of a man wearing a dark wizard outfit calling to you that you will eventually become his pawn" << endl;
					cout << "Once the diease takes over your mind, you see this man and realize he is at the top of a tower and he realize that" << endl;
					cout << "Your only oppertunity to get rid of this disease you must climb the tower and defeat the dark wizard standing at the top " << endl;
					cout << "Or else you will perish" << endl;

					// Setting name and player class 
					mainP.setCharClass(spec);
					mainP.setName(name);
					startGame = true;
				}
				else {
					cout << "Invalid class !" << endl;
				}
			}
		}
	return 0;
}


