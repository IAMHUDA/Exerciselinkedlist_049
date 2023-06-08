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
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
	void searchdata();
};
void CircularLinkedList::addNode() { 
	int nim;
	string nama;
	Node* nodeBaru = new Node();
	cout << "|Masukan Nim :     ";
	cin >> nim;
	cout << "|Masukan Nama :    ";
	cin >> nama;
	nodeBaru->rollNumber = nim;
	nodeBaru->name = nama;

	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber)
		{
			cout << "|   NIM sudah ada   |" << endl;
			return;
		}

		nodeBaru->next = LAST;
		LAST = nodeBaru;
		return;
	}

	Node* previous = LAST;
	Node* current = LAST;

	while ((current != NULL) && (nim >= current->rollNumber))
	{
		if (nim == current->rollNumber) {
			cout << "NIM sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}
bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	if (LAST == NULL)
		return true;
	else
		return false;

	return LAST == NULL;
}
bool CircularLinkedList::delNode() {
	int rollNo;
	if (listEmpty()) {
		cout << "\nList is empty " << endl;

	}
	cout << "\n enter the roll number of student whose record is to be  deleted: ";

	cin >> rollNo;
	cout << endl;
	if (CircularLinkedList::delNode() == false)
		cout << "record not found" << endl;
	else
		cout << "record with roll number " << rollNo << "deleted" << endl;

	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = LAST;
		while (currentNode != NULL) {
			cout << "________________________________________________" << endl;
			cout << "|\tNim\t\t| nama mahasiswa\t\t" << endl;
			cout << "|     " << currentNode->rollNumber << "\t\t| " << currentNode->name << endl;
			cout << "________________________________________________" << endl;
			cout << endl;
			currentNode = currentNode->next;
		}
	}

}
void CircularLinkedList::searchdata() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukan NIM: ";
		cin >> nim;
		Node* currentNode = LAST;
		while (currentNode != NULL) {
			if (currentNode->rollNumber == nim) {
				cout << "________________________________________________" << endl;
				cout << "|\tNim\t\t| nama mahasiswa\t\t" << endl;
				cout << "|     " << currentNode->rollNumber << "\t\t| " << currentNode->name << endl;
				cout << "________________________________________________" << endl;
				cout << endl;
				cout << "|  NIM TERSEDIA  | " << endl;
				cout << endl;
				cout << "__________________________________________________________________________" << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}
}


int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "----------------------------------------------------------" << endl;
			cout << "|1. Tambah Data \t\t\t\t\t|" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << "|2. cari Data  \t\t\t\t\t\t|" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << "|3. Tampilkan Data\t\t\t\t\t|" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << "|4. hapus Data   \t\t\t\t\t|" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << "|5. list kosong      \t\t\t\t\t|" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << "pilihan:        ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.searchdata();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.delNode();
				break;
			case '5':
				obj.listEmpty();
				break;
			case '6':
				return 0;
			default:
				cout << "\ninvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "check for the values entered." << endl;
		}

	}
}