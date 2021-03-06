#ifndef SINGLY_LINKED_LIST
	#define SINGLY_LINKED_LIST

#include <stdint.h>
#include <string>

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
		uint32_t listLength;
		struct SLL_Node<dataType> *head;
	public:
		//error classes
		class invalidAccessError
		{
			public:
			std::string errorMessage;
			invalidAccessError(std::string message)
			:errorMessage(message)
			{
				
			}
		};
		//constructors
		SLL(); 
		SLL(dataType headValue);
		SLL(SLL<dataType> &); 
		//member functions
		int insertBack(dataType val); //insert at last;
		int insertFront(dataType val); //insert at beginning
		int insertAt(uint32_t pos, dataType val); //insert at a random position
		int deleteFront();
		int deleteBack();
		int deleteAt(uint32_t pos);
		void reverse();
		SLL_Node<dataType> * getHead()const{return this->head;}
		uint32_t getLength()const{return this->listLength;}
		void display();
		dataType readAt(uint32_t  pos);
};
#endif
