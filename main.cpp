#include <iostream>

// Data Structure
#include "binary-heap.h"
// Sorting


int main(int argc, const char* argv[]) {

	BinaryHeap<int> bh;
	bh.SetHeapType(BinaryHeapType::MIN_HEAP);
	bh.Insert(31);
	bh.Insert(12);
	bh.Insert(10);
	bh.Insert(8);
	bh.Insert(9);
	bh.Insert(3);
	bh.Insert(7);
	bh.Insert(12);
	std::cout << std::setw(30) << "bh is ";
	bh.Display();
	bh.Sort();
	std::cout << std::setw(30) << "sorted bh is : ";
	bh.Display();
	std::cout << std::endl << std::endl;

	int arr[5] = {1, 2, 3, 4, 5};
	std::cout << std::setw(30) << "arr is : ";
	PrintArray(arr);
	BinaryHeap<int> bt2(arr, 5);
	std::cout << std::setw(30) << "bt2 is : ";
	bt2.Display();
	bt2.Sort();
	std::cout << std::setw(30) << "sorted bt2 is : ";
	bt2.Display();

	return 0;
}
