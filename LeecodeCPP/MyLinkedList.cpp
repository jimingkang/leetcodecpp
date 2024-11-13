#include "MyLinkedList.h"
#include <string>
void MyLinkedList::addAtHead(int data) {
	MyNode* tmp = new MyNode();
	tmp->data = data;
	tmp->next = head;
	this->head = tmp;
}
void MyLinkedList::addAtTail(int data) {
	MyNode* curr = this->getHead();

	while (curr->next != nullptr)
	{
		curr = curr->next;
	}

	MyNode* tmp = new MyNode();
	tmp->data = data;
	tmp->next = nullptr;
	curr->next = tmp;

}
void MyLinkedList::delAtTail(int index) {
}
void MyLinkedList::delAtHead(int index) {
}

MyNode* MyLinkedList::getHead() {
	return head;
}



void MyLinkedList::drawNode(SDL_Renderer* renderer, int x, int y, int value, bool hasNext) {
    // 绘制矩形框表示节点
    SDL_Rect nodeRect = { x, y, NODE_WIDTH, NODE_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // 蓝色
    SDL_RenderFillRect(renderer, &nodeRect);

    // 绘制节点值
    SDL_Color textColor = { 255, 255, 255, 255 }; // 白色文字
    std::string valueStr = std::to_string(value);

    // 此处需要使用SDL_ttf库来显示文本。若没有使用SDL_ttf库，可以注释掉此部分代码

    // 绘制箭头指向下一个节点
    if (hasNext) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色箭头
        SDL_RenderDrawLine(renderer, x + NODE_WIDTH, y + NODE_HEIGHT / 2, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2, y + NODE_HEIGHT / 2);
        SDL_RenderDrawLine(renderer, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2 - 5, y + NODE_HEIGHT / 2 - 5, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2, y + NODE_HEIGHT / 2);
        SDL_RenderDrawLine(renderer, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2 - 5, y + NODE_HEIGHT / 2 + 5, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2, y + NODE_HEIGHT / 2);
    }
}

void MyLinkedList::drawLinkedList(SDL_Renderer* renderer, MyNode* head) {
    int x = 50; // 初始 x 坐标
    int y = SCREEN_HEIGHT / 2 - NODE_HEIGHT / 2;

    MyNode* current = head;
    while (current != nullptr) {
        drawNode(renderer, x, y, current->data, current->next != nullptr);
        x += NODE_SPACING;
        current = current->next;
    }
}

// 入队
 void MyLinkedList::offer(int value) {
    MyNode* newMyNode = new MyNode(value);
    if (rear == nullptr) {
        head = rear = newMyNode;
        return;
    }
    rear->next = newMyNode;
    rear = newMyNode;
}

// 出队
void MyLinkedList::poll() {
    if (head == nullptr) {
        std::cout << "Queue(LinkedList)  is empty." << std::endl;
        return;
    }
    MyNode* temp = head;
    head = head->next;

    if (head == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

// 查看队首元素
int MyLinkedList::peek() const {
    if (head == nullptr) {
        std::cout << "Queue(LinkedList) is empty." << std::endl;
        return -1;
    }
    return head->data;
}

// 检查队列是否为空
bool MyLinkedList::isEmpty() const {
    return head == nullptr;
}