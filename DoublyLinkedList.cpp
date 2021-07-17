#include "DoublyLinkedList.h";
#include <stdint.h>
#include <string>

//DLL Node constuctors
template <template dataType>
DLL_Node<dataType>::DLL_Node()
next(NULL), prev(NULL)
{

}

template <template dataType>
DLL_Node<dataType>::DLL_Node(DLL_Node<dataType> *nextVal, DLL_Node<dataType> *prevVal)
:next(nextVal), prev(prevVal)
{
	
}

template <template dataType>
DLL_Node<dataType>::DLL_Node(DLL_Node<dataType> *nextVal, DLL_Node<dataType> *prevVal, dataType dataVal)
:next(nextVal), prev(prevVal), data(dataVal)
{
	
}

//DLL contructors
template <typename dataType>
DLL<dataType>::DLL(dataType val)
:head(NULL), tail(NULL), data(val)
{

}
template <typename dataType>
DLL<dataType>::DLL(dataType headValue)
{
	this->head = new DLL_Node(NULL, NULL, headValue);
	this->tail = this->head;
	this->listLength = 1;
}
template <typename dataType>
DLL<dataType>::DLL(DLL<dataType> &)
{
	
}
//insert a new node at the front.
template <typename dataType>
int DLL<dataType>::insertBack(dataType val)
{
	DLL_Node<dataType> * newNode = new DLL_Node<dataType>(NULL, tail, val);
	this->tail = newNode;
}
//insert a new node at the back.
template <typename dataType>
int DLL<dataType>::insertFront(dataType val)
{
	DLL_Node<dataType> * newNode = new DLL_Node<dataType>(head, NULL, val);
	this->head = newNode;
}
//insert a new node at a given position
template <typename dataType>
int DLL<dataType>::insertAt(uint32_t pos, dataType val)
{
	
}
//delete the first node
template <typename dataType>
int DLL<dataType>::deleteFront()
{
	
}
//delete the last node
template <typename dataType>
int DLL<dataType>::deleteBack()
{
	
}
//delete the node at a given position
template <typename dataType>
int DLL<dataType>::deleteAt(uint32_t pos)
{
	
}
//reverse the given DLL
template <typename dataType>
void DLL<dataType>::reverse()
{
	DLL_Node<dataType> * temp = this->head;
	this->head = this->tail;
	this->tail = temp;
}
//display the DLL
template <typename dataType>
void DLL<dataType>::display()
{
	DLL_Node<dataType> * current = this->head;
	while(current != NULL)
	{
		std::cout << current->val;
		if(current->next)
			std::cout << "<->";
		current = current->next;
	}
	std::cout << "END" <<  std::endl;
}
//read the value at the given position
template <typename dataType>
dataType DLL<dataType>::readAt(uint32_t pos)
{
	
}
