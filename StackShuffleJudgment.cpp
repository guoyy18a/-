//栈混洗判断
#include <iostream>
#include<stack>
using namespace std;

int Push[10010];
int Stack[10010]; 
int Pop[10010];

int main()
{
	int n;
	int t;
	cin>>t>>n;
	for (int i = 0; i < n; i++)
	{
		Push[i]=i+1;
	}
	while (t--)
	{
		for (int i = 0; i < n; i++)
		{
			cin>>Pop[i];
		}

		int i = 0;
		int j = 0;
		int top = -1;
		bool flag = false;
		while (j < n)
		{
			if (top == -1 || Stack[top] < Pop[j])
			{
				if (top < n - 1)
					Stack[++top] = Push[i++];
				else
				{
					flag = true;
					break;
				}
			}
			if (Stack[top] == Pop[j])
				--top, ++j;
			else if (Stack[top] > Pop[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
