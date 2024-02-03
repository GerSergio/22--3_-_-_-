#include <iostream>
#include <cstdlib>

void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 50 + 1; // заполнение случайными числами от 1 до 50
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void findPairsWithSum(int* arr, int size, int sum) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == sum) {
                std::cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << std::endl;
            }
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    fillArray(arr, size);

    std::cout << "Generated array: ";
    printArray(arr, size);

    int sum;
    std::cout << "Enter the sum to find pairs for: ";
    std::cin >> sum;

    findPairsWithSum(arr, size, sum);

    delete[] arr;
    return 0;
}