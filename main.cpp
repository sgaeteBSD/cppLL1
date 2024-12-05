// Santiago Gaete
// 12/5/24
// Testing for Linked List Pt. 1

#include "Student.h"
#include "Node.h"

using namespace std;

void add(char newName, Node* &head); //pass by reference on head
void print(Node* next, Node* head);

int main() {
  Node* head = nullptr;
  add('G', head); //Student* contains one char
  print(head, head);
  add('J', head);
  print(head, head);
  add('R', head);
  print(head, head);
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
