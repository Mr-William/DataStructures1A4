//*****************************************************************************************************
//
//		File:			Student.h
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
//		This file contains the definition for Student object creation.
//
//		Other files required: 
//			1.	StudentList.cpp - main driver program
//          2.  Node.h - definition for node creation
//			3.  LinkedList.h - functions to modify the linked list
//			
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

#include "LinkedList.h"
#include "Node.h"

using namespace std;

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char major[6];
	float gpa;

	bool operator == (const Student&) const;
	bool operator != (const Student&) const;
	bool operator < (const Student&) const;
	bool operator <= (const Student&) const;
	bool operator > (const Student&) const;
	bool operator >= (const Student&) const;
	bool operator = (const Student&);

	friend ostream &operator << (ostream &, const Student &);
	friend istream &operator >> (istream&, Student &);
};

//*****************************************************************************************************

bool Student :: operator == ( const Student& obj ) const
{
	bool status;

	if (this->id == obj.id)
		status = true;
	else
		status = false;

	return status;
}

//*****************************************************************************************************

bool Student :: operator != ( const Student& obj ) const
{
	bool status;

	if ( this->id == obj.id )
		status = false;
	else
		status = true;

	return status;
}

//*****************************************************************************************************

bool Student :: operator < ( const Student& obj ) const
{
	bool status;

	if ( this->id < obj.id )
		status = true;
	else if ( this->id == obj.id )
		status = false;
	else
		status = false;

	return status;
}

//*****************************************************************************************************

bool Student :: operator <= ( const Student& obj ) const
{
	bool status;

	if ( this->id < obj.id )
		status = true;
	else if ( this->id == obj.id )
		status = true;
	else
		status = false;

	return status;
}

//*****************************************************************************************************

bool Student :: operator > ( const Student& obj ) const
{
	bool status;

	if ( this->id > obj.id )
		status = true;
	else if ( this->id == obj.id )
		status = false;
	else
		status = false;

	return status;
}

//*****************************************************************************************************

bool Student :: operator >= ( const Student& obj ) const
{
	bool status;

	if ( this->id > obj.id )
		status = true;
	else if ( this->id == obj.id )
		status = true;
	else
		status = false;

	return status;
}

//*****************************************************************************************************

bool Student :: operator = ( const Student& obj ) 
{
	bool status;
	
	if ( obj.id )
	{
		this->id = obj.id;
		memcpy( this->name, obj.name, sizeof(obj.name) );
		memcpy( this->major, obj.major, sizeof(obj.major) );
		this->gpa = obj.gpa;

		status = true;
	}
	else
		status = false;

	return status;
}

//*****************************************************************************************************

ostream& operator << ( ostream& ostr, const Student& obj )
{
	ostr << "\n" << obj.id << ": " << obj.name << "\n  " << obj.major << " " << obj.gpa << endl;

	return ostr;
}

//*****************************************************************************************************

istream& operator >> ( istream& istr, Student& obj )
{
	istr >> obj.id;
	istr.ignore();
	istr.getline(obj.name, 50, '\n');
	istr >> obj.gpa; 
	istr >> obj.major;

	return istr;
}

//*****************************************************************************************************

#endif