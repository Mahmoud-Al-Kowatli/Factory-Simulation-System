#pragma once
#include "Libraries.h"

class Client
{
	static int counter;
	int id;
	string name;
	vector<int> orderHistoryIDs;
public:
	Client(string name);
};

