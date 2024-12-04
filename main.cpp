#include "Student.h"
#include "Node.h"

using namespace std;

void add(char* newName, Node* head);
void print(Node* next, Node* head);

int main() {
  Node* head = nullptr;
  add("George");
  print(head);
  add("James");
  print(head);
  add("John");
}

void add(char* newName, Node* head) {
  Node* current = head;
  Student* newStu = new Student;
  newStu->name = newName;

  if (current == nullptr) {
    head = new Node();
    head->setStudent(newStu);
  }
  else {
    while (current->getNext() != nullptr) {
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setStudent(newStu);
  }
}

void print(Node* next) {
  if (next == head) {
    cout << "list:";
  }
  if (next != nullptr) {
    cout << next->getStudent()->name << " ";
    print(next->getNext());
  }
}
