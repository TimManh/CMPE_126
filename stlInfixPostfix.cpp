/*
 * myInfixPostfix.cpp
 *
 *  Created on: Oct 12, 2018
 *      Author: admin
 */
#include<stack>
#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
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
bool IsNumericDigit(char C)
{
	if((C >= '0' && C <= '9')) return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

double PerformOperation(char operation, double operand1, double operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1;
}
double evaluatePostFix(string expression){
		stack<double> S;
		for(unsigned int i = 0;i< expression.length();i++) {
			if(expression[i] == ' ' ) continue;
			else if(IsOperator(expression[i])) {
				double operand2 = S.top(); S.pop();
				double operand1 = S.top(); S.pop();
				double result = PerformOperation(expression[i], operand1, operand2);
				S.push(result);
			}
			else if(IsNumericDigit(expression[i])){
				double operand = 0;
				while(i<expression.length() && IsNumericDigit(expression[i])) {

					operand = (operand*10) +(expression[i] - '0');
					i++;
				}
				i--;
				S.push(operand);
			}
		}

		return S.top();
	}
int main(){
	string eq;
	string ne;
	char x;
	stack<char> s;
	s.push('x');
	cout<<"Enter the equation for testing"<<endl;
	getline(cin,eq);
	for( unsigned int i=0;i<eq.length();i++){
	if((eq[i]>='0'&&eq[i]<='9')||eq[i]=='.'){
		ne+=eq[i];
	}
	else if(eq[i]==' '){
		ne+=' ';
	}
	else if(eq[i]=='('){
		s.push('(');}
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
	while(s.top() != 'x'){
	  char c = s.top();
	  s.pop();
	  ne += c;
	}
	cout<<ne<<endl;
	double result = evaluatePostFix(ne);
	cout<<"The result is: "<<result<<"\n";
	return 0;
}
