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
	std::cout << "bh is ";
	bh.Display();

	int arr[5] = {1, 2, 3, 4, 5};
	PrintArray(arr);
	BinaryHeap<int> bt2(arr, 5);
	bt2.Display();

	return 0;
}
