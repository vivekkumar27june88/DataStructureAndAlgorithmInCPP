#include <iostream>
#include <iomanip>


template <typename T, std::size_t N>
int partition(T (&arr)[N], int l, int r) {

	int p = l - 1;
	for(int j = l; j < r; ++j) {
		if(arr[j] <= arr[r]) {
			++p;
			std::swap(arr[p], arr[j]);
		}
	}
	std::swap(arr[p + 1], arr[r]);
	return (p + 1);
}


template <typename T, std::size_t N>
void quickSort(T (&arr)[N], int l, int r) {

	while(l < r) {
		int p = partition(arr, l, r);
		quickSort(arr, l, (p - 1));
		quickSort(arr, (p + 1), (r - 1));
	}
}

void driverProgramForQuickSort() {

	int arr1[11] = {13, 19, 9, 5, 12, 8, 4, 11, 2, 6, 21};
	
	std::cout << std::setw(20) << "original arr1 is : ";
	for(int i = 0; i < 11; ++i) {
		std::cout << std::setw(5) << arr1[i];
	}
	std::cout << std::endl;
	
	quickSort(arr1, 0,  11);

	std::cout << std::setw(20) << "original arr1 is : ";
	for(int i = 0; i < 11; ++i) {
		std::cout << std::setw(5) << arr1[i];
	}
	std::cout << std::endl;
}


