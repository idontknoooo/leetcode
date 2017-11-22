#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;
static int some=[](){
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    return 0;
}();

int reverse(int x);
int main(){
	
	cout << reverse(123) << endl;  
	cout << reverse(-123) << endl;  
	cout << typeid(some).name() << endl;
	cout << some << endl;
	cout << "haha";
   return 0;
	 
}
int reverse(int x){

	long long re = 0;
	while(x){
		re = x%10 + re*10;
		x /= 10; 
	}
	return re;
}
