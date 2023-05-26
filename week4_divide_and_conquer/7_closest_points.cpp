#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::min;
using std::pair;
using std::string;
using std::vector;

void pair_sort(vector<int> &A, vector<int> &B)
{
  pair<int, int> ypair[A.size()];

  for (int i = 0; i < A.size(); i++)
  {
    ypair[i].second = A[i];
    ypair[i].first = B[i];
  }

  sort(ypair, ypair + A.size());

  for (int i = 0; i < A.size(); i++)
  {
    A[i] = ypair[i].second;
    B[i] = ypair[i].first;
  }
}

double distance(int x1, int x2, int y1, int y2)
{
  // std::cout << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) << std::endl;
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double minimal_distance(vector<int> x, vector<int> y, int left, int right)
{
  if (right - left < 1)
  {
    return 999999;
  }
  if (right - left == 1)
  {
    return distance(x[left], x[right], y[left], y[right]);
  }
  int mid = (left + right) / 2;

  double lcal = minimal_distance(x, y, left, mid);
  double rcal = minimal_distance(x, y, mid + 1, right) ;

  double d = min(lcal, rcal);

  vector<int> temp_x;
  vector<int> temp_y;

  for (int i = left; i < right + 1; i++)
  {
    if (fabs(x[i] - x[mid]) < d)
    {
      temp_x.push_back(x[i]);
      temp_y.push_back(y[i]);
    }
  }
  
  pair_sort(temp_x, temp_y);

  for (int i = 0; i < temp_x.size(); i++)
  {
    for (int j = i + 1; j < i + 7 && j < temp_x.size(); j++)
    {
      d = min(d, distance(temp_x[i], temp_x[j], temp_y[i], temp_y[j]));
    }
  }

  return d;
}

double minimal_distance_wrapper(vector<int> x, vector<int> y)
{
  float d = minimal_distance(x, y, 0, x.size() - 1);
  return d;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance_wrapper(x, y) << "\n";
}
