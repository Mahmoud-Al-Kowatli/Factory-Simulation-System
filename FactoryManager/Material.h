#pragma once
#include "Libraries.h"

class Material
{
	int id;
	string name;
	int quantity;
	static int counter;
	Material(string name, int quantity);

public:
	int getID() const;
	string getName();
	int getQuantity() const;
	void setQuantity(int quantity);
	static const Material SCREW;
	static const Material METAL_FRAME;
	static const Material FABRIC;
	static const Material WOOD_PANELS;
	static const Material LED_UNITS;
	static const Material METAL_HANDLES;
	static const Material PAINT;
};

