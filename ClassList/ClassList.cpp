// Project.cpp: определяет точку входа для консольного приложения. 
// 

#include "stdafx.h" 
#include "iostream" 
#include <locale.h>

using namespace std; 

template <class T> 
class CList
{ 
public:
	struct Node{ 
		Node():next(NULL){}; 
		Node(const T& t):data(t), next(NULL){}; 
		T data; 
		Node* next; 
	}; 
	Node* head; 

public: 
	CList():head(NULL){}; 

	CList(const CList &obj){
		this->head=NULL;
		Node* N=obj.head;
		while(N!=NULL){
			push(N->data);
			N = N->next;
		}
	} 

	~CList(){ 
		while(head != NULL){ 
			Node* newHead = head->next;
			delete head;
			head = newHead;
		}
	}; 

	void push(const T& t){ 
		if(Node* node = new Node(t)){ 
			node->next = head; 
			head = node; 
		} 

	}; 

	void print(){ 
		Node *N=head; 
		while(N != NULL) { 
			cout << N->data << endl; 
			N=N->next; 
			} 
	} 

	friend ostream& operator<<(ostream& os, const CList& obj){ 
		Node* N=obj.head; 
		while(N) { 
			os << N->data << endl; 
			N=N->next; 
		} 
		return os; 
	} 

	template <typename S> 
	CList<T> operator +(const CList<S>& p2){
		CList<T>::Node* cur1 = this->head;
		CList<S>::Node* cur2 = p2.head;
		CList <T> SList;
		while (cur1 && cur2){
			SList.push(cur1->data);
			cur1 = cur1->next;
			SList.push(cur2->data);
			cur2 = cur2->next;
		}
		return SList;
	}

	CList operator +(int k){
		CList <T> SList;
		Node* N=this->head;
		int ch=0;
		while(N!=NULL){
			SList.push(N->data);
			N = N->next;
			ch++;
			if (ch==k)
				return SList;
		}
		return SList;
	}
}; 




int _tmain(int argc, _TCHAR* argv[]) 
{ 
	setlocale(LC_ALL, "Russian");
	CList <int> CInt; 
	CInt.push(1); // создаем односвязный список из 10 элементов
	CInt.push(2);
	CInt.push(3);
	CInt.push(4);
	CInt.push(5);
	CInt.push(6);
	CInt.push(7);
	CInt.push(8);
	CInt.push(9);
	CInt.push(10);

	cout << "Первоначальный список:" << endl;
	cout << CInt << endl; 
	/*cout << list << endl;
	cout << list2 << endl;*/
	int k = 5;
	cout << "Результат:" << endl;
	cout << CInt + k << endl; // при сложении с числом создается новый список, в котором остается только k элементов

	return 0; 
}