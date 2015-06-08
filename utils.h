#pragma once
#include <iostream>
#include <iomanip>


template<typename T, std::size_t N>
void PrintArray(T (&arr)[N], int width = 5) {

	for(auto const& item : arr) {
		std::cout << std::setw(width) << item;
	}
	std::cout << std::endl;
}
