#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class NestedInteger {
  public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
//// Answers below
typedef long long ll;
class Solution {
public:
  struct cmp{
    bool operator() (string &lhs, string &rhs) {
      int pos1 = lhs.find(' ') + 1;
      int pos2 = rhs.find(' ') + 1;
      return lhs.substr(pos1) == rhs.substr(pos2) ? lhs < rhs : lhs.substr(pos1) < rhs.substr(pos2);
    }
  };
  
  vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> letter;
    vector<string> digit;
    for(int i = 0; i < logs.size(); i++) {
      string curr = logs[i];
      if(isdigit(curr.back())) {
        digit.push_back(curr);
      }
      else{
        letter.push_back(curr);
      }
    }
    sort(letter.begin(), letter.end(), cmp());
    letter.insert(letter.end(), digit.begin(), digit.end());
    return letter;
  }
};
//// Answers above
int main(int argc, char *argv[]) {
  Solution *solution = new Solution();
  
}
  