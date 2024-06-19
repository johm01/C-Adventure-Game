#pragma once

#include "Move.h"
#include "Player.h"
#include "Mob.h"
#include <stdlib.h>

using namespace std;

class BattleSystem {
	private:
		bool battleDone;
		bool playerDead;
		bool mobDead;
		void endBattle(Player p, Mob* m);
		bool speedCheck(Player p, Mob* m);
		int turn; 

	public:
		BattleSystem(bool s) { this->battleDone = s; };
		void battle(Player p, Mob* m);
		void bossBattle(Player p, Mob* m);
		bool isBattleDone() { return this->battleDone; };
		
};

// Checking who won the battle 
void BattleSystem::endBattle(Player p, Mob* m) {
	if (m->getHP() <= 0.0) {
		cout << "Player has won" << endl;
		p.setGold(p.getGold() + 5);
		this->battleDone = true;
		delete m;
	}
	
	// Do xp calc when player wins 
	if (p.getHP() <= 0.0) {
		// TODO: When player dies subtract what tile they are -1 
		p.setCurrTile(p.getCurrTile() + 1);
		cout << "Player is dead returning to previous tile";
	}
}

bool BattleSystem::speedCheck(Player p, Mob* m) {
	if (p.getSpeed() >= m->getSpeed()) {
		return true;
	}
	else {
		return false;
	}
}

void BattleSystem::bossBattle(Player p, Mob* m) {
	cout << "So you have finally made it upstairs huh?" << endl; 

}

void BattleSystem::battle(Player p, Mob* m) {
	cout << "You have found an enemy what shall you do?" << endl;

	cout << "Player HP" << p.getHP() << " | ";
	cout << "Enemy HP" << m->getHP() << endl;

	for (int i = 0; i <= p.getMoves().size() - 1; i++) {
		cout << p.getMoves()[i].getName() << endl;
	}

	// Perform a player speed check
	bool sCheck = this->speedCheck(p, m);
	if((p.getHP() > 0.0 && m->getHP() > 0.0)){
		this->turn = this->turn + 1;
		cout << "Please enter a move: ";
		string moveSelected;
		cin >> moveSelected;
		// if player is faster then mob
		if (sCheck == true) {
			cout << "It is player ones turn" << endl;
			Move currM;
			currM = p.getMove(moveSelected);
			if (currM.getName() == "Heal") {
				p.addHP(2.0);
			}
			else {
				m->subHP(currM.getFloatMod());
			}

			p.setGold(p.getGold() + 5);

			// TODO Program Enemy turn 
			cout << "Enemy does " << m->getDmg() << "dmg" << endl;
			p.subHP(m->getDmg());

			this->battle(p, m);

		}
		// if mob is faster then player then mob goes first 
		else {
			cout << "Enemy does " << m->getDmg() << "dmg" << endl;
			p.subHP(m->getDmg());

			cout << "It is player ones turn" << endl;
			Move currM;
			currM = p.getMove(moveSelected);
			if (currM.getName() == "heal") {
				p.addHP(2.0);
			}
			else {
				m->subHP(currM.getFloatMod());
			}
		}
	}
	else if(m->getHP() < 0.0){
		this->endBattle(p, m);
	}
}

