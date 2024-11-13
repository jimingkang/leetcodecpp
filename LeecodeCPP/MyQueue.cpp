#include "MyQueue.h"
MyQueue::MyQueue() : front(nullptr), rear(nullptr) {}

// 入队
 void MyQueue::offer(int value) {
    MyNode* newMyNode = new MyNode(value);
    if (rear == nullptr) {
        front = rear = newMyNode;
        return;
    }
    rear->next = newMyNode;
    rear = newMyNode;
}

// 出队
 void MyQueue::poll() {
    if (front == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    MyNode* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

// 查看队首元素
 int MyQueue::peek() const {
    if (front == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }
    return front->data;
}

// 检查队列是否为空
bool MyQueue::isEmpty() const {
    return front == nullptr;
}

// 析构函数，用于释放内存
 MyQueue::~MyQueue() {
    while (front != nullptr) {
        MyNode* temp = front;
        front = front->next;
        delete temp;
    }
}