#include <iostream>

class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DNode *head;
    DNode *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList()
    {
        DNode *current = head;
        while (current != nullptr)
        {
            DNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtBeginning(int data)
    {
        DNode *newNode = new DNode(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        DNode *newNode = new DNode(data);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        DNode *temp = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        DNode *temp = tail;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            std::cout << "(empty)" << std::endl;
            return;
        }
        DNode *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

class CNode
{
public:
    int data;
    CNode *next;

    CNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    CNode *tail;

public:
    CircularLinkedList()
    {
        tail = nullptr;
    }

    ~CircularLinkedList()
    {
        if (tail == nullptr)
            return;

        CNode *head = tail->next;
        tail->next = nullptr;

        CNode *current = head;
        while (current != nullptr)
        {
            CNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtBeginning(int data)
    {
        CNode *newNode = new CNode(data);
        if (tail == nullptr)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        CNode *newNode = new CNode(data);
        if (tail == nullptr)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFromBeginning()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        CNode *temp = tail->next;
        if (tail->next == tail)
        {
            tail = nullptr;
        }
        else
        {
            tail->next = temp->next;
        }
        delete temp;
    }

    void deleteFromEnd()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        CNode *temp = tail;
        if (tail->next == tail)
        {
            tail = nullptr;
            delete temp;
            return;
        }

        CNode *current = tail->next;
        while (current->next != tail)
        {
            current = current->next;
        }

        current->next = tail->next;
        tail = current;
        delete temp;
    }

    void display()
    {
        if (tail == nullptr)
        {
            std::cout << "(empty)" << std::endl;
            return;
        }
        CNode *current = tail->next;
        do
        {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != tail->next);
        std::cout << "(head)" << std::endl;
    }
};

int main()
{
    std::cout << "--- Doubly Linked List Operations ---" << std::endl;
    DoublyLinkedList dll;
    std::cout << "Initial list: ";
    dll.display();

    std::cout << "\nInserting 10 at the end..." << std::endl;
    dll.insertAtEnd(10);
    dll.display();

    std::cout << "Inserting 20 at the end..." << std::endl;
    dll.insertAtEnd(20);
    dll.display();

    std::cout << "Inserting 5 at the beginning..." << std::endl;
    dll.insertAtBeginning(5);
    dll.display();

    std::cout << "\nDeleting from the beginning..." << std::endl;
    dll.deleteFromBeginning();
    dll.display();

    std::cout << "Deleting from the end..." << std::endl;
    dll.deleteFromEnd();
    dll.display();

    std::cout << "Deleting from the end again..." << std::endl;
    dll.deleteFromEnd();
    dll.display();

    std::cout << "\n\n--- Circular Linked List Operations ---" << std::endl;
    CircularLinkedList cll;
    std::cout << "Initial list: ";
    cll.display();

    std::cout << "\nInserting 100 at the end..." << std::endl;
    cll.insertAtEnd(100);
    cll.display();

    std::cout << "Inserting 200 at the end..." << std::endl;
    cll.insertAtEnd(200);
    cll.display();

    std::cout << "Inserting 50 at the beginning..." << std::endl;
    cll.insertAtBeginning(50);
    cll.display();

    std::cout << "\nDeleting from the beginning..." << std::endl;
    cll.deleteFromBeginning();
    cll.display();

    std::cout << "Deleting from the end..." << std::endl;
    cll.deleteFromEnd();
    cll.display();

    std::cout << "Deleting from the beginning again..." << std::endl;
    cll.deleteFromBeginning();
    cll.display();

    return 0;
}