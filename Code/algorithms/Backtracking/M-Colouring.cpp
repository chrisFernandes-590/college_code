#include <bits/stdc++.h>
using namespace std;

/*
    M-Coloring Problem (Backtracking) --> DFS ON CHOICES (Decision-Tree)

    Goal:
    -----
    Assign colors to vertices such that:
    - No two adjacent vertices have the same color


    🔁 Backtracking Idea:
    --------------------
    For each node:
      → Try all available colors
      → Check if safe (no neighbor has same color)
      → If safe:
           assign color
           recurse to next node
           remove color (backtrack)


    🔴 Important Learnings:

    1. Why we use backtracking:
       - We try all possibilities
       - Undo changes to explore other options

    2. Why we use "continue" instead of "return":
       - return → stops exploring further colors ❌
       - continue → skip this color and try next ✅

    3. State representation:
       - colours[node] stores assigned color
       - "" (Empty String) means unassigned

    4. Safety check:
       - Only check neighbors (not entire graph)
       - If neighbor has same color → not safe


    ⏱️ Time Complexity:
       ----------------
       O(M^V)

       - For each node → M choices
       - Total nodes = V
       → Total combinations ≈ M^V


    💾 Space Complexity:
       -----------------
       Auxiliary Space = O(V)
       - Recursion depth = V

       Answer Storage:
       - O(K × V)
       - K = number of valid colorings

       Total Space:
       - O(V + K×V)


    💯 Key Takeaway:
       -------------
       - Try → Check → Recurse → Undo
       - This pattern works for most backtracking problems
*/


/*
    Function: combo()

    Purpose:
    --------
    Assign colors to each node such that no two adjacent nodes
    have the same color.

    Parameters:
    -----------
    node         -> current node to assign color
    colours      -> stores assigned color for each node (string)
    givenColours -> list of available colors
    adj          -> adjacency list of graph
    ans          -> stores all valid colorings
    V            -> number of vertices

*/

void combo(int node,
           vector<string> &colours,
           vector<string> &givenColours,
           vector<vector<int>> &adj,
           vector<vector<string>> &ans,
           int V) {

    // ✅ Base Case: all nodes colored
    if (node == V) {
        ans.push_back(colours);
        return;
    }

    // Try all available colors
    for (int c = 0; c < givenColours.size(); c++) {

        bool isSafe = true;

        // Check all neighbors
        for (auto neigh : adj[node]) {
            if (colours[neigh] != "" &&
                colours[neigh] == givenColours[c]) {
                isSafe = false;
                break;
            }
        }

        //If safe → assign color
        if (isSafe) {

            colours[node] = givenColours[c];

            // Recurse for next node
            combo(node + 1, colours, givenColours, adj, ans, V);

            //Backtrack
            colours[node] = "";
        }
    }
}


int main() {

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }

    int m;
    cout << "Enter number of colors: ";
    cin >> m;

    vector<string> givenColours(m);
    cout << "Enter color names:\n";
    for (int i = 0; i < m; i++) {
        cin >> givenColours[i];
    }

    // Initialize all nodes as uncolored ("" --> Empty String)
    vector<string> colours(V, "");

    vector<vector<string>> ans;

    // Start coloring from node 0
    combo(0, colours, givenColours, adj, ans, V);

    // 🔹 Print all valid colorings
    cout << "\nValid colorings are:\n";

    for (auto &solution : ans) {
        cout << "{ ";
        for (int i = 0; i < solution.size(); i++) {
            cout << solution[i];
            if (i != solution.size() - 1) cout << ", ";
        }
        cout << " }\n";
    }

    return 0;
}