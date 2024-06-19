#pragma once

#include <string>

using namespace std;

class Move {
	private:
		string name;
		string moveType;
		float floatMod;
		int intMod;

	public:
		Move(string n, string mt, float fm, int im) 
		{ this->name = n; this->moveType = mt; 											
		this->floatMod = fm; this->intMod = im; };

		Move() = default;

		string getName() { return this->name; };
		void setName(const string n) { this->name = n; }; 
		void setMoveType(string mt) { this->moveType = mt; };
		float getFloatMod() { return this->floatMod; };
		void setFloatMod(float fm) { this->floatMod = fm; };
		int getIntMod() { return this->intMod; };
		void setIntMod(int im) { this->intMod = im; };
		string getMoveType();
};

string Move::getMoveType() {
	return this->moveType;
}