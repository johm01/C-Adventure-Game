#pragma once
#include <string>
#include "Move.h"
#include <random>

// TODO: Create battle logic for Mob

using namespace std;

class Mob {
	private:
		string name;
		float dmg;
		float speed;
		vector<Move> Moves;
		double hp;
		double maxHp;
		bool canHeal;

	public:

		Mob(const string n, float d, float s);
		Mob() = default;
		string getName() { return this->name; };
		void setName(const string n) { this->name = n; };
		float getDmg() { return this->dmg; };
		void setDmg(float d) { this->dmg = d; };
		float getSpeed() { return this->speed; };
		void setSpeed(float s) { this->speed = s; };
		Move getMove(const string m);
		vector<Move> getMoves() { return this->Moves; };
		double getHP() { return this->hp; };
		void setHP(double HP) { this->hp = HP; };
		void subHP(double shp);
		double getMax() { return this->maxHp; };
		Move mobLogic (vector<Move> vm, Player p,int turn);
		bool getCanHeal() { return this->canHeal; }
		void setCanHeal(bool ch) { this->canHeal = ch; };
		bool MobHPCheck();

};

Mob::Mob(const string n, float d, float s) {
	this->name = n;
	this->dmg = d;
	this->speed = s;
}

Move Mob::getMove(const string m) {
	Move n;
	for (int i = 0; i < this->Moves.size(); i++) {
		if (m == this->getMoves()[i].getName()) {
			n = this->getMove(m);
		}
	}
	return n;
}


void Mob::subHP(double shp) {
	this->hp -= shp;
}

// Logic to determine wether or not the mob can heal 
bool Mob::MobHPCheck() {
	if (this->getHP() >= this->getMax() * .25) {
		return false;

	}
	else if (this->getHP() <= this->getMax() * .25) {
		return true;
	}
}

Move Mob::mobLogic(vector<Move> vm,Player p,int turn) {
	if (this->MobHPCheck() && turn >= 3) {
		return this->getMove("Heal");
	}
	else{
		// TODO: Return a random attack every time
		return this->getMove("Attack");
	}
}

class Boss : public Mob {
	public:
		void bossLogic();
};

void Boss::bossLogic() {

}