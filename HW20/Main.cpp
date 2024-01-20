#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

void print_arr(int arr[], const int length);
template <typename T>
void fill_arr(T arr[], const int length, int left, int right);
int search_last_index(int arr[], const int length, int last);
int search_last_index(int arr[], const int length, int last, int pos);
int arr_min(int arr[], const int length);
int arr_max(int arr[], const int length);
int mean_value(int arr[], const int length);
void range(int arr[], const int length, int left, int right);
int count(int arr[], const int length, int num);
void sort_arr(int arr[], const int length);
int search_index(int arr[], const int length, int pos) {
	for (int i = 0; i < length; i++)
		if (arr[i] == pos)
			return i;
	return -1;
}

int main() {
	setlocale(0, "");
	int n;

	const int size = 20;
	int arr[size]{};
	fill_arr(arr, size, -50, 50);
	std::cout << "Массив:" << std::endl;
	print_arr(arr, size);
	std::cout << "Индекс первого вхождения -> " << search_index(arr, size, 23) << std::endl;
	std::cout << "Индекс последнего вхождения -> " << search_last_index(arr, size, 1) << std::endl;
	std::cout << "Индекс последнего вхождения с определенной позиции -> " << search_last_index(arr, size, 13, 5) << std::endl;
	std::cout << "Минимальное значение в массиве -> " << arr_min(arr, size) << std::endl;
	std::cout << "Максимальное значение в массиве -> " << arr_max(arr, size) << std::endl;
	std::cout << "Среднее арифметическое массива -> " << mean_value(arr, size) << std::endl;
	std::cout << "Элементы в заданом диапазоне -> ";
	range(arr, size, -10, 20);
	std::cout << "Кол-во вхождений элемента в массив -> " << count(arr, size, 8) << std::endl;
	std::cout << "Отсортированный массив:\n";
	sort_arr(arr, size);
	print_arr(arr, size);


	return 0;
}


void print_arr(int arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << " }" << std::endl;
}
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (right + 1 - left) + left;
	}
}

int search_last_index(int arr[], const int length, int last) {
	for (int i = length; i >= 0; i--) {
		if (arr[i] == last)
			return i; 
	}
	return -1;
}

int search_last_index(int arr[], const int length, int last, int pos) {
	for (int i = pos; i >= 0; i--) {
		if (arr[i] == last)
			return i;
	}
	return -1;
}

int arr_min(int arr[], const int length) {
	int min = 50;
	for (int i = 0; i < length; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
int arr_max(int arr[], const int length) {
	int max = -50;
	for (int i = 0; i < length; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int mean_value(int arr[], const int length) {
	int sum = arr[0];
	for (int i = 1; i < length; i++) {
		sum += arr[i];
	}
	return sum / length;
}

void range(int arr[],const int length, int left, int right) {
	for (int i = 0; i < length; i++) {
		if (arr[i] > left && arr[i] < right)
			std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int count(int arr[], const int length, int num) {
	int counter = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == num)
			counter++;
	return counter;
}

void sort_arr(int arr[], const int length) {
	for (int i = length - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}