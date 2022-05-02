//*****************************************************************************************************
//
//		File:			LinkedList.h
//		
//		Student:		William Gibbs
//
//		Assignment:	 	Program  #4, StudenList
//
//		Course Name:	Data Structures I 
//
//		Course Number:	COSC 3050 - 10
//
//		Due:			September 21, 2020 
//
//
//		This file contains the definition for node creation.
//
//		Other files required: 
//			1.	StudentList.cpp - main driver program
//          2.  Node.h - definition for node creation
//			3.  Student.h - definition for Student object
//			
//*****************************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <new>
#include "Node.h"
#include "Student.h"

using namespace std;

//*****************************************************************************************************

template <typename TYPE>
class LList
{
private:
	Node <TYPE>* front;
public:
	LList();
	~LList();
	bool insert(const TYPE&);
	TYPE remove(TYPE&);
	TYPE retrieve(TYPE&) const;
	bool viewFront(TYPE&) const;
	bool viewBack(TYPE&) const;
	bool isEmpty() const;
	bool isFull() const;
	bool clearList();
	bool display() const;
	int getSize() const;
};

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE> :: LList()
{
	front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE> :: ~LList()
{
	Node<TYPE>* pTemp = front;

	while ( pTemp != nullptr )
	{
	    Node<TYPE>* next = pTemp->next;
		delete pTemp;
		pTemp = next;
	}

	front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE> :: insert( const TYPE& dataIn )
{
	bool success = false;
	Node<TYPE>* pPrev = nullptr;
	Node<TYPE>* pAfter = front;

	while (( pAfter != nullptr ) && ( pAfter->data < dataIn ))
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	Node<TYPE>* pNew = new ( nothrow ) Node<TYPE>( dataIn, pAfter );

	if ( pNew != nullptr )
	{
		if ( pPrev != nullptr )
		{
			pPrev->next = pNew;
		}

		else
		{
			front = pNew;
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE LList<TYPE> :: remove( TYPE& dataOut )
{
	Node<TYPE>* pTemp = front;
	Node<TYPE>* pPrev = nullptr;

	while (( pTemp != nullptr) && (pTemp->data < dataOut ))
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (( pTemp != nullptr ) && ( pTemp->data == dataOut ))
	{
		dataOut = pTemp->data;

		if ( pPrev != nullptr )
		{
			pPrev->next = pTemp->next;
		}
		else
		{
			front = pTemp->next;
		}

		delete pTemp;
	}

	return dataOut;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE LList <TYPE> :: retrieve( TYPE& data ) const
{
	Node<TYPE>* pTemp = front;

	while (( pTemp != nullptr ) && ( pTemp->data < data ))
	{
		pTemp = pTemp->next;
	}

	if ((pTemp != nullptr) && (pTemp->data == data))
	{
		data = pTemp->data;
	}
	else
		data.id = 0;

	return data;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: viewFront( TYPE& dataOut ) const
{
	bool success = false;

	if ( front != nullptr )
	{
		dataOut = front->data;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: viewBack( TYPE& dataOut ) const
{
	bool success = false;

	Node<TYPE>* pTemp = front;

	while (( pTemp != nullptr ) && ( pTemp->next != nullptr ))
	{
		pTemp = pTemp->next;
	}

	if ( pTemp != nullptr )
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: isEmpty() const
{
	bool empty = true;

	if ( front != nullptr )
		empty = false;

	return empty;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: isFull() const
{
	bool full = true;
	Node<TYPE>* pTemp = new (nothrow) Node <TYPE>;

	if ( pTemp != nullptr )
	{
		full = false;
		delete pTemp;
	}

	return full;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: clearList()
{
	bool hasValues = true;
	Node<TYPE>* pTemp = front;

	if ( front == nullptr )
		hasValues = false;

	else
	{

		while ( pTemp != nullptr )
		{
			Node<TYPE>* next = pTemp->next;
			delete pTemp;
			pTemp = next;
		}

		front = pTemp;
	}

	return hasValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: display() const
{
	bool hasValues = false;
	Node<TYPE>* pTemp = front;

	if ( pTemp != nullptr )
	{

		while (( pTemp != nullptr ))
		{
			cout << pTemp->data;
			pTemp = pTemp->next;
		}

		hasValues = true;

		cout << endl;
	}

	return hasValues;
}

//*****************************************************************************************************

template <typename TYPE>
int LList <TYPE> :: getSize() const
{
	int count = 0;
	Node<TYPE>* pTemp = front;

	while ( pTemp != nullptr )
	{
		pTemp = pTemp->next;
		count++;
	}

	return count;
}

//*****************************************************************************************************

#endif