#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_map>
//#include <string>
#include <bitset>
using namespace std;

int main(){
  bitset<10> bs;
  cout << bs << endl;
  cout << bs.set() << endl;
  cout << bs.reset(0) << endl;
  return 0;
}
