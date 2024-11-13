#pragma once
#include <iostream>
#include "MyNode.h"
class MyQueue {
private:
    MyNode* front;
    MyNode* rear;

public:
    MyQueue();

    // 入队
    virtual void offer(int value);

    // 出队
    virtual void poll();

    // 查看队首元素
    virtual int peek() const;

    // 检查队列是否为空
    bool isEmpty() const;
    // 析构函数，用于释放内存
    virtual ~MyQueue();
};