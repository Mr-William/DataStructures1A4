//*****************************************************************************************************
//
//		File:			Node.h
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
//          2.  LinkedList.h - functions to modify the linked list
//			3.  Student.h - definition for Student object
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node <TYPE>* next;
	Node();
	Node( TYPE d, Node<TYPE>* n = nullptr );
};

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node( TYPE d, Node <TYPE>* n )
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif