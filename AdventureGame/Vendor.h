#pragma once

#include <vector>
#include <string>
#include "Item.h"
#include "Player.h"
#include <iostream>

using namespace std;

class Vendor {
	public:
		void entershop(Player ps);
		void addItem(Item item);
		void removeItem(Item item);
		vector<Item> getShop() { return this->Shop; };
		Item getItem(const string i);

	private:
		vector<Item> Shop;
};

void Vendor::addItem(Item item) {
	this->Shop.push_back(item);
}

void Vendor::removeItem(Item item) {
	for (int i = 0; i <= this->Shop.size() - 1; i++) {
		if (item.getName() == this->Shop[i].getName()) {
			this->Shop.erase(this->Shop.begin() + i);
		}
	}
}

Item Vendor::getItem(const string item) {
	Item item2give;
	for (int i = 0; i <= this->Shop.size() - 1; i++) {
		if (item == this->Shop[i].getName()) {
			item2give = this->Shop[i];
		}
	}
	return item2give;
}

void Vendor::entershop(Player p) {

	cout << "Welcome to my shop of trinkets and doodads" << endl;
	cout << endl;
	for (int i = 0; i <= this->Shop.size() - 1; i++) {
		cout << this->Shop[i].getName() << endl;
		cout << this->Shop[i].getDescript() << endl;
		cout << this->Shop[i].getDmgBuff() << endl;
		cout << "-------------------------------------------------------" << endl;
		
	}

	string buySell;
	string item2mod;

	cout << "Would you like to sell or buy stranger? ";
	cin >> buySell;

	if (buySell == "buy") {
		cout << "Please enter the item you would like to buy: ";
		cin >> item2mod;
		Item item2add;
		
		item2add = this->getItem(item2mod);
		if (item2add.getGoldBuff() > p.getGold()) {
			cout << "Not enough gold comeback later" << endl;
			this->entershop(p);
		}
		else {
			p.addItem(item2add);
			this->removeItem(item2add);
			for (int i = 0; i <= p.getInventory().size() - 1; i++) {
				cout << p.getInventory()[i].getName() << endl;
			}
			this->entershop(p);
		}
	}
	else if (buySell == "sell") {

		// TODO: Check if item wanted to be sold does exist

		cout << "Please enter the item you would like to sell: ";
		cin >> item2mod;

		Item item2sell;

		item2sell = p.getItem(item2mod);
		this->Shop.push_back(item2sell);
		p.setGold(p.getGold() + item2sell.getGoldBuff());
		cout << p.getItem(item2mod).getGoldBuff() << endl;
		p.removeItem(item2mod);
		cout << "Player gold:" << p.getGold() << endl;;
		this->entershop(p);
	}
}