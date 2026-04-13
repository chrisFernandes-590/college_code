#include<iostream>
#include<vector>
using namespace std;

/* Time & Space Complexity (KMP Algorithm)

Let:
M = length of pattern
N = length of text

Time Complexity:
- Step 1: Construct LPS array → O(M)
- Step 2: Traverse text using KMP → O(N)

Total Time:
O(M) + O(N) = O(N + M)

✔ This holds for ALL cases (Best, Average, Worst)
✔ KMP never re-checks characters → always linear time

---

Space Complexity:
- LPS array → O(M)
- Output array → O(K), where K = number of matches (depends upon input)

Auxiliary Space: O(M)
Total Space: O(M + K)

---

Intuition:
KMP avoids re-comparing characters by using the LPS array,
which tells how much of the previous match can be reused.
*/

vector<int> computeLPS(int pattLen, string pattern){
    
    vector<int> LPS(pattLen, 0);
    LPS[0] = 0;

    int k = 0;

    for(int i = 1; i < pattLen; i++){
        
        //Backtracking step
        while(k > 0 && pattern[k] != pattern[i]){
            k = LPS[k - 1];
        }

        if(pattern[k] == pattern[i]){
            k += 1;
        }

        LPS[i] =  k;
    }

    return LPS;
}

void KMP(int textLen, int pattLen, string text, string pattern, vector<int> &occurrences){

    //Step 1: Construct the LPS Array (Pattern String)
    vector<int> LPS = computeLPS(pattLen, pattern);
    
    //Step 2: Traverse through the entire main string and store the occurrences
    int q = 0;

    for(int i = 0; i < textLen; i++){

        //Backtracking step
        while(q > 0 && pattern[q] != text[i]){
            q = LPS[q - 1]; //Keep backtracking to last checkpoint until match is found or q == 0
        }

        if(pattern[q] == text[i]) q += 1;

        if(q == pattLen){       //q has now reached invalid index i.e lastIdx + 1 (0-based indexing)
            int stIdx = (i - pattLen) + 1;
            occurrences.push_back(stIdx);  //push the stIdx correctly (0-based indexing)

            q = LPS[q - 1]; //Backtrack once to check for overlapping matches in next iteration 
        }
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

    // Call KMP function
    KMP(textLen, pattLen, text, pattern, occurrences);

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