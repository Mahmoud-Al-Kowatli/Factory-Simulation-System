#pragma once
#include "Libraries.h"

class Material
{
	int id;
	string name;
	int quantity;
	static int counter;
	static unordered_map<int, Material> materialDatabase;

public:
	Material();
	Material(string name, int quantity);
	int getID() const;
	string getName();
	int getQuantity() const;
	void setQuantity(int quantity);
	static Material getMaterial(int id);
	static void registerMaterial(const Material& material);
	static const Material SCREW;
	static const Material METAL_FRAME;
	static const Material FABRIC;
	static const Material WOOD_PANELS;
	static const Material LED_UNITS;
	static const Material METAL_HANDLES;
	static const Material PAINT;
};

