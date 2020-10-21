#include <iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode {
	int value;
	struct ListNode* next;
	ListNode(int x) :value(x), next(NULL)
	{

	}
};
class PrintList {
public:
	vector<int> printListFromTailToHead(ListNode* head){
		stack<int> s;
		while (head != NULL)
		{
			s.push(head->value);
			head = head->next;
		}
		vector<int> ans;
		while (!s.empty()) 
		{
			ans.push_back(s.top());
			s.pop();
		}
	}
};
