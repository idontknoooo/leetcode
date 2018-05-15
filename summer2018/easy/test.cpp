#include <iostream>
#include <vector>
#include <unordered_map>
//#include <string>
using namespace std;

int main(){
  unordered_map<int, int> um;
  vector<int> vec = {1,2,3,4,5,6};
  for(int i = 0; i < vec.size(); ++i){
    int tmp = vec[i]<<1;
    cout << tmp << endl;
  }
  return 0;
}
