#include<iostream>
#include<vector>
using namespace std;

/*
BRUTE FORCE STRING MATCHING

Idea:
- Try every possible starting index in the text
- For each index, check if full pattern matches
- If yes → store that index

Time Complexity: O(N * M)
Space Complexity: O(K)  (K = number of matches stored)
*/

void bruteForce(string &pattern, string &text, int pattLen, int textLen, vector<int> &occurrences){
    
    // Loop over all possible starting points in text
    for(int i = 0; i <= textLen - pattLen; i++){
        int st = i;              // pointer for text
        bool isMatch = true;     // assume match initially

        // Try matching pattern from this starting point
        for(int j = 0; j < pattLen; j++){
            if(text[st] != pattern[j]){
                isMatch = false; // mismatch found 
                break;
            }
            st++; // move ahead in text
        }

        // If full pattern matched → store index
        if(isMatch) occurrences.push_back(i);
    }
}

int main(){

    string text, pattern;

    // Take input strings directly
    cout << "Enter the main string: ";
    cin >> text;

    cout << "Enter the pattern string: ";
    cin >> pattern;

    // Automatically calculate lengths
    int textLen = text.length();
    int pattLen = pattern.length();

    //Early Exit (Edge Case)
    if(pattLen > textLen){
        cout <<"No matching indices since pattern is bigger than main text" <<endl;
        return 0;
    }

    vector<int> occurrences; 

    // Call brute force function
    bruteForce(pattern, text, pattLen, textLen, occurrences);

    // If no matches found
    if(occurrences.size() == 0){
        cout << "There are no matching indices" << endl;
        return 0;
    }

    // Print all matching indices
    cout << "The matching indices in the main string are as follows (0-based indexing): " << endl;

    for(int i = 0; i < occurrences.size(); i++){
        cout << occurrences[i] << " ";
    }

    return 0;
}