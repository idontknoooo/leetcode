#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_map>
//#include <string>
using namespace std;

int main(){
  vector<int> vec = {1,2,3,4};
  set<int> s(vec.begin(), vec.end());
  for(auto it = s.begin(); it != s.end(); ++it){
    cout << *it << endl;
  }
  cout << endl;
  for(auto it = s.rbegin(); it != s.rend(); ++it){
    cout << *it << endl;
  }
  return 0;
}
