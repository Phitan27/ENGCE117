#include <stdio.h>

class Node {
    public:
        int Data;
        Node *Next;
        Node *Back;
        Node(int data = 0) : Data(data), Next(NULL), Back(NULL) {}
};

class DoubleLinkedList {
    private:
        Node *head;
    public:
        DoubleLinkedList() : head(NULL) {}
        void AddNode(int data = 0);
        void InsertNode(int data = 0, int position = 1);
        void DeleteNode(int position = 1);
        void ShowFront();
        void ShowBack();
};

int main() {
    DoubleLinkedList A, B;
    A.AddNode(1); A.AddNode(2); A.ShowFront(); // Output: 1 2 
    A.InsertNode(3, 1); A.InsertNode(4, 1); A.ShowFront(); // Output: 4 3 1 2 
    A.DeleteNode(1); A.DeleteNode(2); A.ShowFront(); // Output: 3 2 
    printf("---\n");
    B.AddNode(9); B.AddNode(8); B.AddNode(7); B.ShowBack(); // Output: 7 8 9 
    return 0;
}

void DoubleLinkedList::AddNode(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
        newNode->Back = temp;
    }
}

void DoubleLinkedList::ShowFront() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("\n");
}

void DoubleLinkedList::ShowBack() {
    if (head == NULL) return;
    Node *temp = head;
    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Back;
    }
    printf("\n");
}

void DoubleLinkedList::InsertNode(int data, int position) {
    Node *newNode = new Node(data);
    if (position == 1) {
        newNode->Next = head;
        if (head != NULL) head->Back = newNode;
        head = newNode;
    } else {
        Node *temp = head;
        for (int i = 1; temp != NULL && i < position - 1; i++) {
            temp = temp->Next;
        }
        if (temp == NULL) return;
        newNode->Next = temp->Next;
        if (temp->Next != NULL) temp->Next->Back = newNode;
        temp->Next = newNode;
        newNode->Back = temp;
    }
}

void DoubleLinkedList::DeleteNode(int position) {
    if (head == NULL) return;
    Node *temp = head;
    if (position == 1) {
        head = temp->Next;
        if (head != NULL) head->Back = NULL;
        delete temp;
    } else {
        for (int i = 1; temp != NULL && i < position - 1; i++) {
            temp = temp->Next;
        }
        if (temp == NULL || temp->Next == NULL) return;
        Node *toDelete = temp->Next;
        temp->Next = toDelete->Next;
        if (toDelete->Next != NULL) toDelete->Next->Back = temp;
        delete toDelete;
    }
}