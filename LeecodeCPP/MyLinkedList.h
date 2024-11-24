#pragma once
#include <iostream>
#include "MyNode.h"
#include <SDL2/SDL.h>
#undef main
#include <SDL2/SDL_ttf.h>

#include "MyQueue.h"

extern int NODE_WIDTH ;      // 节点宽度
extern int NODE_HEIGHT ;     // 节点高度
extern int NODE_SPACING ;    // 节点之间的间隔
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int NODE_RADIUS;
extern int DFS_DELAY_MS; // 每次绘制路径之间的延迟时间（毫秒）

using namespace std;
class MyLinkedList :public MyQueue {
public :
	MyNode * head;
	MyNode* rear;
	SDL_Rect rect;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
public:
	MyLinkedList() {

		head = nullptr; };
	MyLinkedList(SDL_Renderer* renderer) {
		this->renderer = renderer;
		head = nullptr;
	};
	void drawNode( int x, int y, int value, bool hasNext);
	void drawLinkedList();
	void get_text_and_rect(int x, int y, int nodeNum, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect);
	void addAtHead(int data);
	void addAtTail(int data);
	void delAtTail(int index);
	void delAtHead(int index);
	MyNode * getHead();

	// 入队
	 void offer(MyNode * node);

	// 出队
	 void poll();

	// 查看队首元素
	 MyNode* peek() ;

	// 检查队列是否为空
	bool isEmpty() const;
	// 析构函数，用于释放内存


	void print() {
		MyNode *curr = head;
		while (curr != nullptr)
		{
			cout << curr->val<<" ";
			curr = curr->next;
		}
	}
	~MyLinkedList() {
		while (head != nullptr) {
			MyNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

};




/*
int main() {
	MyLinkedList *l = new MyLinkedList();
	l->addAtHead(1);
	l->addAtHead(2);
	l->print();

	l->addAtTail(3);
	l->print();


	return 0;
}
*/
