#pragma once
#include"Libraries.h"
#include "Order.h"

void Order::calculateValue() {
	return;
}

bool Order::operator<(const Order& other) {
	return this->priority < other.priority;
}