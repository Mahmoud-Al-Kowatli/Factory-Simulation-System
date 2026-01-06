#pragma once
#include "Libraries.h"

class Order
{
	int id;
	int priority;
	time_t arrivalTime;
	int requiredQuantity;
	int clientID;
	int productID;
	double totalValue;
public:
	int calculateValue();
	bool operator<(Order other);
};

