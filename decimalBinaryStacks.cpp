/*
 * decimalBinaryStacks.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: admin
 */
#include<stack>
#include<iostream>
using namespace std;
int main(){
	int dec;
	int temp;
	stack <int> s;
	cout<<"Enter number for testing: "<<endl;
	cin>>dec;
	while(dec!=0){
		s.push(dec%2);
		dec=dec/2;
	}
	cout<<"Binary value is: "<<endl;
	while(!s.empty()){
		temp= s.top();
		s.pop();
		cout<<temp;

	}
	return 0;
}


