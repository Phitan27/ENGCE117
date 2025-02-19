#include <stdio.h>

struct Node {
    int Data;
    Node *Next;
    Node *Back;
};

void AddNode(Node **, int *Data);
void InsertNode(Node **, int *Data, int *pos);
void DeleteNode(Node **, int *pos);
void SwapNode(Node **, int *pos1, int *pos2);
void ShowFront(Node **);
void ShowBack(Node **);

int main() {
    Node *start = NULL;
    int data, pos1, pos2;

    data = 17; AddNode(&start, &data);
    data = 15; AddNode(&start, &data);
    data = 19; AddNode(&start, &data);
    ShowFront(&start);
    ShowBack(&start);

    data = 26; pos1 = 1; InsertNode(&start, &data, &pos1);
    data = 150; pos1 = 5; InsertNode(&start, &data, &pos1);
    data = 45; pos1 = 3; InsertNode(&start, &data, &pos1);
    ShowFront(&start);

    pos1 = 1; DeleteNode(&start, &pos1);
    pos1 = 2; DeleteNode(&start, &pos1);
    ShowFront(&start);

    pos1 = 1; pos2 = 4; SwapNode(&start, &pos1, &pos2);
    ShowFront(&start);

    return 0;
}

void AddNode(Node **Walk, int *Data) {
    Node *newNode = new Node;  // Using new instead of malloc
    newNode->Data = *Data;
    newNode->Next = NULL;
    newNode->Back = NULL;
    
    if (*Walk == NULL) {
        *Walk = newNode;
    } else {
        Node *temp = *Walk;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
        newNode->Back = temp;
    }
}

void ShowFront(Node **Walk) {
    printf("Show Front : ");
    Node *temp = *Walk;
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("\n");
}

void ShowBack(Node **Walk) {
    printf("Show Back : ");
    Node *temp = *Walk;
    if (temp == NULL) return;
    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Back;
    }
    printf("\n");
}

void InsertNode(Node **Walk, int *Data, int *position) {
    Node *newNode = new Node;  // Using new instead of malloc
    newNode->Data = *Data;
    newNode->Next = NULL;
    newNode->Back = NULL;
    
    if (*position == 1) {
        newNode->Next = *Walk;
        if (*Walk != NULL) (*Walk)->Back = newNode;
        *Walk = newNode;
    } else {
        Node *temp = *Walk;
        for (int i = 1; temp != NULL && i < *position - 1; i++) {
            temp = temp->Next;
        }
        if (temp == NULL) return;
        newNode->Next = temp->Next;
        if (temp->Next != NULL) temp->Next->Back = newNode;
        temp->Next = newNode;
        newNode->Back = temp;
    }
}

void DeleteNode(Node **Walk, int *position) {
    if (*Walk == NULL) return;
    Node *temp = *Walk;
    if (*position == 1) {
        *Walk = temp->Next;
        if (*Walk != NULL) (*Walk)->Back = NULL;
        delete temp;  // Using delete instead of free
    } else {
        for (int i = 1; temp != NULL && i < *position; i++) {
            temp = temp->Next;
        }
        if (temp == NULL) return;
        if (temp->Back != NULL) temp->Back->Next = temp->Next;
        if (temp->Next != NULL) temp->Next->Back = temp->Back;
        delete temp;  // Using delete instead of free
    }
}

void SwapNode(Node **Walk, int *position1, int *position2) {
    if (*position1 == *position2) return;
    Node *node1 = *Walk, *node2 = *Walk;
    int i;
    for (i = 1; node1 != NULL && i < *position1; i++) node1 = node1->Next;
    for (i = 1; node2 != NULL && i < *position2; i++) node2 = node2->Next;
    
    if (node1 == NULL || node2 == NULL) return;
    int temp = node1->Data;
    node1->Data = node2->Data;
    node2->Data = temp;
}