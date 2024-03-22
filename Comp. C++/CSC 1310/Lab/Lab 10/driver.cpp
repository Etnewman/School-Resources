#include "Student.h"
#include "Heap.h"
#include <iostream>

using namespace std;

int main()
{
	
	
	Heap* heapPtr = new Heap(50);
	
	Student data1(2.6, "Cosette Mealbone","HPC");
	heapPtr->insert(data1);
	
	Student data2(4.0, "April Crockett","CSSC");
	heapPtr->insert(data2);
	
	Student data3(3.8, "Beatrix Longbottom", "CYBERSECURITY");
	heapPtr->insert(data3);
	
	Student data4(3.9, "Blaire Strange", "DATA SCIENCE");
	heapPtr->insert(data4);
	
	Student data5(2.9, "Cybil Lidscrew", "CSSC");
	heapPtr->insert(data5);
	
	Student data6(1.4, "Coco Mobo", "DATA SCIENCE");
	heapPtr->insert(data6);
	
	Student data7(3.2, "Alabama Joebob", "CSSC");
	heapPtr->insert(data7);
	
	Student data8(3.6, "Diem Carpefat", "HPC");
	heapPtr->insert(data8);
	
	Student data9(3.9, "Chichi Musicpaper", "CSSC");
	heapPtr->insert(data9);
	
	Student data10(2.7, "Bentlee Caryellow", "CYBERSECURITY");
	heapPtr->insert(data10);


	
	
	
	
	
	while(!heapPtr->isEmpty())
	{
		cout << "\nThe number of Nodes: " << heapPtr->getNumberOfNodes();
		cout << "\nThe Height: " << heapPtr->getHeight();
		cout << endl;
		Student temp(heapPtr->remove());
		cout << temp << endl;
	}
	
	return 0;
}