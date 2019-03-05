/*
 * lab1-cmpe126.cpp
 *Lab_section2: Tues, 2:30-5:20
 *  Created on: Aug 28, 2018
 *      Author: Thinh Manh
 *
 */
#include "clockType.h"
#include <iostream>
using namespace std;
int main(){
	clockType c1;
	clockType c2(10,59);
	clockType c3(5,10,20);
	int sec = 10;
	cout << "The time of the first clock: "<<c1<<"\n";
	cout << "The time of the second clock: "<<c2<<"\nThe time of the third clock: "<< c3<<"\n";
	cout <<"The sum of the first and second clock is: "<<c1+c2<<endl;
	c1= c1+sec;
	cout<<"The time of the first clock after adding 10 seconds:"<< c1<<endl;
	return 0;
}


