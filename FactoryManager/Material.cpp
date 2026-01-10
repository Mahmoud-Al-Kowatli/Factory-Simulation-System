#include "Material.h"

int Material::counter = 0;

unordered_map<int, Material> Material::materialDatabase = {};

const Material Material::SCREW = Material("Screw", 30);

const Material Material::METAL_FRAME = Material("Metal Frame", 30);

const Material Material::FABRIC = Material("Fabric", 10);

const Material Material::WOOD_PANELS = Material("Wood Panels", 10);

const Material Material::LED_UNITS = Material("RGB Units", 20);

const Material Material::METAL_HANDLES = Material("Metal Handles", 10);

const Material Material::PAINT = Material("Paint", 4);

Material::Material() : id(0), name(""), quantity(0) {}

Material::Material(string name, int quantity)
{
	id = ++counter;
	this->name = name;
	this->quantity = quantity;
	auto atd = [=](const Material& material) {
		materialDatabase[material.getID()] = material;
	};
	atd(FABRIC);
	atd(LED_UNITS);
	atd(METAL_FRAME);
	atd(METAL_HANDLES);
	atd(PAINT);
	atd(SCREW);
	atd(WOOD_PANELS);
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

void Material::setQuantity(int quantity)
{
	this->quantity = quantity;
}

Material Material::getMaterial(int id)
{
	return materialDatabase[id];
}
