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
class ReverseList {
public:
	ListNode* NewListHead(ListNode* head){
		ListNode* first = head;				//从原链表的首节点开始反转操作
		ListNode* reverse = NULL;			//用一个新的空链表存放反转后的链表
		while (first != NULL)
		{
			ListNode* second = first->next;	//初始化原链表首节点的下一个节点
			first->next = reverse;			//原链表首节点的下一个节点链接到新链表的首节点处
			reverse = first;				//下一跳节点链接完成后，将原链表首节点放入到新链表中，成为新链表的首节点
			first = second;					//从原链表中剥离掉原首节点，原链表首节点的下一个节点成为新的原链表首节点，用于下一次循环
		}
		return reverse;
	}
};
