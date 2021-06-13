#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define max 100000
void createsieve(vector<int>&v){
	int arr[max]={0};
	v.push_back(2);//2 is a first prime number
	for(int i=3;i<max;i+=2){
		//all even are not prime
		arr[i]=1;
	}
	for(long long int i=3;i<max;i+=2){
		if(arr[i]==1){//prime number
			v.push_back(i);
			for(long long int j=i*i;j<max;j=j+i){//3=3*3 9 9+3
				arr[i]=0;
			}
		}
	}
}
int main() {
	vector<int>p;
	createsieve(p);
	int n;
	cin>>n;
	int q;
	cin>>q;
	stack<int>A[q+1];//0 or 1 for size 2
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		A[0].push(x);
	}
	stack<int>B[q];
	for(int i=0;i<q;i++){
		while(!A[i].empty()){
			int t=A[i].top();
			A[i].pop();
			if(t%p[i]==0){
				//stack in b
				B[i].push(t);
			}
			else{
				A[i+1].push(t);
			}
		}
	}
	for(int i=0;i<q;i++){
		while(!B[i].empty()){
			cout<<B[i].top()<<endl;
			B[i].pop();
		}
	}
	while(!A[q].empty()){
		cout<<A[q].top()<<endl;
		A[q].pop();
	}
		return 0;
}
