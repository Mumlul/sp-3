#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* prev;

public:
    Node(int data) {
        this->data = data;
        this->prev = this->next = NULL;
    }
};


class DoublyLinkedList
{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        this->head = this->tail = NULL;
    }
public:
    void push_front(int value)
    {
        Node* node = new Node(value);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void push_back(int value) {

        /*Node* node = new Node(value);
        if (tail == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }*/
        Node* ptr = new Node(value);

        ptr->prev = tail;
        if (tail != NULL)
            tail->next = ptr;
        if (head == NULL)
            head = ptr;
        tail = ptr;


    }

    void pop_front() {
        if (!head) {
            std::cout << "Список пустой";
        }
        else {
            Node* node = head->next;
            if (node != NULL)
                node->prev = NULL;
            else
            tail = NULL;
            delete head;
            head = node;
        }
    }

    void pop_back() {
        if (!tail) {
            std::cout << "Список пустой";
        }
        else {
            Node* node = tail->prev;
            if (node != NULL)
                node->next = NULL;
            else
                head = NULL;
            delete tail;
            tail = node;
        }

        
    }

    void display() {
        Node* node = head;
        while (node)
        {
            std::cout << node->data << " ";
            node = node->next;
        }
    }

    void sort() {
        Node* node = head;
        while (node != nullptr)
        {
            Node* next = node->next;
            while (next != nullptr)
            {
                if (node->data > next->data)
                {
                    std::swap(node->data, next->data);
                }
                next = next->next;
            }
            node = node->next;
        }
    }

    void remove_duplicates() {
        if (!head || !(head)->next) {
            return; 
        }

        Node* current = head;

        while (current) {
            Node* runner = current->next; 
            while (runner) {
                if (runner->data == current->data) {
                    Node* toDelete = runner;
                    if (runner->prev) {
                        runner->prev->next = runner->next;
                    }
                    if (runner->next) {
                        runner->next->prev = runner->prev;
                    }
                    runner = runner->next; 
                    delete toDelete; 
                }
                else {
                    runner = runner->next; 
            }
            }
        }
    }



};


void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить элемент в начало.\n";
    std::cout << "2. Добавить элемент в конец.\n";
    std::cout << "3. Удалить элемент с начала.\n";
    std::cout << "4. Удалить элемент с конца.\n";
    std::cout << "5. Отобразить список.\n";
    std::cout << "6. Сортировать список.\n";
    std::cout << "7. Удалить дубликаты.\n";
    std::cout << "8. Выйти.\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    DoublyLinkedList list;
    int choice, value;

    while (true) {
        displayMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение: ";
            std::cin >> value;
            list.push_front(value);
            break;
        case 2:
            std::cout << "Введите значение: ";
            std::cin >> value;
            list.push_back(value);
            break;
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            list.display();
            break;
        case 6:
            list.sort();
            std::cout << "Список отсортирован." << std::endl;
            break;
        case 7:
            list.remove_duplicates();
            std::cout << "Дубликаты удалены." << std::endl;
            break;
        case 8:
            std::cout << "Выход из программы." << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }
    }

    return 0;
   
}