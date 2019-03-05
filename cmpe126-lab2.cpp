/*
 * cmpe126-lab2.cpp
 *
 *  Created on: Sep 4, 2018
 *      Author: Thinh Manh
 *      Class : CMPE 126
 *      LAB 2
 */
#include <iostream>
#include "complex.h"
#include <fstream>
using namespace std;
int main(){
	complex c1, c2,c3,c4,c5,c6;
	ifstream in_stream("complexInput.txt");
	ofstream out_stream;
	if(in_stream.fail())
		{
			cout<<"Input file opening failed.\n";
			exit(1);
		}
	in_stream>>c1>>c2;

	// The product of those complex number
	out_stream.open("complexOutput.txt");
	if (out_stream.fail())
		{
			cout<<"Output file opening failed.\n";
			exit(1);
		}
	c3=c2*c1;
	cout<<"The result is: "<<c3<<endl;
	out_stream<<"The result is: "<<c3<<endl;
	ifstream ins("complexInputWrong.txt");
	if(ins.fail())
		{
			cout<<"Input file opening failed.\n";
			exit(1);
		}
	ins>>c4>>c5;
	cout<<c4<<c5;
	in_stream.close();
	ins.close();
	out_stream.close();
	return 0;

}
