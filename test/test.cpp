#include <iostream>
#include <cstring>
#include <typeinfo>
#include <vector>
#include <cmath>
using namespace std;
static int some=[](){
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    return 0;
}();
vector<int> hh(vector<int> vec, int n);
int reverse(int x);
string countAndSay(int n);
int fibonacci(int a);
int fibonacci1(int a);
int main(){
	
	// vector<int> vec = {1,2,2,3,3,3,4,5,6};
	// vector<int> tmp = hh(vec,0);
	// for(int i = 0; i < tmp.size(); ++i){
	// 	cout << tmp[i] << endl;
	// }

	// vector<int> a = {1,2,3,4,5};
	// int y = 0;
	// int x = 2;
	// for(int i = 0; i < 5; ++i){
	// 	y += a[i]*pow(x,i);
	// }
	// cout << y << endl;
	// y = a[4]*x+a[3];
	// for(int i = 3; i > 0; --i){
	// 	y = y*x+a[i-1];
	// }
	// cout << y << endl;
	// for(int i = 1; i < 6; ++i)
	// 	cout << countAndSay(i) << endl;
	// char a = 9+'0';
	// cout << a << endl;
	// string b = to_string(88);
	// cout << b << endl;
	for(int i = 1; i < 10; ++i){
		cout << fibonacci(i) << " ";
	}
	cout << endl;
	for(int i = 1; i < 10; ++i){
		cout << fibonacci1(i) << " ";
	}
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
vector<int> hh(vector<int> vec, int n){
	if(!vec.size()) return vec;
	int a = 1;
	for(int i = 1; i < vec.size(); ++i){
		if(vec[i]!=vec[i-1]){
			vec[a++] = vec[i];
		}
	}
	return vector<int> (vec.begin(), vec.begin()+a);

}
string countAndSay(int n){

	string s = "1";
	string tmp = "";
	int i = 1;
	while(i < n){
		int count = 1;
		int j = 0;
		while(j < s.length()){
			if(s[j]!=s[j+1]){
				tmp += count + '0';
				tmp += s[j];
				count = 1;
			}
			else{
				count += 1;
			}
			++j;
		}
		s = tmp;
		tmp = "";
		++i;
	}
	return s;
}
int fibonacci(int n){
	int a = 0, b = 1;
	int re = 0;
	if(n==1) return a;
	if(n==2) return b;
	while(n-- > 2){
		re = a + b;
		a = b;
		b = re;
	}	
	return re;
}
int fibonacci1(int n){
	int a = 0, b = 1;
	if(n<=1) return 0;
	else if(n==2) return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}