#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> num, int key)
{
  int i = 0, j = num.size() - 1;

  while (j >= i)
  {
    int mid = (j + i) / 2;

    if (num[mid] == key)
    {
      return mid;
    }
    else if (num[mid] > key)
    {
      j = mid - 1;
    }
    else
    {
      i = mid + 1;
    }
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  vector<int> num(n);

  for (int i = 0; i < n; i++)
  {
    cin >> num[i];
  }

  int m;
  cin >> m;
  vector<int> index;

  for (int i = 0; i < m; i++)
  {
    int key;
    cin >> key;
    int x = binarySearch(num, key);
    index.push_back(x);
  }

  for (int i = 0 ; i < index.size(); i++)
  {
    cout << index[i] << " " ;
  }

  return 0 ;
}