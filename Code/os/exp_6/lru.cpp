#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
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

  list<int> lruList; // stores pages (most recent at front)
  unordered_map<int, list<int>::iterator> pageMap;

  int hits = 0, misses = 0;

  for (int i = 0; i < n; i++)
  {
    int page = pages[i];

    // HIT: page already in memory
    if (pageMap.find(page) != pageMap.end())
    {
      hits++;

      // Move page to front (most recently used)
      lruList.erase(pageMap[page]);
      lruList.push_front(page);
      pageMap[page] = lruList.begin();
    }
    // MISS: page not in memory
    else
    {
      misses++;

      // If frames are full → remove least recently used (back)
      if (lruList.size() == frameSize)
      {
        int lru = lruList.back();
        lruList.pop_back();
        pageMap.erase(lru);
      }

      // Insert new page at front
      lruList.push_front(page);
      pageMap[page] = lruList.begin();
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