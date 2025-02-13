#include <iostream>

void merge(int* arr, int p, int q, int r) {
    size_t n1 = q - p + 1;
    size_t n2 = r - q;
    int* left_arr = new int[n1 + 1];
    int* right_arr = new int[n2 + 1];
    for (size_t i = 0; i < n1; ++i) {
        left_arr[i] = arr[p + i];
    }
    for (size_t j = 0; j < n2; ++j) {
        right_arr[j] = arr[q + 1 + j]; 
    }
    left_arr[n1] = __INT32_MAX__;
    right_arr[n2] = __INT32_MAX__;
    size_t i = 0, j = 0;
    for (size_t k = p; k <= r; ++k) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
    }
    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(int* arr, size_t p, size_t r) {
    if (p < r) {
        size_t q =  p + (r - p) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
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
    merge_sort(arr, 0, size - 1);
    arr_print(arr, size);
    delete[] arr;
    return 0;
}