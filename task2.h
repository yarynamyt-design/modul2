#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;
struct Order {
    string product;
    int quantity;
};

map<string, int> loadWarehouse(const string& filename);
void processOrders(map<string, int>& warehouse, queue<Order>& orders);
void saveToCSV(const map<string, int>& warehouse, const string& filename);
