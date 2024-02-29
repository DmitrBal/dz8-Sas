#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

void splitLinkedList(Node* head, int x, Node** smallerHead, Node** largerHead) {
    Node* smallerTail = nullptr;
    Node* largerTail = nullptr;

    Node* current = head;
    while (current) {
        Node* newNode = new Node(current->data);
        if (current->data < x) {
            if (*smallerHead == nullptr) {
                *smallerHead = newNode;
                smallerTail = *smallerHead;
            }
            else {
                smallerTail->next = newNode;
                smallerTail = newNode;
            }
        }
        else {
            if (*largerHead == nullptr) {
                *largerHead = newNode;
                largerTail = *largerHead;
            }
            else {
                largerTail->next = newNode;
                largerTail = newNode;
            }
        }
        current = current->next;
    }
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(7);

    std::cout << "Исходный список: ";
    printLinkedList(head);

    int x;
    std::cout << "Введите значение для разделения списка: ";
    std::cin >> x;

    Node* smallerHead = nullptr;
    Node* largerHead = nullptr;

    splitLinkedList(head, x, &smallerHead, &largerHead);

    std::cout << "Список элементов меньше " << x << ": ";
    printLinkedList(smallerHead);

    std::cout << "Список элементов больше или равных " << x << ": ";
    printLinkedList(largerHead);

    return 0;
}
