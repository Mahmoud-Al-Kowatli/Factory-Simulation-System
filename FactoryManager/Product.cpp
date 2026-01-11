#include "Product.h"

int Product::counter = 0;

unordered_map<int, Product> Product::productDatabase = {};

const Product Product::OFFICER_CHAIR = Product("Officer Chair", 100, {{Material::FABRIC, 2}, {Material::SCREW, 12}, {Material::METAL_FRAME, 1}});

const Product Product::WOODEN_DESK = Product("Wooden Desk", 80, {{Material::WOOD_PANELS, 3}, {Material::SCREW, 20}, {Material::METAL_FRAME, 1}, {Material::PAINT, 1}});

const Product Product::GAMING_DESK = Product("Gaming Desk", 200, {{Material::WOOD_PANELS, 2}, {Material::SCREW, 15}, {Material::LED_UNITS, 2}, {Material::METAL_FRAME, 1}});

const Product Product::BOOKSHELF = Product("Bookshelf", 70, {{Material::WOOD_PANELS, 5}, {Material::SCREW, 24}, {Material::METAL_FRAME, 1}, {Material::PAINT, 1}});

const Product Product::DRAWER_CABINET = Product("Drawer Cabient", 150, {{Material::WOOD_PANELS, 4}, {Material::SCREW, 16}, {Material::METAL_HANDLES, 4}, {Material::PAINT, 2}, {Material::METAL_FRAME, 1}});

Product::Product() : id(0), name(""), unitPrice(0) {}

Product::Product(string name, double unitPrice, vector<pair<Material, int>> requirements)
{
	id = ++counter;
	this->name = name;
	this->unitPrice = unitPrice;
	this->requirements = requirements;
	auto atd = [=](const Product &product)
	{
		productDatabase[product.getID()] = product;
	};
	atd(BOOKSHELF);
	atd(DRAWER_CABINET);
	atd(GAMING_DESK);
	atd(OFFICER_CHAIR);
	atd(WOODEN_DESK);
}

int Product::getID() const
{
	return id;
}

vector<pair<Material, int>> Product::getRequirements()
{
	return requirements;
}

double Product::getPrice() const
{
	return unitPrice;
}

Product Product::getProduct(int id)
{
	return productDatabase[id];
}
