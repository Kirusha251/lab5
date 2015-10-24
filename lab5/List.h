#pragma once
#define NULL 0
#include <iostream>
class List
{
	int value;
public:
	List *head;
	List *next;
	List operator() (int val)
	{ 
		if (checkForCorrect(val) == false)
		{
			std::cout << "Sorry,Entered the wrong data" << std::endl;
			return *this;
		}
			List *p = head;
			List *old = NULL;
			while (p != NULL)
			{
				if (p->value == val)
				{
					if (old == NULL)
					{
						old = p;
						head = p->next;
						delete old;
					}
					else
					if (p->next == NULL)
					{
						delete p;
						old->next = NULL;
						p = old;
					}
					else
					{
						old->next = p->next;
						delete p;
						p = old;
					}
				}
				old = p;
				p = p->next;
			}
			return *this;
	};
	List operator() (int val, int position)
	{	
		if (checkForCorrect(val)==false || checkForCorrect(position)==false)
		{
			std::cout << "Sorry,Entered the wrong data" << std::endl;
			return *this;
		}
		List *p = head;
		List *old = p;
		while (p !=NULL)
		{
			if (p->value == position)
			{
				old = p->next;
				p->next = new List(val);
				p->next->next = old;
				break; // 
			}
			p = p->next;
		}
		return *this; 
	};
	List operator !=(List &bel)
	{
		bool flag=false;
		List *first=this->head;
		List *second = bel.head;
		if (first->countSize() == second->countSize())
		while (first!=NULL)
		{
			if (first->value == second->value)
				flag = true;
			else
				flag = false;
			first = first->next;
			second = second->next;
			
		}
		if (flag == true)
			std::cout << "L=B" << std::endl;
		else
			std::cout << "L!=B" << std::endl;
		return flag;
	};
	List();
	List(int value);
	~List();
	void add(int val);
	void show();
	bool checkForCorrect(int);
	int countSize();
};// перегружаем операцию скобки (), проверка на неравенство туда передаем ссылку на объект