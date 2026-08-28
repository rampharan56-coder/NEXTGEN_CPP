#include <iostream>
void copyArray(int *src, int *dest, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void BubleSort(int *arr, int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                swaps++;
            }
        }
        if (!swapped)
            break;
    }
}

void insertSort(int *arr, int n, int &comparions, int &moves)
{
    comparions = 0;
    moves = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            comparions++;
            arr[j + 1] = arr[j];
            moves++;
            j--;
        }
        arr[j + 1] = temp;
        moves++;
    }
}

void selectionSort(int *arr, int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        swaps++;
    }
}
int main()
{
    int arr[] = {8, 5, 9, 10, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int arr1[8] = {0}, arr2[8] = {0}, arr3[8] = {0};

    int comp, swaps;

    std::cout << "Original array: ";
    printArray(arr, size);
    std::cout << std::endl;

    // Bubble Sort
    copyArray(arr, arr1, size);
    BubleSort(arr1, size, comp, swaps);
    std::cout << "Bubble Sort: " << std::endl;
    std::cout << "Comparisons: " << comp << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
    std::cout << "Sort: ";
    printArray(arr1, size);
    std::cout << std::endl;

    // Insertion Sort
    copyArray(arr, arr2, size);
    insertSort(arr2, size, comp, swaps);
    std::cout << "Insetion Sort: " << std::endl;
    std::cout << "Comparisons: " << comp << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
    std::cout << "Sort: ";
    printArray(arr2, size);
    std::cout << std::endl;

    // Selection Sort
    copyArray(arr, arr3, size);
    selectionSort(arr3, size, comp, swaps);
    std::cout << "Selection Sort: " << std::endl;
    std::cout << "Comparisons: " << comp << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
    std::cout << "Sort: ";
    printArray(arr3, size);
    std::cout << std::endl;
    return 0;
}