//  Word reader program based on a simple linked list
//  Created by Antoun, Sherine on 10/12/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//
	
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// #define DEBUG

const int MAX = 128;

struct word{
	char data[MAX];
	int count;
	word* next;
};

void initialise(word*&);		// initalise the linked list
bool addnode(char[], word*&);		// add a word to the list
void printnodes(word*&);		// print the linked list
void freelist(word*&);			// delete the linkedlist

int main()
{
	word* head;
	char buffer[MAX];
	char textfile[MAX];
	ifstream ins;

	cout << "Enter Text file to open: ";
	cin >> textfile;
	
	ins.open(textfile, ios::in);

	if (!ins.good())
	{
		cout << "Can not open text file.. Terminating" << endl;
		return 0;
	}

	initialise(head);

	while (ins>>buffer)
	{
		#ifdef DEBUG
		cout << buffer << endl;
		#endif

		if (ins.eof())
		{
			#ifdef DEBUG
			cout << "eof reached" << endl;
			#endif

			break;
		}
	
		if (addnode(buffer, head) == false)
		{
			cout << "Could not insert word into list" << endl;
			freelist(head);
			return 0;
		}		
	}

#ifdef DEBUG
	cout << "made it out of while loop" << endl;
#endif

	printnodes(head);

	freelist(head);

	return 0;
}

//
// The initialise function takes a head node and sets it to NULL.
//

void initialise(word*& head)		// initalise the linked list
{
	head = nullptr;
}

//
// addnode function takes a word to insert into the list and a
// pointer to the head of the list.
// If the word exists in the list then it finds it and increments
// the count indicating it has been seen before. If it is a new
// word then the word is inserted at the end of the list

bool addnode(char data[], word*& head)	
{
	/*
	make temp and curr word pointers
	make temp a node with data in it and with its pointer null.
	if the head is not pointing to anything then set head to temp
	if head is pointing at something set current to head and while current is pointing at something set 
	curr to curr pointer and check if its value is a repeat. if it is, increment current count and break 
	from the loop never inserting. If the end of the list is reached (current->next == nullptr), 
	then current->next = temp.
	*/
	word* temp, *curr;

	temp = new word;

	//populating temp with this particular word
	temp->next = nullptr;
	temp->count = 1;
	strcpy(temp->data, data);

	if(head != nullptr) //checking if there are words already in the list
	{
		curr = head;
		while(curr->next != nullptr)
		{
			curr = curr->next;
			if(strcmp(curr->data, data) == 0) //if word is repeated, increment its count and return true
			{
				curr->count++;
				return true;
			}
		}
		curr->next = temp; //otherwise add it to the end of the list
		return true;
	}
	else
	{
		head = temp; //making head point to this new word if there are no words
		return true;
	}
	return false;

}

//  printnodes is given the head node of the list and prints
// out each word and count - it does this for every node in
// the list.

void printnodes(word*& head)		// print the linked list
{
	word* curr;
	curr = head;
	while (curr != nullptr)
	{
		cout << curr->data << ": " << curr->count << endl;
		curr = curr->next;
	}
}

// deletes the linked list.

void freelist(word*& head)			// delete the linkedlist
{
	word* X = head;
	head = head->next;
	delete X;
}
