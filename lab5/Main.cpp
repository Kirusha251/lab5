#include<iostream>
#include"List.h"
using namespace std;



void main()
{

	List l;
	List b;
	b.add(-1);
	b.add(2);
	l.add(1);
	l.add(2);
	l.add(1);
	l.add(1);
	l.add(1);
	l.add(2);
	b != (l);
	l(1, 1);
	l.show();
	b!= (l);
	l(3, 2);
	l.show();
	b != (l);
} // оператор должен записывать одинаковые значения и должен записывать в пустой список