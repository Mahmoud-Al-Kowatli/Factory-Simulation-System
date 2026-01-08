#include "Product.h"

int Product::counter = 0;

Product::Product() : id(0), name(""), unitPrice(0.0) {}

Product::Product(string name, double unitPrice, vector<pair<int, int>> requirements)
{
	id = ++counter;
	this->name = name;
	this->unitPrice = unitPrice;
	this->requirements = requirements;
}

int Product::getID() const
{
	return id;
}

vector<pair<int, int>> Product::getRequirements()
{
	return requirements;
}

double Product::getPrice() const
{
	return unitPrice;
}

