#include <iostream>

using namespace std;
template <typename T>

struct Node{
	T data;
	Node *next;//TO point to next node, null otherwise
	//With default value of parameter, we can use the constructor with two as well as one parameter
	Node (T d, Node *n=NULL){
		data = d;
		next = n;
	}
};

template <typename T> class LinkedList {
  Node<T> *head;

public:
  LinkedList() { head = NULL; }
  LinkedList &addNodeAtStart(T d) {
    head = new Node<T>(d, head);
    return *this;
  }
  LinkedList &addNodeAtEnd(T d) {
    if (!head)
      head = new Node<T>(d);
    else {
      Node<T> *t;
      for (t = head; t->next != NULL; t = t->next)
        ;
      t->next = new Node<T>(d);
    }
    return *this;
  }
  LinkedList &deleteNodeFromStart() {
    if (head != NULL) {
      Node<T> *t = head;
      head = head->next;
      delete t;
    }
    return *this;
  }
  LinkedList &deleteNodeFromEnd() {
    if (!head)
      return *this; // there is no node to delete
    if (head->next == NULL) {
      delete head;
      head = NULL;
    } else {
      Node<T> *t = head;
      for (; t->next->next != NULL; t = t->next)
        ; // Move to second last node
      delete t->next;
      t->next = NULL;
    }
    return *this;
  }
  void show() const {
    for (Node<T> *t = head; t != NULL; t = t->next)
      cout << t->data << ' ';
    cout << '\n';
  }

  void addInOrder(T k) {
    Node<T> *temp = head;

    if (head == NULL || temp->data >= k) {
      addNodeAtStart(k);
    } else {
      while (temp->next && temp->next->data < k) {
        temp = temp->next;
      }
      Node<T> *toAdd = new Node<T>(k);
      toAdd->next = temp->next;
      temp->next = toAdd;
    }
  }

  // void addInOrder(T k) {
  //   Node<T> *temp = head;
  //   if (head == NULL || head->data > k) {
  //     addNodeAtStart(k);
  //   }
  //   while (temp->next && temp->next->data < k) {
  //     temp = temp->next;
  //   }
  //   Node<T> *toAdd = new Node<T>(k);
  //   toAdd->next = temp->next;
  //   temp->next = toAdd;
  // }
  void removeDuplicateElements() {
    Node<T> *temp = head;
    while (temp && temp->next) {
      if (temp->data == temp->next->data) {
        Node<T> *t = temp->next;
        temp->next = temp->next->next;
        delete t;
      } else {
        temp = temp->next;
      }
    }
  }

  void removeDuplicates() {
    Node<T> *temp = head;
    Node<T> *prev = NULL;
    while (temp && temp->next) {
      if (temp->data == temp->next->data) {
        while (temp->next && temp->data == temp->next->data) {
          Node<T> *t = temp->next;
          temp->next = temp->next->next;
          delete t;
        }
        prev->next = temp->next;
        delete temp;
        temp = prev;
      }

      prev = temp;
      temp = temp->next;
    }
  }

  // void removeDuplicateElements() {
  //   Node<T> *temp = head;
  //   while (temp && temp->next) {
  //     while (temp->next && temp->data == temp->next->data) {
  //       Node<T> *temp2 = temp->next->next;
  //       delete temp->next;
  //       temp->next = temp2;
  //     }
  //     temp = temp->next;
  //   }
  // }

  // void removeDuplicates() {
  //   Node<T> *temp = head;
  //   Node<T> *prev = NULL;
  //   while (temp && temp->next) {
  //     if (temp->data == temp->next->data) {
  //       while (temp->data == temp->next->data) {
  //         Node<T> *temp2 = temp->next->next;
  //         delete temp->next;
  //         temp->next = temp2;
  //         if (temp->next == NULL) {
  //           break;
  //         }
  //       }
  //       prev->next = temp->next;
  //       delete temp;
  //       temp = prev;
  //     }
  //     prev = temp;
  //     temp = temp->next;
  //   }
  // }
};

int main() {
  LinkedList<int> a;
  a.addNodeAtEnd(3);
  a.addNodeAtEnd(5);
  a.addNodeAtEnd(7);
  a.addNodeAtEnd(7);
  a.addNodeAtEnd(7);
  a.show();
  a.removeDuplicates();
  a.show();
}
