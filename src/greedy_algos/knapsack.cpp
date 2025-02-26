#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>


struct Item final {
    int weight;
    int value;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
    double value = 0.0;

    for (auto &item:items) {
        if (capacity > item.weight) {
            capacity -= item.weight;
            value += item.value;
        } 
        else {
            value += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}

int main(void) {
    int number_of_items;
    int knapsack_capacity;
    std::cin >> number_of_items >> knapsack_capacity;
    std::vector <Item> items(number_of_items);
    for (int i = 0; i < number_of_items; i++) {
        std::cin >> items[i].value >> items[i].weight;
    }

    struct
    {
        bool operator()(Item a, Item b) const { return static_cast<double>(a.value)/a.weight > static_cast<double>(b.value)/b.weight; }
    }
    customGreater;

    std::sort(items.begin(), items.end(), customGreater); 
    
    for (const Item& i : items) {
        std::cout << i.value << " " << i.weight << std::endl;
    }
    
    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << max_knapsack_value << std::endl;
    return 0;
}