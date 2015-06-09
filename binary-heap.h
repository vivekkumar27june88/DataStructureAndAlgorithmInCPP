#pragma once
#include <stdexcept>
#include "utils.h"

enum class BinaryHeapType { MIN_HEAP, MAX_HEAP };

template <typename T>
class BinaryHeap{

public:
    BinaryHeap();
    BinaryHeap(T arr[], int n);
    ~BinaryHeap();
    void HeapifyDown(int index);
    void HeapifyUp(int index);
	void ResizeBinaryHeap();
	void Insert(T data);
	T Delete();
	void Display();
	void Sort();

    inline int GetParentIndex(int index);
    inline int GetLeftChild(int index);
    inline int GetRightChild(int index);
	inline void SetHeapType(BinaryHeapType type);    

private:
    T* backingArr;
    int capacity;
    int size;
    BinaryHeapType type;
};


template <typename T>
BinaryHeap<T>::BinaryHeap() :  backingArr(nullptr), capacity(0), size(0),
	type(BinaryHeapType::MAX_HEAP) {

	backingArr = new T[10];
	capacity = 10;
}

template <typename T>
BinaryHeap<T>::BinaryHeap(T arr[],  int n) : BinaryHeap() {

	if(n < 1) {
		return;
	}

	capacity = n;
	backingArr = new T[capacity];
	for(int i = 0; i < n; ++i) {
		backingArr[i] = arr[i];
	}
	size = n;

	/*
	 * Leaf node always satisfy the heap property and do not need to care for
	 * them. The leaf elements are always at the end and to heapify the given
	 * array it should be enough if we heapify the non-leaf nodes. Now let us
	 * concentrate on finding the first non-leaf node. For this it is enough to
	 * find the parent of last element.
	 */
	int parentOfLastElem = GetParentIndex(size - 1);
	for(int i = parentOfLastElem; i >= 0; --i) {
		HeapifyDown(i);
	}
}

template <typename T>
BinaryHeap<T>::~BinaryHeap() {

    if(backingArr != nullptr) {
        delete[] backingArr;
        backingArr = nullptr;
    }
    capacity = 0;
    size = 0;
}

template <typename T>
void BinaryHeap<T>::HeapifyDown(int index) {

    if(index < 0 || index > (size - 1)) {
        return;
    }

    int left = -1;
    try {
        left = GetLeftChild(index);
    }
    catch(const std::exception& e) {
   		left = -1; 
    }

	if(left < 0 || left >= size) {
		left = -1;
	}

    int right = -1;
    try {
        right = GetRightChild(index);
    }
    catch(const std::exception& e) {
        right = -1;
    }

	if(right < 0 || right >= size) {
		right = -1;
	}

    int swapIndex = -1;

    if(type == BinaryHeapType::MAX_HEAP) {
        if(left != -1 && backingArr[left] > backingArr[index]) {
            swapIndex = left;
        }
        else {
            swapIndex = index;
        }

        if(right != -1 && backingArr[right] > backingArr[swapIndex]) {
            swapIndex = right;
        }
    }
    else {
        if(left != -1 && backingArr[left] < backingArr[index]) {
            swapIndex = left;
        }
        else {
            swapIndex = index;
        }

        if(right != -1 && backingArr[right] < backingArr[swapIndex]) {
            swapIndex = right;
        }
    }

	if(swapIndex != index) {
		std::swap(backingArr[swapIndex], backingArr[index]);
		HeapifyDown(swapIndex);
	}
}

template <typename T>
void BinaryHeap<T>::HeapifyUp(int index) {

    if(index < 0 || index > (size - 1)) {
        throw std::exception();
    }


	int parentIndex = 0;
	try {
		parentIndex = GetParentIndex(index);
	}
	catch(const std::exception& e){
		parentIndex = -1;
	}

	while(parentIndex >= 0 && 
		((type == BinaryHeapType::MAX_HEAP && backingArr[index] > backingArr[parentIndex]) ||
		 (type == BinaryHeapType::MIN_HEAP && backingArr[index] < backingArr[parentIndex]))) {

		std::swap(backingArr[index], backingArr[parentIndex]);
		std::cout << "swapped" << backingArr[index] << " <==> " << backingArr[parentIndex] << std::endl;

		index = parentIndex;
		try {
			parentIndex = GetParentIndex(index);
		}
		catch(const std::exception& e){
			parentIndex = -1;
		}
	}		
}

template <typename T>
void BinaryHeap<T>::ResizeBinaryHeap() {

	T* oldBackingArr = backingArr;
	backingArr = new T[2* size];
	for(int i = 0; i < size; ++i) {
		backingArr[i] = oldBackingArr[i];
	}	
	capacity = 2 * size;

	delete [] oldBackingArr;
	oldBackingArr = nullptr;
}


template <typename T>
void BinaryHeap<T>::Insert(T data) {
	
	if(capacity == size) {
		ResizeBinaryHeap();
	}

	++size;
	backingArr[size - 1] = data;
	HeapifyUp(size - 1);	
}

template <typename T>
T BinaryHeap<T>::Delete(){

	T retVal = backingArr[0]; 
	backingArr[0] =	backingArr[size - 1];

	HeapifyDown(0);
}

template <typename T>
void BinaryHeap<T>::Display() {

	for(int i = 0; i < size; ++i) {
		std::cout << std::setw(5) << backingArr[i];
	}
	std::cout << std::endl;
}

template <typename T>
void BinaryHeap<T>::Sort() {

	int originalSize = size;
	for(int i = (size - 1); i >= 0; --i) {
		std::swap(backingArr[i], backingArr[0]);
		--size;
		HeapifyDown(0);
	}	
	size = originalSize;
}


template <typename T>
int BinaryHeap<T>::GetParentIndex(int index) {

    if(index < 0 || index > (size - 1)) {
        throw std::exception();
    }

    return (index - 1) / 2;
}


template <typename T>
int BinaryHeap<T>::GetLeftChild(int index) {

    if(index < 0 || index > (size - 1)) {
        throw std::exception();
    }

    return ((2 * index) +  1);
}


template <typename T>
int BinaryHeap<T>::GetRightChild(int index) {

    if(index < 0 || index > (size - 1)) {
        throw std::exception();
    }

    return ((2 * index) +  2);
}

template <typename T>
void BinaryHeap<T>::SetHeapType(BinaryHeapType type) {

	this->type = type;
}
