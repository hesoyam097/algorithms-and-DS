#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int* arr, size_t left, size_t right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right ; ++j) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i + 1;
}

void quick_sort(int* arr, size_t left, size_t right) {
    if (left < right) {
        int q = partition(arr, left, right);
        if (q > left) {
            quick_sort(arr, left, q - 1);
        }
        if (q < right) {
            quick_sort(arr, q + 1, right);
        }
    }
}

void arr_print(int* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    int* arr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    quick_sort(arr, 0, size - 1);
    arr_print(arr, size);
    delete[] arr;
    return 0;
}