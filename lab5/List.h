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
		List *p = head;
		List *old = p;
		while (p !=NULL)
		{
			if (p->value == position)
			{
				old = p->next;
				p->next = new List(val);
				p->next->next = old;
				
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
		while (first!=NULL)
		{
			if (first->value==second->value)
				flag = true;
			first = first->next;
			second = second->next;
		}
		return flag;
	};
	List();
	List(int value);
	~List();
	void add(int val);
	void show();
};// перегружаем операцию скобки (), проверка на неравенство туда передаем ссылку на объект