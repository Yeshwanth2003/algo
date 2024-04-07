#include <bits/stdc++.h>

using namespace std;

class MergeSort
{
protected:
     void merge(int low, int mid, int high)
     {
          // this is an temp arr using which elements can be kept sorted 
          // for every instance
          vector<int> temp;
          int i = low, j = mid + 1;

          // getting a reference to given array
          vector<int> &input = (*this->arr);

          while (i <= mid && j <= high)
          {
               if (input[i] < input[j])
                    temp.push_back(input[i++]);
               else
                    temp.push_back(input[j++]);
          }
          while (i <= mid)
               temp.push_back(input[i++]);
          while (j <= high)
               temp.push_back(input[j++]);

          //copy the temp into the given boundary(low,mid,high) 
          for (int idx = low; idx <= high; ++idx)
          {
               // input is accesed from low to high where temp is from 0 to it's size
               input[idx] = temp[idx - low];
          }
     }

public:
     vector<int> *arr;
     MergeSort(vector<int> *a)
     {
          this->arr = a;
     }
     void mergesort(int i, int j)
     {
     // base condition divide until you have one element left
          if (i >= j)
               return;
          int mid = (i + j) / 2;
          mergesort(i, mid);
          mergesort(mid + 1, j);
          // once the divide is end start to merge|combine
          this->merge(i, mid, j);
     }
};

int main()
{
     vector<int> arr{88, 43, 22, 6, 11, 8};
     MergeSort m(&arr);
     m.mergesort(0, arr.size() - 1);
     for (auto i : arr)
     {
          cout << i << " ";
     }
}