/*
 * myInfixPostfix.cpp
 *
 *  Created on: Oct 12, 2018
 *      Author: admin
 */
#include"arrayStack.h"
#include<iostream>
#include<string>
using namespace std;
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
int main(){
	string eq;
	string ne;
	char x;
	arrayStack<char> s(100);
	s.push('x');
	cout<<"Enter the equation for testing"<<endl;
	getline(cin,eq);
	for( unsigned int i=0;i<eq.length();i++){
	if((eq[i]>='A'&&eq[i]<='Z')||(eq[i]>='a'&&eq[i]<='z'))
		ne+=eq[i];
	else if(eq[i]=='(')
		s.push('(');
	else if(eq[i] == ')')
	 {
	   while(s.top() != 'x' && s.top() != '(')
	            {
	              x = s.top();
	              s.pop();
	              ne += x;
	            }
	            if(s.top() == '(')
	            {
	                x = s.top();
	                s.pop();
	            }
	        }
	else{
	  while(s.top() != 'x' &&prec(eq[i]) <= prec(s.top()))
	   {
	     char c = s.top();
	     s.pop();
	     ne += c;
	   }
	     s.push(eq[i]);
	   }
	}
	 while(s.top() != 'x')
	    {
	        char c = s.top();
	        s.pop();
	        ne += c;
	    }

	cout<<ne<<endl;
	return 0;
}
