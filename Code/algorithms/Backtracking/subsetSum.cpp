#include <bits/stdc++.h>
using namespace std;

/*
Function: sum()

```
Purpose:
--------
Finds all subsets whose sum equals reqSum using backtracking + pruning.

Parameters:
-----------
wsf   -> weight (sum) so far
tpl   -> total possible left (sum of remaining elements)
reqSum-> target sum
idx   -> current index in array
arr   -> input array
soln  -> solution vector (0 = not pick, 1 = pick)
ans   -> stores all valid subsets


Key Concepts:
-------------

1. Backtracking:
   - We explore all possibilities by making choices (pick / not pick)
   - Modify state → recurse → undo changes (backtrack)

2. Two Approaches to Handle State:

   (a) Method 1: Passing Values (No Backtracking Needed)
       - Example: sum(wsf + arr[idx], tpl - arr[idx], ...)
       - We pass new values instead of modifying original variables
       - No need to undo anything
       - Easier and less error-prone

   (b) Method 2: In-place Modification (Backtracking Required)
       - Example:
             wsf += arr[idx];
             tpl -= arr[idx];
             sum(...);
             wsf -= arr[idx];   // backtrack
             tpl += arr[idx];
       - We modify the same variables, so we MUST undo changes
       - More efficient and commonly used in interviews

3. Pruning (Optimization):
   - If wsf > reqSum → stop (sum exceeded)
   - If wsf + tpl < reqSum → stop (even future elements can't reach target)
   - This avoids unnecessary recursion calls

4. Defensive Coding:
   - We explicitly set soln[idx] = 0 before notPick
   - Even though backtracking resets it,
     this prevents bugs if code is modified later
     (e.g., early returns added before backtracking)


Time Complexity:
----------------
O(2^n)
- For each element, we have 2 choices: pick or not pick
- So total subsets explored ≈ 2^n

Space Complexity:
-----------------
O(n)
- Recursion stack depth = n
- soln array also takes O(n)
```

*/

void sum(int &wsf, int &tpl, int reqSum, int idx,
         vector<int> &arr, vector<int> &soln,
         vector<vector<int>> &ans) {

    // ✅ Base Case: target achieved
    if (wsf == reqSum) {
        vector<int> subset;
        for (int i = 0; i < soln.size(); i++) {
            if (soln[i] == 1) subset.push_back(arr[i]);
        }
        ans.push_back(subset);
        return;
    }

    // ❌ Pruning conditions
    if (idx == arr.size() || wsf > reqSum || wsf + tpl < reqSum)
        return;

    // 🔹 NOT PICK current element
    // (Defensive coding: ensure clean state)
    soln[idx] = 0;
    sum(wsf, tpl, reqSum, idx + 1, arr, soln, ans);

    // 🔹 PICK current element
    soln[idx] = 1;
    wsf += arr[idx];
    tpl -= arr[idx];

    sum(wsf, tpl, reqSum, idx + 1, arr, soln, ans);

    // 🔹 BACKTRACK (restore state)
    wsf -= arr[idx];
    tpl += arr[idx];
    soln[idx] = 0;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int reqSum;
    cout << "Enter required sum: ";
    cin >> reqSum;

    // Compute total sum (tpl initial value)
    int tpl = 0;
    for (int x : arr) tpl += x;

    int wsf = 0;

    vector<int> soln(n, 0);           // solution vector
    vector<vector<int>> ans;          // final answer

    // Function call
    sum(wsf, tpl, reqSum, 0, arr, soln, ans);

    // Output
    cout << "\nThe subsets equal to the given sum are as follows:\n";

    for (auto sub : ans) {
        cout << "{ ";
        int sz = sub.size();
        for (int i = 0; i < sz; i++) {
            cout << sub[i];
            if (i != sz - 1) cout << ", ";
        }
        cout << " }\n";
    }

    return 0;
}