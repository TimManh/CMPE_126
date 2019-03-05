/*
 * complex.cpp
 *
 *  Created on: Sep 4, 2018
 *      Author: admin
 */

#include "complex.h"
#include<iostream>
using namespace std;
complex::complex(){
	a=0;
	b=0;
}
complex::complex(int a1,int b1){
	a=a1;
	b=b1;

}
complex operator +(const complex c1, const complex c2){
	complex c3;
	c3.a=c1.a+c2.a;
	c3.b=c1.b+c2.b;
	return c3;
}
complex operator -(const complex c1, const complex c2){
	complex c3;
	c3.a=c1.a-c2.a;
	c3.b=c1.b-c2.b;
	return c3;
}
complex operator *(const complex c1, const complex c2){
	complex c3;
	c3.a=c1.a*c2.a-c1.b*c2.b;
	c3.b=c1.b*c2.a+c1.a*c2.b;
	return c3;
}
 ostream& operator <<(ostream& outs, complex& c1){
	if(c1.b>0){
		outs<<'('<<c1.a<<"+"<<c1.b<<'i'<<')';
	}
	else{
		outs<<'('<<c1.a<<c1.b<<'i'<<')';}
	return outs;
}
 istream& operator >>(istream& ins, complex& c1){
	 char symbol;
	 int number;
	 ins>>symbol;
	 if(symbol!='('){
		 return ins;
	 }
	 ins>>number;
	 c1.a = number;
	 ins>>number;
	 c1.b= number;
	 ins>>symbol;
	 if(symbol!='i'){
		 return ins;
	 }
	 ins >> symbol;
	 if(symbol != ')'){
	 	return ins;
	 }
	 ins>>symbol;
	 if(symbol!='*'||symbol!='+'||symbol!='-'||symbol!=' '||symbol!='\n'){
		 return ins;
	 }

	return ins;
}

complex::~complex(){

}
