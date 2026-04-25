#include <iostream>
using namespace std;

/* Function to compute LPS array */
void computeLPS(char pattern[], int m, int lps[])
{
  int length = 0; // length of previous longest prefix suffix
  lps[0] = 0;

  int i = 1;
  while (i < m)
  {
    if (pattern[i] == pattern[length])
    {
      length++;
      lps[i] = length;
      i++;
    }
    else
    {
      if (length != 0)
      {
        length = lps[length - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

/* KMP Search Function */
void KMPSearch(char text[], char pattern[])
{
  int n = strlen(text);
  int m = strlen(pattern);

  int lps[50];
  computeLPS(pattern, m, lps);

  int i = 0; // index for text
  int j = 0; // index for pattern

  while (i < n)
  {
    if (pattern[j] == text[i])
    {
      i++;
      j++;
    }

    if (j == m)
    {
      cout << "Pattern found at index " << i - j << endl;
      j = lps[j - 1];
    }
    else if (i < n && pattern[j] != text[i])
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
}

int main()
{
  char text[100], pattern[50];

  cout << "Enter text: ";
  cin >> text;

  cout << "Enter pattern: ";
  cin >> pattern;

  KMPSearch(text, pattern);

  return 0;
}