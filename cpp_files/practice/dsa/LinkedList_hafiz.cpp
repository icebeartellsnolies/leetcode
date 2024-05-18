#include <iostream>

using namespace std;
struct Node{
	int data;
	Node *next;//TO point to next node, null otherwise
	//With default value of parameter, we can use the constructor with two as well as one parameter
	Node (int d, Node *n=NULL){
		data = d;
		next = n;
	}
};

class LinkedList {
  Node *head;

public:
  LinkedList() { head = NULL; }
  LinkedList &addNodeAtStart(int d) {
    head = new Node(d, head); // In Node constructor either next will point to
                              // NULL or some node previously pointed by head
    return *this;
  }
  LinkedList &addNodeAtEnd(int d) {
    if (!head)
      head = new Node(d);
    else {
      Node *t;
      for (t = head; t->next != NULL; t = t->next)
        ;
      t->next = new Node(d);
    }
    return *this;
  }
  LinkedList &deleteNodeFromStart() {
    if (head != NULL) {
      Node *t = head;
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
      Node *t = head;
      for (; t->next->next != NULL; t = t->next)
        ; // Move to second last node
      delete t->next;
      t->next = NULL;
    }
    return *this;
  }
  void show() {
    for (Node *t = head; t != NULL; t = t->next)
      cout << t->data << ' ';
    cout << '\n';
  }

  void splitEvenElements() {
    Node *temp = head;

    while (temp) {
      if (temp->data % 2 == 0) {
        int split1 = temp->data / 2;
        int split2 = temp->data / 2;
        if (split1 % 2 == 0) {
          split1--;
          split2++;
        }
        temp->data = split1;
        Node *t = new Node(split2, temp->next);
        temp->next = t;
      }

      temp = temp->next;
    }
  }

  // void splitEvenElements() {
  //   Node *temp = head;
  //   if (head == NULL)
  //     return;
  //   while (temp) {
  //     if (temp->data % 2 == 0) {
  //       int split1 = temp->data / 2;
  //       int split2 = temp->data / 2;
  //       if (split1 % 2 == 0) {
  //         split1--;
  //         split2++;
  //       }
  //       temp->data = split1;
  //       Node *t = new Node(split2, temp->next);
  //       temp->next = t;
  //     }
  //     temp = temp->next;
  //   }
  // }
  //
  // void mergeElements() {
  //   Node *temp = head;
  //   if (head == NULL)
  //     return;
  //   while (temp && temp->next) {
  //     while (temp->data < 50) {
  //       temp->data += temp->next->data;
  //       Node *todel = temp->next;
  //       temp->next = temp->next->next;
  //       delete todel;
  //       if (temp->next == NULL) {
  //         return;
  //       }
  //     }
  //     if (temp->next->next == NULL && temp->next->data < 50) {
  //       temp->data += temp->next->data;
  //       delete temp->next;
  //       temp->next = NULL;
  //     }
  //     temp = temp->next;
  //   }
  // }
  //

  void mergeElements() {
    Node *temp = head;
    Node *prev = NULL;
    while (temp) {
      while (temp->next && temp->data < 50) {
        temp->data += temp->next->data;
        Node *t = temp->next;
        temp->next = temp->next->next;
        delete t;
      }
      if (prev && temp->data < 50) {
        prev->data += temp->data;
        prev->next = NULL;
        delete temp;
        break;
      }

      prev = temp;
      temp = temp->next;
    }
  }
};

int main() {
  LinkedList a;
  a.addNodeAtEnd(12);
  a.addNodeAtEnd(38);
  a.addNodeAtEnd(12);
  a.show();
  a.mergeElements();
  a.show();
  // a.addNodeAtEnd(32);
  // a.addNodeAtEnd(14);
  // a.addNodeAtEnd(21);
  // a.addNodeAtEnd(52);
  // a.addNodeAtEnd(21);
  // a.addNodeAtEnd(35);
  // a.addNodeAtEnd(12);
  // a.show();
  // a.mergeElements();
  // a.show();
}
