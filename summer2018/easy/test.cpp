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
  cout << endl;
  unsigned int a = -100 & 15, b = -100 % 16;
  cout << a << endl;
  cout << b << endl;
  cout << 16-84 % 16 << endl;
  return 0;
}
