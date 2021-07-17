#ifndef DOUBLY_LINKED_LIST
	#define DOUBLY _LINKED_LIST

#include <stdint.h>
#include <string>

template <typename dataType>
struct DLL_Node
{
	DLL<dataType> *next, *prev;
	dataType data;

	DLL_Node(dataType val);
	DLL_Node(DLL_Node<dataType> *nextVal, DLL_Node<dataType> *prevVal);
	DLL_Node(DLL_Node<dataType> *nextVal, DLL_Node<dataType> *prevVal, dataType dataVal);
};

template <typename dataType>
class DLL
{
	private:
		uint32_t listLength;
		struct DLL_Node<dataType> *head, *tail;
		DLL_Node<dataType> * goToPosition(uint32_t pos);
	public:
	
	//error classes
	class invalidAccessError
	{
		public:
		std::string errorMessage;
		invalidAccessError(std::string msg)
		:errorMessage(msg)
		{
			
		}
	};
	//constructors
	DLL();
	DLL(dataType headValue);
	DLL(DLL<dataType> &);
	//member functions
	int insertBack(dataType val);
	int insertFront(dataType val);
	int insertAt(uint32_t pos, dataType val);
	int deleteFront();
	int deleteBack();
	int deleteAt(uint32_t pos);
	void reverse();
	DLL_Node<dataType> * getHead()const{return this->head;}
	DLL_Node<dataType> * getTail()const{return this->tail;}
	void display();
	dataType readAt(uint32_t pos);
}

#endif
