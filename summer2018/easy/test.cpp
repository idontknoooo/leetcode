#include <iostream>
#include <vector>
//#include <string>
using namespace std;

int main(){
  cout << string::npos << endl;
  string s = "abc";
  if(s.find('a') != -1){
    cout << "FOUND";
  } else 
    cout << "NOT FOUND";
}
