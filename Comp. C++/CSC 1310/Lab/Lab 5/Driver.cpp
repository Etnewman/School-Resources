/*
	Name: Ethan Newman
	Assignment: Lab 5
	Instructor: April Crockett
	Date: 10/6/2019
*/
#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list;
	
	cout << "\tThe LinkedList has been created.\n\n";
	cout << "\tI am appending several strings to the list.\n\n";
	
	list.appendNode("boogeyman");
	list.appendNode("ghost");
	list.appendNode("scarecrow");
	list.appendNode("witch");
	list.appendNode("zombie");
	
	list.displayList();
	
	cout << "\n\n\tI am inserting vampire in the list.\n\n";
	
	list.appendNode("vampire");
	
	list.displayList();
	
	cout << "\n\n\tI am now deleting ghost from the list.\n\n";
	
	list.deleteNode("ghost");
	
	list.displayList();
		
	return 0;
}