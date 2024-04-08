#include <bits/stdc++.h>

using namespace std;

class QuickSort
{
protected:
     int partition(int i, int j)
     {
          // get reference to the input array
          vector<int> &input = (*this->n);
          // considering initial element as pivot element
          int pivot = input[i];
          // copy i,j as it is need to check bounds and in final swap
          int x = i, y = j;
          // until x < y
          while (x < y)
          {
               // find the greater element to pivot form i to j()
               while (input[x] <= pivot && x < j)
                    x++;
               // find the smaller element to pivot from j to i
               while (input[y] >= pivot && y > i)
                    y--;
               // which ever i and j occur first swap
               // this makes that every elements smaller to pivot is at its left
               // where geater at its rigth
               if (x < y)
                    swap(input[x], input[y]);
          }
          // at this point y is the position at which pivot have to be placed
          swap(input[i], input[y]);
          // return y as it is fixed
          return y;
     }

     vector<int> *n;

public:
     QuickSort(vector<int> *n)
     {
          this->n = n;
     }
     void quicksort(int i, int j)
     {
          if (i > j)
               return;
          //   do partition
          int m = this->partition(i, j);
          // leaving the m partion rest
          quicksort(i, m - 1);
          quicksort(m + 1, j);
     }
};

int main()
{
     vector<int> a{2, 64, 12, 52, 74, 35, 13, 75, 85, 9, 8, 11};
     QuickSort q(&a);
     q.quicksort(0, a.size() - 1);
     for (auto i : a)
          cout << i << " ";
}