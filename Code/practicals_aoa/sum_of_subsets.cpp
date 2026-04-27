#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int> &subset){
    cout << "{ ";
    for (int i = 0; i < subset.size(); i++)
    {
        cout << subset[i] << " ";
    }
    cout << "}" << endl;
    
}

void sumOfSubsets(vector<int> &arr, vector<int> &subset, int index, int currentSum, int target){
    // base condition currSum == target
    if(currentSum == target){
        printSubset(subset);
        return;
    }
    // if currSum > target
    if(currentSum > target || index >= arr.size()) return;

    // include the elem
    subset.push_back(arr[index]);
    sumOfSubsets(arr, subset, index + 1, currentSum + arr[index], target);

    // backtrack
    subset.pop_back();

    // exclude elem
    sumOfSubsets(arr, subset, index + 1, currentSum, target);
}

int main(){
    int n, target;
    cout << "\nEnter the num of elems: ";
    cin >> n;
    cout << "\nEnter the elements: ";
    vector<int> arr(n);
    vector<int> subsets;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter target sum: ";
    cin >> target;
    sumOfSubsets(arr, subsets, 0, 0, target);
    
    return 0;
}