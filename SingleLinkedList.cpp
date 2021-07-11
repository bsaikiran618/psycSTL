#include "SingleLinkedList.h"
#include <stdlib.h>
#include <iostream>

//SLL_Node Constructors
template <typename dataType>
SLL_Node<dataType>::SLL_Node()
:next(NULL)
{
	
}

template <typename dataType>
SLL_Node<dataType>::SLL_Node(SLL_Node<dataType> *nextVal)
:next(nextVal)
{
	
}

template <typename dataType>
SLL_Node<dataType>::SLL_Node(SLL_Node<dataType> *nextVal, dataType dataVal)
:next(nextVal), data(dataVal)
{
	
}

//SLL Default constructor
template <typename dataType>
SLL<dataType>::SLL()
{
	head = NULL;
	listLength = 0;
}

//SLL Parameterized Constructor
template <typename dataType>
SLL<dataType>::SLL(dataType val)
{
	this->head = new SLL_Node<dataType>(NULL, val);
	this->listLength = 1;
}

//SLL Copy Constructor
template <typename dataType>
SLL<dataType>::SLL(SLL<dataType> &firstList)
{
	SLL_Node<dataType> *current;
	SLL_Node<dataType> *first = firstList.getHead();

	this->listLength = 0;
	while(first != NULL)
	{
		if(this->head == NULL)
		{
			this->head = new SLL_Node<dataType>(NULL, first->data);
			current = this->head;
		}
		else
		{
			current->next = new SLL_Node<dataType>(NULL, first->data);
		}
		current = current->next;
		first = first->next;
		this->listLength++;
	}
}

template <typename dataType>
int SLL<dataType>::insertBack(dataType val)
{
	if(!this->head)
	{
		this->head = new SLL_Node<dataType>(NULL, val);
	}
	else
	{
		SLL_Node<dataType> *current = this->head;
		while(current->next != NULL)
			current = current->next;

		current->next = new SLL_Node<dataType>(NULL, val);
	}
	this->listLength++;
	return 0;
}

template <typename dataType>
int SLL<dataType>::insertFront(dataType val)
{
	if(!this->head)
	{
		this->head = new SLL_Node<dataType>(NULL, val);
	}
	else
	{
		this->head = new SLL_Node<dataType>(this->head, val);
	}
	this->listLength++;
	return 0;
}

template <typename dataType>
int SLL<dataType>::insertAt(uint8_t pos, dataType val)
{
	if(pos > this->listLength || pos < 0)
	{
		std::cerr << "Cannot insert at given position:" << pos << std::endl;
		return -1;
	}
	if(pos == 0) return this->insertFront(val);
	else if(pos == this->listLength) return this->insertBack(val);
	else
	{
		SLL_Node<dataType> *current = this->head;
		uint8_t currentPos = 0;

		while(currentPos < (pos - 1))
		{
			current = current->next;
			currentPos++;
		}

		current->next = new SLL_Node<dataType>(current->next, val);
		this->listLength++;
	}
}


template <typename dataType>
int SLL<dataType>::deleteFront()
{
	if(this->head)
	{
		if(this->head->next == NULL)
		{
			delete this->head;
			this->head = NULL;
		}
		else
		{
			
			SLL_Node<dataType> *temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
	}
	this->listLength--;
	return 0;
}


template <typename dataType>
int SLL<dataType>::deleteBack()
{
	if(this->head)
	{
		
		SLL_Node<dataType> * current = this->head;
		SLL_Node<dataType> * prev = this->head;
		while(current->next != NULL)
		{
			prev = current;	
			current = current->next;
		}
		prev->next = NULL;
		if(current == this->head)
			this->head = NULL;
		delete current;
	}
	this->listLength--;
	return 0;
}

template <typename dataType>
int SLL<dataType>::deleteAt(uint8_t pos)
{
	if(this->head)
	{
		if(pos >= this->listLength || pos < 0)
		{
			std::cerr << "Cannot delete at position:" << pos << std::endl;
			return -1;
		}
		else if(pos == 0) return deleteFront();
		else if(pos == this->listLength) return deleteBack();
		else
		{
			SLL_Node<dataType> *prev = this->head;
			SLL_Node<dataType> *current = this->head;
			uint8_t currentPos = 0;

			while(currentPos < (pos))
			{
				prev = current;
				current = current->next;
				currentPos++;
			}
			prev->next = current->next;
			if(current == this->head)
				this->head = NULL;
			delete current;
		}
	}
	this.listLength--;
	return 0;
}

template <typename dataType>
void SLL<dataType>::display()
{
	SLL_Node<dataType> * current = this->head;
	while(current != NULL)
	{
		std::cout << current->val;
		if(current->next)
			std::cout << "->";
		current = current->next;
	}
	std::cout << std::endl;
}
