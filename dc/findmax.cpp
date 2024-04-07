#include <bits/stdc++.h>

using namespace std;

int findGreatest(vector<int> lst, int s, int e)
{
  if (e-s == 1)
    return max(lst[e],lst[s]);
  int mid = s + (e - s) / 2;
  int num1 = findGreatest(lst, s, mid);
  int num2 = findGreatest(lst, mid+1, e);

  return max(num1, num2);
}

int main()
{
  vector<int> lst{5, 2, 6, 88, 2, 9, 10, 3};
  cout << findGreatest(lst, 0, lst.size() - 1);
}