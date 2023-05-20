#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void Merge(vector<int> &A, int left, int right, int mid)
{
    int p = left;
    int q = mid;

    vector<int> merged;

    while (p < mid && q < right)
    {
        if (A[p] <= A[q])
        {
            merged.push_back(A[p]);
            p++;
        }
        else
        {
            merged.push_back(A[q]);
            q++;
        }
    }

    while (p < mid)
    {
        merged.push_back(A[p]);
        p++;
    }
    while (q < right)
    {
        merged.push_back(A[q]);
        q++;
    }

    for (int i = 0; i < merged.size(); i++)
    {
        A[left + i] = merged[i];
    }
}

void MergeSort(vector<int> &A, int begin, int end)
{
    if (end - begin == 1)
    {
        return;
    }
    int mid = floor((end - begin) / 2);
    MergeSort(A, begin, begin + mid);
    MergeSort(A, begin + mid, end);
    Merge(A, begin, end, begin+mid);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    MergeSort(v, 0, v.size());

    bool flag = 0 ;
    int tmp = (v.size()/2) ;
    for (int i = 1 ; i < v.size() ; i++)
    {
      // cout << v[i]  << endl ;
      if (tmp == 0)
      {
        cout << 1 ;
        flag = 1 ;
        break ;
      }
      if (v[i-1] == v[i])
      {
        // cout << "Good\n";
        tmp -- ;
      }
      else 
      {
        tmp = (v.size()/2) ;
      }
    }

    if (tmp == 0 && flag == 0)
    {
      cout << 1 ;
      flag = 1 ;
    }
    if (flag == 0)
    {
      cout << 0 ;
    }
    
    return 0;
}
