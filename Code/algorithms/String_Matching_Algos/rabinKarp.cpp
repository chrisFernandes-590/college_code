#include<iostream>
#include<vector>
using namespace std;

/*
Time & Space Complexity (Rabin-Karp):

Let:
N = length of text
M = length of pattern

1) Best Case: O(N + M)
   - Initial hash computation takes O(M)
   - While sliding, hash values rarely match
   - So no substring comparisons are needed

Note:
Even though we loop (N - M + 1) times and loop M times for initial hashes
so mathematially it becomes : 

O(M) + O(N - M + 1) = O(N)

We still include O(M) independently for initial hash → so formally O(N + M)
But in practical use --> O(N)

2) Average Case: O(N + M)
   - Good hash function → very few collisions
   - Occasional substring checks but negligible overall

3) Worst Case: O(N × M) --> SPURIOUS HIT

   - Many hash collisions (e.g., repetitive strings like "aaaaa...")
   - For many positions, we do full substring comparison → O(M) each
   - Happens ~N times → O(N × M)

Space Complexity: O(K)

- Auxiliary Space: O(1) (only hash variables and pointers)
- Output Space: O(K), where K = number of matching indices (depends upon input)
- Total Space: O(K)
*/

void rabinKarp(int textLen, int pattLen, string text, string pattern, vector<int> &occurrences){

    // Primes for Rabin karp algorithm
    int p = 7, mod = 101;
    
    // To store the hash values of pattern and susbtring of text
    int hashPat = 0, hashText = 0;
    
    int pRight = 1, pLeft = 1;
    
    // Computing the initial hash values
    for(int i = 0; i < pattLen; i++) {

        hashPat += ((pattern[i] - 'a' + 1) * pRight) % mod;
        hashText += ((text[i] - 'a' + 1) * pRight) % mod;
        pRight = (pRight * p) % mod; //Increment the 'p' powers
    }

    // Traverse the text string
    for(int i = 0; i <= textLen - pattLen; i++) {
        
        // If the hash value matches
        if(hashPat == hashText) {
            // Add the index of the result if the substring matches (Extra safety check)
            if(text.substr(i, pattLen) == pattern) occurrences.push_back(i);
        }
        
        /* Update hash only if a next window exists
           The loop runs from i = 0 to i = textLen - pattLen (inclusive),
           where each i represents the starting index of a valid substring of length pattLen.
        
           At the last valid index (i == textLen - pattLen), there is no further window to process.
           Accessing text[i + pattLen] in that case would go out of bounds.
    
           Therefore, we perform the hash update only when i < textLen - pattLen,
           ensuring that text[i + pattLen] remains within valid index range       */

        if(i < textLen - pattLen){
        
            // Updating the hash values
            hashText = (hashText - ((text[i] - 'a' + 1) * pLeft) % mod + mod) % mod;
            //hash property --> When something is subtracted during mod operation, we do '+ mod' to bring it back to correct range
            //First % --> To prevent possible overflow by pLeft
            //Second % --> To normalize final result 

            hashText = (hashText + ((text[i + pattLen] - 'a' + 1) * pRight) % mod) % mod;
            //In addition, there's no risk of going negative so '+ mode' is not needed 
            //Double mods here is just for safety (mathematically a single mod is also fine here)

            hashPat = (hashPat * p) % mod; //Keep strengthening the hashPat by multiplying with p (not pRight/pLeft)
            
            // Updating the prime multiples
            pLeft = (pLeft * p) % mod;
            pRight = (pRight * p) % mod;

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

    // Call rabinKarp function
    rabinKarp(textLen, pattLen, text, pattern, occurrences);

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