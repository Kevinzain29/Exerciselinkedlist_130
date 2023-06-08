
#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** zain, Node** ahmad);
	bool listEmpty();
	bool delNode(int rollno);
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int nim;
	string nm;
	cout << "\nEnter the rool number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->rollNumber = nim; // step 2
	newNode->name = nm; // step 2

	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST; //step 3
		if (LAST != NULL)
			LAST->next = newNode; // step 4
		newNode->next = NULL; 
		LAST = newNode; 
		return;
	}
	/*inserting a Node between two Nodes in the list*/
	Node* ahmad = LAST; 
	Node* zain = NULL;
	while (ahmad->next != NULL && ahmad->next->rollNumber < nim) 
	{
		zain = ahmad;
		ahmad = ahmad->next; 
	}

	if (ahmad->next != NULL && nim == ahmad->next->rollNumber) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newNode->next = ahmad->next; 
	newNode->next = ahmad; 
	if (ahmad->next != NULL)
		ahmad->next = newNode; 
	ahmad->next = newNode; 
}
bool CircularLinkedList::search(int rollno, Node** zain, Node** ahmad) {
	*zain = LAST->next;
	*ahmad = LAST->next;
	while (*ahmad != LAST) {
		if (rollno == (*ahmad)->rollNumber) {
			return true;
		}
		*zain = *ahmad;
		*ahmad = (*ahmad)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(int rollno) { //write your answer here
	Node* zain, * ahmad;
	zain = ahmad = NULL;
	if (search(rollno, &zain, &ahmad) == false)
		return false;
	if (ahmad->next != NULL)
		ahmad->next->next = zain; 
	if (zain != NULL)
		zain->next = ahmad->next; 
	else
		LAST = ahmad->next;

	delete ahmad; 
	return 0;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}