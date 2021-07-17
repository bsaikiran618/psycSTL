#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <string>
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

//SLL Constructors
template <typename dataType>
SLL<dataType>::SLL()
{
	head = NULL;
	listLength = 0;
}

template <typename dataType>
SLL<dataType>::SLL(dataType val)
{
	this->head = new SLL_Node<dataType>(NULL, val);
	this->listLength = 1;
}

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


//Insert node at the end
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

//Insert node at the beginning
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

//Insert node at a position
template <typename dataType>
int SLL<dataType>::insertAt(uint32_t pos, dataType val)
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
		uint32_t currentPos = 0;

		while(currentPos < (pos - 1))
		{
			current = current->next;
			currentPos++;
		}

		current->next = new SLL_Node<dataType>(current->next, val);
		this->listLength++;
	}
}

//Delete the first node
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


//Delete the last node
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

//Delete the node at a certain position
template <typename dataType>
int SLL<dataType>::deleteAt(uint32_t pos)
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
			uint32_t currentPos = 0;

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

//Show the linked list
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
	std::cout << "END" <<  std::endl;
}

//reverse the linked list
template <typename dataType>
void SLL<dataType>::reverse()
{
	if(this->head)
	{
		SLL<dataType> *first, *second;
		first = this->head;
		second = first->next;

		while(second != NULL)
		{
			SLL<dataType> *temp = second->next;
			second->next = first;
			first = second;
			second = temp;
		}

		this->head = first;
	}
}

//read the value at a position
template <typename dataType>
dataType SLL<dataType>::readAt(uint32_t position)
{
	if(position > this->listLength || position < 0)
		throw new SLL<dataType>::invalidAccessError("Position out of bounds");

	uint32_t currentPos = 0;
	SLL<dataType> * current = this->head;

	while(currentPos < position)
		current = current->next;
	
	return *current;
}
