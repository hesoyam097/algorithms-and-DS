#include <iostream>
#include <string>
#include <vector>

struct PriorityQueue {
    virtual void insert(int num) = 0;
    virtual int extract_max() = 0;
    virtual ~PriorityQueue() = default;
protected:
    virtual void sift_up(int index) = 0;
    virtual void sift_down(int index) = 0;
};

struct Heap : PriorityQueue {
    Heap(int n) {
        binary_tree.reserve(n);
    }

    void insert(int num) override {
        binary_tree.push_back(num);
        sift_up(binary_tree.size() - 1);
    }

    int extract_max() override {
        if (binary_tree.empty()) {
            throw std::runtime_error("Heap is empty!");
        }
        std::swap(binary_tree[0], binary_tree[binary_tree.size() - 1]);
        int ret = binary_tree.back();
        binary_tree.pop_back();
        if (!binary_tree.empty()) {
            sift_down(0);
        }
        return ret;
    }

    ~Heap() = default;

protected:
    std::vector<int> binary_tree;

    void sift_up(int index) override {
        while (index > 0 && binary_tree[index] > binary_tree[(index - 1) / 2]) {
            std::swap(binary_tree[index], binary_tree[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void sift_down(int index) override {
        int size = binary_tree.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && binary_tree[left] > binary_tree[largest]) {
                largest = left;
            }
            if (right < size && binary_tree[right] > binary_tree[largest]) {
                largest = right;
            }
            if (largest == index) break;

            std::swap(binary_tree[index], binary_tree[largest]);
            index = largest;
        }
    }
};

void parse_command(Heap* heap) {
    std::string command;
    std::cin >> command;
    
    if (command == "Insert") {
        int num;
        std::cin >> num;
        heap->insert(num);
    } 
    else if (command == "ExtractMax") {
        std::cout << heap->extract_max() << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); 

    Heap heap(n);
    for (int i = 0; i < n; ++i) {
        parse_command(&heap);
    }

    return 0;
}