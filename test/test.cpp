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
int main(){
	
	vector<int> vec = {1,2,2,3,3,3,4,5,6};
	vector<int> tmp = hh(vec,0);
	for(int i = 0; i < tmp.size(); ++i){
		cout << tmp[i] << endl;
	}

	vector<int> a = {1,2,3,4,5};
	int y = 0;
	int x = 2;
	for(int i = 0; i < 5; ++i){
		y += a[i]*pow(x,i);
	}
	cout << y << endl;
	y = a[4]*x+a[3];
	for(int i = 3; i > 0; --i){
		y = y*x+a[i-1];
	}
	cout << y << endl;
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
