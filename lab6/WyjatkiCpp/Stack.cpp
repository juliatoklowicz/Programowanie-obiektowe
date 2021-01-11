#include <iostream>
#include <vector>
#include "Stack.h"
#include "StackException.h"

using namespace std;

Stack::Stack()
{
    maxStackSize = 5;
    top = 0;
}

Stack::Stack(int max) 
{
    maxStackSize = max;
    top = 0;
}

void Stack::push(int new_Item)
{
	if (maxStackSize > top)
	{
		dfs[top] = new_Item;
		top++;	
	}

	else
	{
		throw StackFullException("Przekroczony maksymalny rozmiar stosu",new_Item,maxStackSize);
	}

}

int Stack::pop()
{
	if (top > 0)
	{
		top--;
		return dfs[top];		
	}

	else
	{
		throw StackEmptyException("Stos jest pusty");
	}
}