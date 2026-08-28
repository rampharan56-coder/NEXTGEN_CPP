#include <iostream>
void insertSort(int *arr, int n){
    for (int i = 1; i < n;i++){
        int temp = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr, size);
    int i = 0;
    while (i < size)
    {
        std::cout << arr[i] << " ";
        i++;
    }
    return 0;
}