#include <iostream>
#include <string>
using namespace std;
#define ListNodePosi(T) ListNode<T>*
template <typename T> struct ListNode {
	T data; ListNodePosi(T) pred; ListNodePosi(T) succ;
	ListNode()
	{
	}
	ListNode(T e,ListNodePosi(T) p=NULL,ListNodePosi(T) s=NULL)
		:data(e),pred(p),succ(s){}
	ListNodePosi(T) insertAsPred(T const& e);
};
template <typename T> class List {
private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;
protected:
	void init();
public:
	List()
	{
		init();
	}
	~List();
	ListNodePosi(T) first();
	ListNodePosi(T) last();
	T remove(ListNodePosi(T) p);
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const & e);
};
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}

template<typename T>
void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
}
template<typename T>
List<T>::~List()
{
	int oldSize = _size;
	while (0 < _size) remove(header->succ);
	delete header;
	delete trailer;
}
template<typename T>
ListNodePosi(T) List<T>::first()
{
	return header->succ;
}

template<typename T>
ListNodePosi(T) List<T>::last()
{
	return trailer;
}

template<typename T>
T List<T>::remove(ListNodePosi(T) p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template<typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const & e)
{
	_size++;
	return p->insertAsPred(e);
}

int main()
{
	string str;
	char link[20000];
	string op;
	string s;
	int x;
	cin >> str;
	int i;
	List<char> list;
	ListNodePosi(char) p = list.first();
	for (i = 0; i < str.length(); i++)
	{
		link[i] = str[i];
		list.insertB(p, link[i]);
	}
	p = list.first();
	while (1)
	{
		cin >> op;
		if (op == "INC")
		{
			cin >> x;
			for (i = 0; i < x; i++)
			{
				p = p->succ;
				if (p == list.last())
				{
					break;
				}
			}
		}
		if (op == "DEC")
		{
			cin >> x;
			for (i = 0; i < x; i++)
			{
				p = p->pred;
				if (p == list.first())
				{
					break;
				}
			}
		}
		if (op == "INS")
		{
			cin >> s;
			char sch[2000];
			for (i = 0; i < s.length(); i++)
			{
				sch[i] = s[i];
				list.insertB(p, sch[i]);
			}
		}
		if (op == "DEL")
		{
			cin >> x;
			p = p->pred;
			for (i = 0; i < x; i++)
			{
				if (p->succ == list.last())
				{
					break;
				}
				list.remove(p->succ);
			}
			p = p->succ;
		}
		if (op == "END")
		{
			p = list.first();
			while (p != list.last())
			{
				cout << p->data;
				p = p->succ;
			}
			cout << endl;
			return 0;
		}
	}
}

