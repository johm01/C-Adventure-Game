#pragma once
#include <string>

using namespace std;

class Item {
	private:
		string name;
		string description;
		float manaBuff;
		float hpBuff;
		int goldCost;
		float dmgBuff;

	public:
		Item(string n, string d, float m, float hp,int g, float b);
		Item() = default;
		string getName() { return this->name; };
		void setName(const string n) { this->name = n; };
		string getDescript() { return this->description; };
		void setDescript(const string desc) { this->description = desc; };
		float getManabuff() { return this->manaBuff; };
		void setManabuff(float mb) { this->manaBuff = mb; };
		int getGoldBuff() { return this->goldCost; };
		void setGoldBuff(int gb) { this->goldCost = gb; };
		float getDmgBuff() { return this->dmgBuff; };
		void setDmgBuff(float db) { this->dmgBuff = db; };
};


Item::Item(string n,string d,float m, float h,int g,float b) {
	this->name = n;
	this->description = d;
	this->manaBuff = m;
	this->hpBuff = h;
	this->goldCost = g;
	this->dmgBuff = b;
}