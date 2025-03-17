#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &numbers, int number, int left, int right) {
    if (left > right) return -1;
    int middle = left + (right - left) / 2;
    if (numbers[middle] == number) {
        return middle + 1;
    } else if (numbers[middle] < number) {
        return binary_search(numbers, number, middle + 1, right);
    }
    else {
        return binary_search(numbers, number, left, middle - 1);
    }
}

int get_pos(const std::vector<int> &numbers, int number) {
    return binary_search(numbers, number, 0, numbers.size()-1);
}

int main(void) {
  size_t number_count;
  std::cin >> number_count;
  std::vector<int> numbers(number_count);
  for (size_t i = 0; i < number_count; i++) {
    std::cin >> numbers[i];
  }

  size_t query_count;
  std::cin >> query_count;
  while (query_count-- > 0) {
    int number;
    std::cin >> number;
    std::cout << get_pos(numbers, number) << " ";
  }
  std::cout << std::endl;
}