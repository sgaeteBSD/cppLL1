// Santiago Gaete
// 12/17/24
// Testing for Linked List Pt. 1

#include "Student.h"
#include "node.h"

using namespace std;

void add(char newName, Node* &head); //pass by reference on head
void print(Node* next, Node* head);
Node* removeLastNode(Node* head);

int main() {
  Node* head = nullptr;
  add('G', head); //Student* contains one char
  print(head, head);
  add('J', head);
  print(head, head);
  add('R', head);
  print(head, head);
  removeLastNode(head);
  print(head, head);
  removeLastNode(head);
  print(head, head);
  //last print should be list:G
}

void add(char newName, Node* &head) {
  Node* current = head;
  //create student and its name (one char)
  Student* newStu = new Student;
  newStu->name = newName;

  if (current == nullptr) {
    head = new Node(newStu); //update head if it's first
  }
  else {
    while (current->getNext() != nullptr) {
      current = current->getNext(); //walk to end
    }
    current->setNext(new Node(nullptr)); //set next to null
    current->getNext()->setStudent(newStu); //and set this to new student
  }
}

void print(Node* next, Node* head) {
  if (next == head) { //print list: to start
    cout << "list:";
  }
  if (next != nullptr) {
    cout << next->getStudent()->name << " ";
    print(next->getNext(), head);
  }
}

Node* removeLastNode(Node* head) {
    //if list is empty return nullptr
    if (head == nullptr) {
        return nullptr;
    }
    //if list has only one node... delete it and return nullptr
    if (head->getNext() == nullptr) {
        delete head;
        return nullptr;
    }

    //find second last node
    Node* secondLast = head;
    while (secondLast->getNext()->getNext() != nullptr) {
      secondLast = secondLast->getNext();
    }

    //delete the last node
    delete (secondLast->getNext());

    //change next of second last
    secondLast->setNext(nullptr);

    return head;
}
