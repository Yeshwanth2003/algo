#include <bits/stdc++.h>

using namespace std;

void maxmin(vector<int> v, int i, int j, int *max, int *min)
{
     // only if one value then it acts as both max and min
     if (i == j)
          *max = *min = v[i];
     // if two value is left then find max and min among them
     else if (j - i == 1)
     {
          if (v[i] < v[j])
          {
               *max = v[j];
               *min = v[i];
          }
          else
          {
               *max = v[i];
               *min = v[j];
          }
     }
     // else divide to base length to 1 or 2
     else
     {
          int mid = (i + j) / 2;
          // m1 and m2 are max and min respectively to hold the result of other part
          // of recursion, ie range from mid to end
          int m1, m2;
          maxmin(v, i, mid, max, min);
          maxmin(v, mid + 1, j, &m1, &m2);
          // finally comparing both max|min with m1|m2
          if (m1 > *max)
          {
               *max = m1;
          }
          if (m2 < *min)
               *min = m2;
     }
}

int main()
{
     int max, min;
     vector<int> lst{1, 2, 7, 5, 2, 33, 51, 4, 0, -1, 100};
     maxmin(lst, 0, lst.size() - 1, &max, &min);
     cout << max << " " << min;
}