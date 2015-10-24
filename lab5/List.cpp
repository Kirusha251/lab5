#include"List.h"

List::List()
{	
	head = NULL;
	value = NULL;
};

List::List (int value)
{
	if (head == NULL)
	{
		this->value = value;
		next = NULL;
	}
	else
	{
		this->value = value;
		next = NULL;
	}
}

List::~List()
{

};

bool List::checkForCorrect(int val)
{
	if (val >= 0)
		return true;
	else
		return false;

}
int List::countSize()
{
	List *helper = this;
	int counter = 0;
	while (helper != NULL)
	{
		counter++;
		helper = helper->next;
	}
	return counter;
}

void List::add(int val)

{
	if (checkForCorrect(val)==false)
	{
		std::cout << "Sorry,Entered the wrong data" << std::endl;
		return ;
	}
	if (!head)
	{
		head = new List(val);
	}
	else
	{
		List *p = head;
		if (p->next==NULL)
		{
			next = new List(val);
			head->next = next;
		}
		else
		{
			while (p->next != NULL)
			{
				p = p->next;
			};
			p->next = new List(val);
		}
	}
	/*if (!head)
	{
		head = this;
		head->value = val;
		this->next = NULL;
	}
	else
	{
		List *q = head;
		if (q->next == NULL)
		{
			q->next = this;
			q->next->value = val;
			this->next = NULL;
		}
		else
		{
			while (q->next != NULL)
			{
				q = q->next;
			};
			q->next = this;
			q->next->value = val;
			this->next = NULL;

		}
	}*/
}


void List::show()
{

	List *p = head;
	while (p!=NULL)
	{
		std::cout<<p->value<<std::endl;
		p = p->next;
	}
}
