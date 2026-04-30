#pragma once
#include <iostream>
#include <list>
#include <stdexcept>
using namespace std;
void removeEvenOrThrow(std::list<int>& lst) {
	for (int x : lst) {
		if (x < 0) {
			throw std::domain_error("Negative number found");
		}
	}
	for (auto it = lst.begin(); it != lst.end();) {
		if (*it % 2 == 0) {
			it = lst.erase(it);
		}
		else {
			++it;
		}
	}
}