#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include "StackException.h"

using namespace std;

class Stack
{
private:
	int maxStackSize;
	vector<int> dfs;
	int top;
public:
	Stack();
	Stack(int max);
	void push(int new_Item);
	int pop();
};

#endif 
