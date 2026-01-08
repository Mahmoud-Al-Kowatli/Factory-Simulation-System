#include "Material.h"

int Material::counter = 0;

Material::Material(string name, int quantity)
{
	id = ++counter;
	this->name = name;
	this->quantity = quantity;
}

int Material::getID() const
{
	return id;
}

string Material::getName()
{
	return name;
}

int Material::getQuantity() const 
{
	return quantity;
}
