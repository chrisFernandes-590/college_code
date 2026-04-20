#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main()
{
  int n, frameSize;

  cout << "Enter number of pages: ";
  cin >> n;

  vector<int> pages(n);
  cout << "Enter page reference string: ";
  for (int i = 0; i < n; i++)
  {
    cin >> pages[i];
  }

  cout << "Enter frame size: ";
  cin >> frameSize;

  queue<int> q;              // To maintain FIFO order
  unordered_set<int> frames; // To check presence quickly

  int hits = 0, misses = 0;

  for (int i = 0; i < n; i++)
  {
    int page = pages[i];

    // If page already in frame → HIT
    if (frames.find(page) != frames.end())
    {
      hits++;
    }
    // Page fault → MISS
    else
    {
      misses++;

      // If frames are full, remove oldest page
      if (frames.size() == frameSize)
      {
        int oldest = q.front();
        q.pop();
        frames.erase(oldest);
      }

      // Insert new page
      q.push(page);
      frames.insert(page);
    }
  }

  double hitRatio = (double)hits / n;
  double missRatio = (double)misses / n;

  cout << "\nResults:\n";
  cout << "Page Hits: " << hits << endl;
  cout << "Page Misses: " << misses << endl;
  cout << "Hit Ratio: " << hitRatio << endl;
  cout << "Miss Ratio: " << missRatio << endl;

  return 0;
}