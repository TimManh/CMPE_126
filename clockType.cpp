/*
 * clockType.cpp
 *Lab_section2: Tues, 2:30-5:20
 *  Created on: Aug 28, 2018
 *      Author: Thinh Manh
 *
 */
#include "clockType.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Define constructors
clockType::clockType() {
	hr=21;
	min=38;
	sec =32;

}
clockType::clockType(int hr1,int min1, int sec1) {
	hr=hr1;
	min=min1;
	sec=sec1;
}
clockType::clockType(int hr1, int min1) {
	hr=hr1;
	min=min1;
	sec=0;
}

// Follow the instruction min and sec is max 60.
clockType operator+(const clockType c1,const clockType c2){
	clockType x;
	int y=0,z=0;
	x.hr=c1.hr+c2.hr;
	x.min =c1.min+c2.min;
	x.sec= c1.sec+c2.sec;
	if(x.sec>=60 ){
		y=x.sec/60;
		x.sec=x.sec-y*60;
		x.min=y+x.min;
	}
	if(x.min>=60 ){
		z=x.min/60;
		x.min=x.min-z*60;
		x.hr=x.hr+z;
	}
	return x;
}
// adding an object and integer with overloading operator
clockType operator+(const clockType c1, int x){
	clockType x1;
	int x2=0,x3=0;
	x1.sec=c1.sec+x;
	if(x1.sec>=60 ){
			x2=x1.sec/60;
			x1.sec=x1.sec-x2*60;
			x1.min=x2+x1.min;
		}
		if(x1.min>=60 ){
			x3=x1.min/60;
			x1.min=x1.min-x3*60;
			x1.hr=x1.hr+x3;
		}
	return x1;
}
//Output the value with << operator
ostream& operator <<(ostream& outs, clockType c1){
	outs<<setfill('0')<<setw(2)<< c1.hr<<":"<<c1.min<<":"<<setfill('0')<<setw(2)<<c1.sec;
	return outs;
}
