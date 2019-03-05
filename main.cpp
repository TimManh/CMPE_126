/*
 * main.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: admin
 */
#include <iostream>
#include"linkedListList.h"
using namespace std;
int main(){
	char ans;
	int num,x;
	double numb,y;
	linkedListList<double> X;
	cout<<"How many number do you want to insert?"<<endl;
	cin>>num;
	while(num>X.maxListSize()){
		cout<<"Re-enter the number to insert and max is "<<X.maxListSize()<<endl;
		cin>>num;
	}

	if(num!=0){
	cout<<"Enter the value for the list: "<<endl;
	for(int i=0;i<num;i++){
	cin>>numb;
	X.insertEnd(numb);}
	X.print();}
	else{
		X.isEmpty();
		X.print();
	}
	cout<<"The list size is: "<<X.listSize()<<endl;
	cout<<"What position do you want to remove from the list?"<<endl;
	cin>>num;
	X.removeAt(num);
	cout<<"The list size is: "<<X.listSize()<<endl;
	X.print();
	cout<<"Position and value to replace: "<<endl;
	cin>>x>>y;
	X.replaceAt(x, y);
	X.print();
	cout<<"Position and value to insert: "<<endl;
	cin>>x>>y;
	X.insertAt(x,y);
	X.print();
	cout<<"Position and value to check:"<<endl;
	cin>>x>>y;
	X.isItemAtEqual(x,y);
	if(X.isItemAtEqual(x,y)){
		cout<<y<<" is at location "<<x<<endl;
	}
	else
		cout<<"There is no value in such position"<<endl;
	cout<<"Value you want to retrieve at: "<<endl;
	cin>>x;
	if(X.retreiveAt(x)<=0){
		cout<<"No value in that position";
	}else{
		cout<<X.retreiveAt(x)<<endl;
	}
	cout<<"Do you want to clear the list?"<<endl;
		cin>>ans;
		if(ans=='y'||ans=='Y'){
		X.clearList();
		X.print();}
		else{
		X.print();
		}
	return 0;
}
