#include <iostream>
#include <vector>
#include <algorithm>  // for swap()
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(true){
        while(i <= high && arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j){
            swap(arr[i], arr[j]);
        }else break;
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}