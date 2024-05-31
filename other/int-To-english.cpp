#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
     // to split big number into hundreds
     void mkHundreds(string a, stack<string> &b)
     {
          int c = 0;
          string t = "";
          for (int i = a.length() - 1; i >= 0; i--)
          {
               if (c <= 2)
               {
                    c++;
                    t = a[i] + t;
               }
               else
               {
                    b.push(t);
                    t = a[i];
                    c = 1;
               }
          }
          b.push(t);
     }
     // tester
     void printStack(stack<string> a)
     {
          while (!a.empty())
          {
               cout << a.top() << endl;
               a.pop();
          }
     }
     // helper1
     string once(string a)
     {
          switch (a[0])
          {
          case '1':
               return "One";
          case '2':
               return "Two";
          case '3':
               return "Three";
          case '4':
               return "Four";
          case '5':
               return "Five";
          case '6':
               return "Six";
          case '7':
               return "Seven";
          case '8':
               return "Eight";
          case '9':
               return "Nine";
          }
          return "";
     }
     // helper2
     string twos(string a, stack<string> &util)
     {
          int num = stoi(a);
          if (a[0] == '0')
          {
               a = a[1];
               return once(a);
          }
          switch (num)
          {
          case 10:
               return "Ten";
          case 11:
               return "Eleven";
          case 12:
               return "Twelve";
          case 13:
               return "Thirteen";
          case 14:
               return "Fourteen";
          case 15:
               return "Fifteen";
          case 16:
               return "Sixteen";
          case 17:
               return "Seventeen";
          case 18:
               return "Eighteen";
          case 19:
               return "Nineteen";
          }
          switch (a[0])
          {
          case '2':
               return util.top() != "" ? "Twenty " + util.top() : "Twenty";
          case '3':
               return util.top() != "" ? "Thirty " + util.top() : "Thirty";
          case '4':
               return util.top() != "" ? "Forty " + util.top() : "Forty";
          case '5':
               return util.top() != "" ? "Fifty " + util.top() : "Fifty";
          case '6':
               return util.top() != "" ? "Sixty " + util.top() : "Sixty";
          case '7':
               return util.top() != "" ? "Seventy " + util.top() : "Seventy";
          case '8':
               return util.top() != "" ? "Eighty " + util.top() : "Eighty";
          case '9':
               return util.top() != "" ? "Ninety " + util.top() : "Ninety";
          }
          return "";
     }
     // make induvidual words
     string mkWord(string &a)
     {
          string t = "";
          stack<string> util;
          for (int i = a.size() - 1; i >= 0; i--)
          {
               t = a[i] + t;
               int len = t.length();
               if (len == 1)
               {
                    util.push(once(t));
               }
               else if (len == 2)
               {
                    string a = twos(t, util);
                    while (!util.empty())
                         util.pop();
                    util.push(a);
               }
               else
               {
                    // passing entire string to once because it picks only a[0]
                    string temp = once(t);
                    if (temp != "")
                    {
                         string a = util.top() != ""
                                        ? temp + " Hundred " + util.top()
                                        : temp + " Hundred";
                         while (!util.empty())
                              util.pop();
                         util.push(a);
                    }
               }
          }
          return util.top();
     }
     // handle bunch of hundreds
     void mkWords(stack<string> &s, vector<string> &w)
     {
          while (!s.empty())
          {
               string curr = s.top();
               s.pop();
               string word = mkWord(curr);
               w.push_back(word);
          }
     }

public:
     // access function
     map<int, string> digitPlace{
         {1, "Thousand"}, {2, "Million"}, {3, "Billion"}};
     string numberToWords(int num)
     {
          if (num == 0)
               return "Zero";
          stack<string> hundreds;
          mkHundreds(to_string(num), hundreds);
          vector<string> words;
          // printStack(hundreds);
          mkWords(hundreds, words);
          // printStack(words);
          string ans = "";
          int c = words.size();
          for (int i = 0; i < words.size(); i++)
          {
               c--;
               // a lot of case is done to maintain 'space'
               if (i > 0 && words[i] != "")
                    ans += ' ' + words[i];
               else
                    ans += words[i];
               if (c > 0 && words[i] != "")
               {
                    ans += ' ' + digitPlace[c];
               }
          }
          return ans;
     }
};
int main()
{
     Solution a;
     cout << a.numberToWords(1000);
}