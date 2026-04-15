#include <bits/stdc++.h>
using namespace std;

/*
Problem:
--------
Generate all permutations of given characters such that:
B should NOT be between A and C

```
🔹 What is Permutation?
----------------------
A permutation is an arrangement of elements where order matters.

🔥 Key idea:
👉 Same elements
👉 Different order = different permutation

🔴 Important distinction:
✅ Permutation (order matters)
   AB ≠ BA

❌ Combination (order doesn’t matter)
   AB = BA

🔹 Real-life analogy:
👉 People sitting in chairs:

   A sits first, B second → different
   B sits first, A second → different

   👉 That’s permutation


🔹 Simple example:
Given:
   A, B, C

All permutations:        
   ABC
   ACB
   BAC
   BCA
   CAB
   CBA

   👉 Total = 6 permutations (n!)

👉 Whereas Combinations (pick/notPick) are : {}, A, B, C, AB, AC, BC, ABC    (2^n = 2^3 = 8 combinations)

👉 As per problem constraint:
   Invalid → ABC, CBA
   Valid   → ACB, BAC, BCA, CAB

   👉 Total valid = 4 permutations


🔴 Why checking only idx == 1 is NOT enough:
------------------------------------------
- Condition depends on neighbors, not just position
- Example: DBE → B is in middle but A & C are not present
  → This is VALID, but idx == 1 check would wrongly remove it

✅ Correct approach:
- Only block patterns:
    A B C
    C B A
- Use early pruning while building permutation


⏱️ Time Complexity:
------------------
O(N!)
- Generating all permutations


💾 Space Complexity:
-------------------
Auxiliary Space = O(N)
- Recursion stack 

Answer Storage:
- O(K × N)
- K = number of valid permutations

Total Space:
- O(N + K × N)
```

*/

void solve(int idx,
           vector<char> &choices,
           vector<bool> &used,
           vector<string> &ans,
           string &curr) {

    int n = choices.size();

    // Base case
    if (idx == n) {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < n; i++) {

        if (used[i]) continue;

        char ch = choices[i];

        // 🔥 Early Pruning
        if (idx == 2) {
            if (curr[0] == 'A' && curr[1] == 'B' && ch == 'C') continue;
            if (curr[0] == 'C' && curr[1] == 'B' && ch == 'A') continue;
        }

        // Choose
        used[i] = true;
        curr.push_back(ch); //string behaves like a dynamic char array —> so push_back/pop_back work just like vector

        // Recurse
        solve(idx + 1, choices, used, ans, curr);

        // Backtrack
        curr.pop_back();
        used[i] = false;
    }
}

int main() {

    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> choices(n);
    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) cin >> choices[i];

    vector<string> ans;
    vector<bool> used(n, false);
    string curr = "";

    solve(0, choices, used, ans, curr);

    cout << "\nValid permutations:\n";
    for (auto &s : ans) {
        cout << s << endl;
    }

    return 0;
}