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
	bool search(int rollno, Node** fathur, Node** muhamad);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() {
	int rollno;
	string name;
	cout << "Enter roll number: ";
	cin >> rollno;
	cout << "Enter name: ";
	cin >> name;

	Node* newNode = new Node();		//step 1 a
	newNode->rollNumber = rollno;  
	newNode->name = name;

	if (listEmpty()) { //  Beginning of the list
		newNode->next = newNode;  
		LAST = newNode;			
	}
	else {
		Node* muhamad = LAST->next;
		Node* fathur = NULL;

		while (muhamad->rollNumber < rollno && muhamad != LAST) { // Between two nodes in the list
			fathur = muhamad;
			muhamad = muhamad->next;
		}

		if (muhamad == LAST && muhamad->rollNumber < rollno) { // End of the list
			newNode->next = LAST->next;
			LAST->next = newNode;
			LAST = newNode;
		}
		else {
			newNode->next = muhamad;
			if (fathur == NULL) {
				LAST->next = newNode;
			}
			else {
				fathur->next = newNode;
			}
		}
	}
	cout << "Node added successfully." << endl;
} //

bool CircularLinkedList::search(int rollno, Node** fathur, Node** muhamad) {
	*fathur = LAST->next;
	*muhamad = LAST->next;
	while (*muhamad != LAST) {
		if (rollno == (*muhamad)->rollNumber) {
			return true;
		}
		*fathur = *muhamad;
		*muhamad = (*muhamad)->next;
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
bool CircularLinkedList::delNode() { 
	if (listEmpty()) {		//step 1 a
		cout << "List is empty. Deletion failed." << endl;
		return false;
	}

	int rollno;
	cout << "Enter roll number of the node to delete: ";
	cin >> rollno;

	Node* fathur = NULL;
	Node* muhamad = NULL;
	bool found = search(rollno, &fathur, &muhamad);

	if (!found) {
		cout << "Node not found. Deletion failed." << endl;
		return false;
	}

	if (muhamad == LAST) { // Beginning of the list
		if (LAST->next == LAST) { // If the node to be deleted is the only node in the list
			delete LAST;
			LAST = NULL;
			cout << "Node deleted successfully." << endl;
			return true;
		}

		LAST->next = muhamad->next;
		LAST = muhamad->next;
		delete muhamad;
	}
	else {
		muhamad->next = muhamad->next;
		delete muhamad;
	}

	cout << "Node deleted successfully." << endl;
	return true;
}//write your answer here

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* muhamadNode = LAST->next;
		while (muhamadNode != LAST) {
			cout << muhamadNode->rollNumber << " " << muhamadNode->name << endl;
			muhamadNode = muhamadNode->next;
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