#include <iostream>
void selectionSort(int *arr,int n){
    for (int i = 0; i < n;i++){
        int min = i;
    for (int j = i + 1; j < n;j++){
        if(arr[min] > arr[j]){
            min = j;
        }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
}
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    int i = 0;
    while (i < size)
    {
        std::cout << arr[i] << " ";
        i++;
    }
    return 0;
}