#include"compute.h"
#include<iostream>
void init(int operator_num, queue<int>& q3,queue<char>& q4)
{
	int mark = 0;
	int d = 0;
	int result;
	for (int j = 1; j<= 2*operator_num+1; j++)
	{
		if (j % 2 != 0)
		{
			int k = rand() % 100;
			if (mark == 1) 
			{
				if (d == 1)
				{
					if (k == 0)
						do
						{
							k = rand() % 100;
						} while (k == 0);
					else if (result % k != 0)
					{
						do
						{
							k = rand() % 100;
							if (k == 0)
								continue;
							else if (result % k != 0)
								continue;
							else
								break;
						} while (1);
						result = result / k;
					}
					d = 0;
				}
				else
				{
					if (k == 0)
						do
						{
							k = rand() % 100;
						} while (k == 0);
					else if (q1.back() % k != 0)
					{
						do
						{
							k = rand() % 100;
							if (k == 0)
								continue;
							else if (q1.back() % k != 0)
								continue;
							else
								break;
						} while (1);
						result = q1.back() / k;
					}
				}
				mark = 0;
			}
			q1.push(k);
			q3.push(k);
			cout << q3.back();
		}
		else
		{
			int a = rand() % 4;
			switch (a)
			{
			case 0:q2.push('+');
				break;
			case 1:q2.push('-');
				break;
			case 2:q2.push('*');
				break;
			case 3:
				if (j!=2&&q2.back() == '/')
					d = 1;
				q2.push('/');
				mark = 1;
				break;
			}
			q4.push(q2.back());
			cout << q4.back();
		}
	}
	q4.push('=');
	cout << q4.back();
}
char judge(char c1, char c2)
{
	if (c1 == '*')
		return 4;
	else if (c1 == '/')
		return 3;
	else if (c1 == '+')
		if (c2 == '/')
			return -3;
		else if (c2 == '*')
			return -4;
		else
			return 2;
	else if (c1 == '-')
		if(c2 == '*')
			return -4;
		else if (c2 == '/')
			return -3;
		else
			return 1;
}
int calculate(int result)
{
	int  num1, num2, num3;
	char c1, c2;
	while (1)
	{
		if (q2.size() >= 1)
		{
			if (s2 == 's')
			{
				c1 = q2.front();
				q2.pop();
			}
			else
			{
				c1 = s2;
				s2 = 's';
			}
			c2 = q2.front();
		
			q2.pop();
			if (s1.size() == 0)
			{
				num1 = q1.front();
				q1.pop();
				num2 = q1.front();
				q1.pop();
			}
			else
			{
				num1 = s1.top();
				s1.pop();
				num2 = s1.top();
				s1.pop();
			}
			num3 = q1.front();
			q1.pop();
			switch (judge(c1, c2))
			{
			case 4:result = ( num1 * num2);
				s1.push(num3);
				s1.push(result);
				s2 = c2;
				break;
			case 3:result = (num1 / num2);
				s1.push(num3);
				s1.push(result);
				s2 = c2;
				break;
			case 2:result = (num2 + num1);
				s1.push(num3);
				s1.push(result);
				s2 = c2;
				break;
			case 1:result = (num1 - num2);
				s1.push(num3);
				s1.push(result);
				s2 = c2;
				break;
			case -3:result = (num2 / num3);
				s1.push(result);
				s1.push(num1);
				s2 = c1;
				break;
			case -4:result = (num2 * num3);
				s1.push(result);	
				s1.push(num1);
				s2 = c1;
				break;
			}
		}
		else
		{
			num1 = s1.top();
			s1.pop();
			num2 = s1.top();
			s1.pop();
			switch (s2)
			{
			case'+':result = (num1 + num2);
				break;
			case'-':result = (num1 - num2);
				break;
			case'*':result = (num1 * num2);
				break;
			case'/':result = (num1 / num2);
				break;
			}
			s2 = 's';
			break;
		}
	}
	return result;
}