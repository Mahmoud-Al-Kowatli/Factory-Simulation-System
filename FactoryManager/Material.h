#pragma once
#include "Libraries.h"

class Material
{
	int id;
	string name;
	int quantity;
	static int counter;

public:
	Material(string name, int quantity);
	int getID() const;
	string getName();
	int getQuantity() const;
};

