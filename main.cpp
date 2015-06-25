#include <iostream>

// Data Structure
#include "binary-heap.h"
#include "graph.h"
// Sorting
#include "quick-sort.h"

int main(int argc, const char* argv[]) {
	
	driverProgramForQuickSort(); return 0;

	GraphUsingAdjMat<int> adjMat(6);
	adjMat.addEdge(0, 1);
	adjMat.addEdge(0, 3);
	adjMat.addEdge(1, 4);
	adjMat.addEdge(2, 4);
	adjMat.addEdge(2, 5);
	adjMat.addEdge(3, 1);
	adjMat.addEdge(4, 3);
	adjMat.addEdge(5, 5);
	
	std::cout << "Adjacency Matrix" << std::endl;
	for(int i = -1; i < adjMat.getVerticesCount(); ++i) {
		std::cout << std::setw(10) << "__________";
	}
	std::cout << std::endl;
	for(int i = -1; i < adjMat.getVerticesCount(); ++i) {
		std::cout << std::setw(5) << i << std::setw(5) << "|";
	}
	std::cout << std::endl;
	for(int i = -1; i < adjMat.getVerticesCount(); ++i) {
		std::cout << std::setw(10) << "__________";
	}
	std::cout << std::endl << std::endl;
	for(int r = 0; r < adjMat.getVerticesCount(); ++r) {
		for(int c = 0; c < adjMat.getVerticesCount(); ++c) {
			if(c == 0) {
				std::cout << std::setw(5) << r << std::setw(5) << "|";
			}
			std::cout << std::setw(5) << adjMat.hasEdge(r, c) << std::setw(5) << "|";
		}
		std::cout << std::endl;
	}	
	for(int i = -1; i < adjMat.getVerticesCount(); ++i) {
		std::cout << std::setw(10) << "__________";
	}
	std::cout << std::endl << std::endl;;
	std::list<int> inEdges = adjMat.inEdges(1);
	std::cout << "In edges are : ";
	for(const int& i : inEdges) {
		std::cout << std::setw(5) << i;
	}
	std::cout << std::endl;

	return 0;

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
