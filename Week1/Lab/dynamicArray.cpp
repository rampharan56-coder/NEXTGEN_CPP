#include <iostream>

int main() {
    int size;
    std::cin >> size;
    int *ptr = new int[size];
    int i = 0;
    while(i < size){
        std::cin >> ptr[i];
        i++;
    }
    int j = 0;
    while(j < size){
        std::cout << ptr[j];
        j++;
    }


    delete ptr;
    ptr = nullptr;
    return 0;
}