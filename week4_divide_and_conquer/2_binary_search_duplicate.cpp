#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> num, int key)
{
  int i = 0, j = num.size() - 1, index = 0;
  bool flag = 0;

  while (j >= i)
  {
    int mid = (j + i) / 2;
    if (num[mid] == key)
    {
      bool duplicate = false;
      if (mid > 0)
      {
        if (num[mid - 1] == key)
        {
          duplicate = true;
        }
      }

      if (duplicate == false)
      {
        flag = 1;
        index = mid;
        break;
      }
      else
      {
        j = mid - 1;
      }
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

  if (flag == 1)
  {
    while (num[index] == key)
    {
      index--;
    }
    return index + 1;
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

  for (int i = 0; i < index.size(); i++)
  {
    cout << index[i] << " ";
  }

  return 0;
}