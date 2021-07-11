#ifndef SINGLE_LINKED_LIST
	#define SINGLE_LINKED_LIST

#include <stdint.h>

template <typename dataType>
struct SLL_Node
{
	SLL_Node<dataType> *next;
	dataType data;

	SLL_Node();
	SLL_Node(SLL_Node<dataType> *nextVal);
	SLL_Node(SLL_Node<dataType> *nextVal, dataType dataVal);
};

template <typename dataType>
class SLL
{
	private:
		uint8_t listLength;
		struct SLL_Node<dataType> *head;
	public:
		SLL(); //default constructor
		SLL(dataType headValue);
		SLL(SLL<dataType> &); //copy constructor
		int insertBack(dataType val); //insert at last;
		int insertFront(dataType val); //insert at beginning
		int insertAt(uint8_t pos, dataType val); //insert at a random position
		int deleteFront();
		int deleteBack();
		int deleteAt(uint8_t pos);
		SLL_Node<dataType> * getHead()const{return this->head;}
		uint8_t getLength()const{return this->listLength;}
		void display();
};
#endif
