#include "Product.h"
#include"User.h"
#include"Libraries.h"
#include "WarehouseManager.h"

int main()
{
	WarehouseManager m;
	Order o(Order::Priority::NORMAL, 3, Product::OFFICER_CHAIR);
	m.addMaterial(Material::FABRIC);
	m.addMaterial(Material::SCREW);
	m.addMaterial(Material::METAL_FRAME);
	cout << boolalpha << m.consumeMaterialsForOrder(o);
}
