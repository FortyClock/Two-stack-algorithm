#include <iostream>
#include <stack>
using namespace std;

void main()
{
	string expression = "((5-(5*2))+3)";    // full bracket expression 

	stack <int> digit;
	stack <char> operand;
	int res = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		char elem = expression[i];

		if (elem >= '0' && elem <= '9')     // push digit in the stack of digits

		{
			int num = elem - '0';
			digit.push(num);
			continue;
		}

		if (elem == '+' ||
			elem == '-' ||
			elem == '*' ||
			elem == '/')                    // push operands in the stack of operands
		{
			operand.push(elem);
			continue;
		}

		if (elem == ')')                    // make the operation
		{
			int a = digit.top();
			digit.pop();
			int b = digit.top();
			digit.pop();

			switch (operand.top())
			{
			case('+'):
				res = a + b;
				digit.push(res);
				break;
			case('-'):
				res = b - a;
				digit.push(res);
				break;
			case('*'):
				res = a * b;
				digit.push(res);
				break;
			case('/'):
				res = a / b;
				digit.push(res);
				break;
			}

			operand.pop();
		}
	}

	cout << digit.top();                    // print the result
}