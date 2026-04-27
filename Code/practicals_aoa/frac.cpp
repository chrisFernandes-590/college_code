#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> value(n), weight(n);

    cout<<"Enter the values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    cout<<"Enter the weights:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    
    cout << "Enter capacity: ";
    cin >> W;

    vector<pair<double, int>> ratio;
    for (int i = 0; i < n; i++)
    {
        double r = (double)value[i] / weight[i];
        ratio.push_back({r, i});
    }

    //sort
    sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());
    double maxProfit = 0.0;
    // greedy
    for (int i = 0; i < n; i++)
    {
        int idx = ratio[i].second;
        if(weight[idx] <= W){
            // full inclusion
            maxProfit += value[idx];
            W -= weight[idx];
        }else{
            maxProfit += ratio[i].first * W;
            break;
        }
    }
    
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}