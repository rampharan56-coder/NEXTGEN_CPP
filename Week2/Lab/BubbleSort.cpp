#include <iostream>
void BubleSort(int *arr, int n){
    for (int i = 0; i < n;i++){
        bool swapped = false;
        for (int j = 0; j < n - 1 - i;j++){
            if(arr[j] >arr[j+1]){
                int temp =arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    BubleSort(arr, size);
    int i = 0;
    while(i <size){
        std::cout << arr[i] << " ";
        i++;
    }

    return 0;
}