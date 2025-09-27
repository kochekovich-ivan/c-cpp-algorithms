#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};


class LinkedList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int counter{ 0 };
public:

	void push_back(int value)
	{
		if (counter != 0)
		{
			Node* n = new Node(value);
			tail->next = n;
			tail = tail->next;
			counter++;
		}
		else
		{
			Node* n = new Node(value);
			tail = n;
			head = n;
			counter++;
		}

	}

	void print_all_el()
	{
		if (counter != 0)
		{
			Node* i = head;
			for (; i != nullptr;)
			{
				cout << i->data << ' ';
				i = i->next;
			}
			cout << endl;
		}
		else
		{
			cout << "There is no elements!" << endl;
		}
	}

	unsigned int size()
	{
		return counter;
	}

	
	
	~LinkedList()
	{
		if (head != nullptr)
		{
			Node* cleaner = head;
			if (tail != nullptr)
			{
				Node* after_cleaner = head->next;
				for (; after_cleaner != nullptr;)
				{
					delete cleaner;
					cleaner = after_cleaner;
					after_cleaner = after_cleaner->next;
				}
				delete cleaner;
			}
			else
			{
				delete cleaner;
			}
		}
		
	};


};


int main()
{	
	LinkedList my_list;
	my_list.print_all_el();
	my_list.push_back(10);
	my_list.print_all_el();
	my_list.push_back(15);
	my_list.print_all_el();
	my_list.size();
	
	return 0;
}