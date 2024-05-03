#include <bits/stdc++.h>

using namespace std;

class Knapsack
{
private:
     vector<int> weight;
     vector<int> price;

public:
     Knapsack(vector<int> w, vector<int> p)
     {
          this->weight = w;
          this->price = p;
     }
     // pair to return both price and weight
     pair<float, int> compute(int limit)
     {
          float profit = 0;
          int weight = 0;
          vector<float> fraction;
          // calculating the fraction using the weight and price
          // so valuable among the available
          for (int i = 0; i < this->weight.size(); i++)
               fraction.push_back((float)this->price[i] / (float)this->weight[i]);
          // filling until bag is full
          while (weight < limit)
          {
               float max = INT_MIN;
               int p = -1;
               // finding max for every instance
               for (int i = 0; i < fraction.size(); i++)
               {
                    if (fraction[i] > max && fraction[i] != -1)
                    {
                         max = fraction[i];
                         p = i;
                    }
               }
               // if no weight set/fit end
               if (p == -1)
                    break;
               // if current selected item exceeds the bag limit
               // then pick fraction of it
               if (this->weight[p] + weight > limit)
               {
                    // find how much from the current is needed
                    int diff = abs(this->weight[p] - ((weight + this->weight[p]) - limit));
                    // add it to weight
                    weight += diff;
                    // compute profit for picked fraction
                    // ie.., if out of 3 only 2 is needed then 2/3*price is needed
                    profit += ((float)this->price[p] * ((float)diff / (float)this->weight[p]));
               }
               // else add it
               else
               {
                    weight += this->weight[p];
                    profit += (float)this->price[p];
               }
               // set currrent to least so it don't interfer with next instanceF
               fraction[p] = INT_MIN;
          }
          return {profit, weight};
     }
};

int main()
{
     vector<int> weight{2, 3, 5, 7, 1, 4, 1};
     vector<int> price{10, 5, 15, 7, 6, 18, 3};
     Knapsack k(weight, price);
     pair<float, int> soln = k.compute(15);
     cout << soln.first << " " << soln.second;
}