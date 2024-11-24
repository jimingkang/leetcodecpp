#include "MyAdjlistGraph.h"

// 构造函数
MyAdjlistGraph::MyAdjlistGraph(SDL_Renderer*  renderer) {

	this->renderer = renderer;
    this->V=0;
    //adj.resize(V); // 调整大小
}

void MyAdjlistGraph::addNode(int v) {
	MyNode* vv = new MyNode(v);
	this->adj[v].push_back(vv);
	
	
}
void MyAdjlistGraph::addNode(int x,int y) {

	
	this->vertices.push_back(new MyNode(V, x, y));
	adj.push_back({});
	this->V++;

}
MyNode* MyAdjlistGraph::getNode(int v) {

	return this->vertices[v];

}
vector<MyNode*> MyAdjlistGraph::getNodeAdj(int v) {
	
	return adj[v];
}
// 添加边
void MyAdjlistGraph::addEdge(int v, int w) {
	
    adj[v].push_back(this->vertices[w]); // 添加 v -> w 的边
    adj[w].push_back(this->vertices[v]); // 如果是无向图，添加 w -> v 的边
}

// 打印图
void MyAdjlistGraph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "\n" << v << "";
        for (auto x : adj[v])
            cout << " " << x->val;
        cout << endl;
    }
}
// 绘制图
void MyAdjlistGraph::drawGraph() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 黑色用于边

	// 绘制边
	for (int i = 0; i < this->V; ++i) {
		for (MyNode* neighbor : this->adj[i]) {
			SDL_RenderDrawLine(renderer, this->vertices[i]->p->x, vertices[i]->p->y, neighbor->p->x, neighbor->p->y);
		}
	}

	// 绘制节点
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // 蓝色节点
	for (const auto& vertex : vertices) {
		for (int w = 0; w < NODE_RADIUS * 2; w++) {
			for (int h = 0; h < NODE_RADIUS * 2; h++) {
				int dx = NODE_RADIUS - w;
				int dy = NODE_RADIUS - h;
				if ((dx * dx + dy * dy) <= (NODE_RADIUS * NODE_RADIUS)) {
					SDL_RenderDrawPoint(renderer, vertex->p->x + dx, vertex->p->y + dy);
					
					SDL_RenderPresent(renderer);
				}
			}
		}
		const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";
		TTF_Font* font = TTF_OpenFont(font_path, 24);
		SDL_Rect rect;
		get_text_and_rect(vertex->p->x - 5, vertex->p->y - 10, vertex->val, font, &this->texture, &rect);
		SDL_RenderCopy(renderer, this->texture, NULL, &rect);
	}

	SDL_RenderPresent(renderer);
}
//dfs without SDL2
void MyAdjlistGraph::DFS(MyNode* v) {
    vector<bool> visited(V, false);
    stack<MyNode*> s;



    s.push(v);
    while (!s.empty()) {
		MyNode* node = s.top();
        s.pop();

        if (!visited[node->val]) {
            cout << node->val << " ";
            visited[node->val] = true;
        }

        // 将邻接节点添加到栈中
        for (auto i = adj[node->val].rbegin(); i != adj[node->val].rend(); ++i) {
			if (!visited[(*i)->val]) {
                s.push(*i);
            }
        }
    }
}


void MyAdjlistGraph::DFS(int startNode) {
    std::vector<bool> visited(V, false); // 初始化所有节点为未访问
    DFSUtil(this->vertices[startNode], visited);
}

// DFS递归函数，绘制路径
void MyAdjlistGraph::DFSUtil(MyNode* v, std::vector<bool>& visited) {
	
    visited[v->val] = true;
	

	//for (int i = 0; i < adj.size(); ++i) {        // 遍历每个节点的邻居列表

	//	for (MyNode* neighbor : adj[i]) {
			for (MyNode* neighbor : adj[v->val]) {
			if (!visited[neighbor->val]) {
				// 绘制从节点v到邻居节点的路径
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色路径
				SDL_RenderDrawLine(renderer, v->p->x, v->p->y, neighbor->p->x, neighbor->p->y);
				SDL_RenderPresent(renderer);
			
				std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 延迟显示路径

				// 递归访问邻居节点
				DFSUtil(neighbor, visited);
			}
		}
	//}
}






// 使用SDL绘制圆圈
void MyAdjlistGraph::drawCircle( int x, int y, int radius) {
	for (int w = 0; w < radius * 2; w++) {
		for (int h = 0; h < radius * 2; h++) {
			int dx = radius - w; // 水平偏移
			int dy = radius - h; // 垂直偏移
			if ((dx * dx + dy * dy) <= (radius * radius)) {

				SDL_RenderDrawPoint(renderer, x + dx, y + dy);
				//get_text_and_rect(renderer, 0, 0, "hello", font, &texture1, &rect1);
			}
		}
	}
}
#include <SDL2/SDL_ttf.h>



/*
- x, y: upper left corner.
- texture, rect: outputs.
*/
void MyAdjlistGraph::get_text_and_rect( int x, int y,int nodeNum,TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect
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

// 获取鼠标点击位置的节点索引
int MyAdjlistGraph::getNodeIndexAtPosition(int x, int y) {
	for (int i = 0; i < V; ++i) {

		int dx = x - (this->vertices)[i]->p->x;
		int dy = y - (this->vertices)[i]->p->y;
		if (std::sqrt(dx * dx + dy * dy) <= NODE_RADIUS) {
			return i;
		}
	}
	return -1; // 未找到节点
}


// 获取鼠标点击位置的节点索引

void MyAdjlistGraph::mousePress(SDL_MouseButtonEvent& b) {
	int x = b.x;
	int y = b.y;
	printf("%d,%d\n", b.x, b.y);
	// 绘制节点
	

	
}

void MyAdjlistGraph::mouseMove(SDL_MouseButtonEvent& b) {
	


}
void MyAdjlistGraph::mouseUp(SDL_MouseButtonEvent& b) {

	

}




