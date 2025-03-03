#include <iostream>
#include <string>


struct PriorityQueue {
    virtual void insert(int num) = 0;
    virtual int extract_max() = 0;
protected:
    virtual void sift_up() = 0;
    virtual void sift_down() = 0;
};

struct Heap : PriorityQueue {
    void insert(int num) override {

    }

    int extract_max() override {

    }
protected:
    void sift_up() override {}
    void sift_down() override {}
};


void parse_command(Heap* heap) {
    std::string command;
    int num;
    std::getline(std::cin, command);
    if (command.compare("Insert")) {
        std::cin >> num;
        heap->insert(num);        
    }
    else if (command.compare("ExtractMax")) {
        std::cout << heap->extract_max() << std::endl;
    }
}

int main() {

    return 0;
}