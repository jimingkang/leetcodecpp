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

    //for queue rear pointer
    rear->next = tmp;
    rear = tmp;

}
void MyLinkedList::delAtTail(int index) {
}
void MyLinkedList::delAtHead(int index) {
}

MyNode* MyLinkedList::getHead() {
	return head;
}


// 入队
void MyLinkedList::offer(MyNode *node) {
    if (rear == nullptr) {
        head = rear = node;
        return;
    }
    rear->next = node;
    rear = node;
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
   // delete temp;  //no need to delete the  node ,because we just look the node in the  MyTree::levelOrderTraversal, we need the node for the MyTree 
}

// 查看队首元素
MyNode* MyLinkedList::peek()  {
    if (head == nullptr) {
        std::cout << "Queue(LinkedList) is empty." << std::endl;
        return nullptr;
    }
    return head;
}

// 检查队列是否为空
bool MyLinkedList::isEmpty() const {
    return head == nullptr;
}


void MyLinkedList::drawNode( int x, int y, int value, bool hasNext) {
    // 绘制矩形框表示节点
    SDL_Rect nodeRect = { x, y, NODE_WIDTH, NODE_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // 蓝色
    SDL_RenderFillRect(renderer, &nodeRect);

    // 绘制节点值
    SDL_Color textColor = { 255, 255, 255, 255 }; // 白色文字
    std::string valueStr = std::to_string(value);

    // 此处需要使用SDL_ttf库来显示文本。若没有使用SDL_ttf库，可以注释掉此部分代码
    const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";
    TTF_Font* font = TTF_OpenFont(font_path, 24);
    SDL_Rect rect;
    get_text_and_rect(x - 5, y - 10, value, font, &this->texture, &rect);
    SDL_RenderCopy(renderer, this->texture, NULL, &rect);

    // 绘制箭头指向下一个节点
    if (hasNext) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色箭头
        SDL_RenderDrawLine(renderer, x + NODE_WIDTH, y + NODE_HEIGHT / 2, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2, y + NODE_HEIGHT / 2);
        SDL_RenderDrawLine(renderer, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2 - 5, y + NODE_HEIGHT / 2 - 5, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2, y + NODE_HEIGHT / 2);
        SDL_RenderDrawLine(renderer, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2 - 5, y + NODE_HEIGHT / 2 + 5, x + NODE_WIDTH + NODE_SPACING - NODE_WIDTH / 2, y + NODE_HEIGHT / 2);
    }
}


/*
- x, y: upper left corner.
- texture, rect: outputs.
*/
void MyLinkedList::get_text_and_rect(int x, int y, int nodeNum, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect
) {
    int text_width;
    int text_height;
    SDL_Surface* surface;
    SDL_Color textColor = { 255, 255, 255, 0 };

    char str[12];
    sprintf(str, "%d", nodeNum);
    surface = TTF_RenderText_Solid(font, str, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}
void MyLinkedList::drawLinkedList() {
    static int x = 50; // 初始 x 坐标
    static int y = 100;
   //  SDL_RenderClear(renderer);

    MyNode* current = head;
    while (current != nullptr) {
        drawNode( x, y, current->data, current->next != nullptr);
        x += NODE_SPACING;
       current = current->next;
      
    }
    x = NODE_SPACING;
    y += NODE_SPACING;
    SDL_RenderPresent(renderer);
}
