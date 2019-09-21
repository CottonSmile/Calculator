#include<iostream>
#include<ctime>
#include<stack>
#include<queue>
#include"compute.h"
using namespace std;
FILE* fp;
int main()
{
	int n;
	int result;
	int operator_num;
	queue<int>  q1;
	queue<char> q2;
	stack<int> s1;
	char s2 = 's';
	cout << "请输入生成的作业题道数n:" << endl;
	errno_t err;
	err = fopen_s(&fp,"tset.txt","w");
	cin >> n;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		queue<int> q3;
		queue<char> q4;
		operator_num = rand() % 2 + 2;
		init(operator_num, q3,q4,q1,q2);
		result = 0;
		result = calculate(result,q1,q2,s1,s2);
		if (result < 0)
		{
			i--;
			continue;
		}
		q3.push(result);
		for (int j=1; q3.size() != 0;j++)
		{
			if (j % 2 != 0)
			{
				cout << q3.front();
				fprintf(fp, "%d", q3.front());
				q3.pop();
			}
			else
			{
				cout << q4.front();
				fprintf(fp, "%c", q4.front());
				q4.pop();
			}
		}
		fputc('\n',fp);
		cout << endl;
	}
	fclose(fp);
	return 0;
}