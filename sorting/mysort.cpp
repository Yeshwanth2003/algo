#include <bits/stdc++.h>

using namespace std;

void mySort(vector<int> &lst)
{
    int i = 0;
    int e = lst.size() - 1;
    while (i < e)
    {
        int min = INT_MAX, mini;
        int max = INT_MIN, maxi;
        for (int j = i; j <= e; j++)
        {
            if (lst[j] < min)
            {
                min = lst[j];
                mini = j;
            }
            else if (lst[j] > max)
            {
                max = lst[j];
                maxi = j;
            }
        }
        swap(lst[i], lst[mini]);
        swap(lst[e], lst[maxi]);
        i++;
        e--;
    }
}

int main()
{
    vector<int> lst{2, 4, 1, 5, 2, 5, 2, 6, 8, 5};
    mySort(lst);
    for (auto i : lst)
    {
        cout << i << " ";
    }
}