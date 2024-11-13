#include <memory>
#include "MyAdjlistGraph.h"
#include "leetcode.h"
#include "MyLinkedList.h"
#include "MyAdjmatrixGraph.h"

#include "MyTree.h"


#include "main.h"


// example 5//

int test(MyAdjlistGraph* g) {
	





	// 保持窗口打开
	bool quit = false;
	SDL_Event e;
	int selectedNode = -1;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x = e.button.x;
				int y = e.button.y;

				int nodeIndex = g->getNodeIndexAtPosition(x, y);
				if (nodeIndex == -1) {
					g->addNode(x, y); // 在点击位置添加新节点
				}
				else {
					if (selectedNode == -1) {
						selectedNode = nodeIndex; // 选择第一个节点
					}
					else {
						g->addEdge(selectedNode, nodeIndex); // 创建边
						selectedNode = -1; // 重置选择状态
					}
				}
				g->drawGraph();
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
				g->printGraph();
				g->DFS(0); // 按下空格键时从节点0开始DFS
			}
		}

	}
	return 0;

}

//example 6

int testMyTree(MyTree* g) {






	// 保持窗口打开
	bool quit = false;
	SDL_Event e;
	int selectedNode = -1;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x = e.button.x;
				int y = e.button.y;

				int nodeIndex = g->getNodeIndexAtPosition(x, y);
				if (nodeIndex == -1) {
					g->addNode(x, y); // 在点击位置添加新节点
				}
				else {
					if (selectedNode == -1) {
						selectedNode = nodeIndex; // 选择第一个节点
					}
					else {
						g->addEdge(selectedNode, nodeIndex); // 创建边
						g->drawTree(g->root);
						selectedNode = -1; // 重置选择状态
					}
				}
				g->drawGraph();
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
				g->dfsPreorder(g->root);
			}
		}

	}
	return 0;

}

/*
// 构建二叉树并设置节点位置
MyNode* root = new MyNode(1, SCREEN_WIDTH / 2, 50);
root->left = new MyNode(2, SCREEN_WIDTH / 4, 150);
root->right = new MyNode(3, 3 * SCREEN_WIDTH / 4, 150);
root->left->left = new MyNode(4, SCREEN_WIDTH / 8, 250);
root->left->right = new MyNode(5, SCREEN_WIDTH / 4 + SCREEN_WIDTH / 8, 250);
root->right->left = new MyNode(6, 3 * SCREEN_WIDTH / 4 - SCREEN_WIDTH / 8, 250);
root->right->right = new MyNode(7, 7 * SCREEN_WIDTH / 8, 250);

// 清空屏幕并绘制初始二叉树
SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // 白色背景
SDL_RenderClear(renderer);
MyTree* p = new MyTree(root);
p->drawTree(renderer, root);

// 执行DFS遍历并动态显示过程
p->dfsPreorder(root, renderer);

*/
/**/

int main(int argc,char ** argv) {
	// example 1
	/* MyLinkedList *l = new MyLinkedList();
	l->addAtHead(1);
	l->addAtHead(2);
	l->print();

	l->addAtTail(3);
	l->print();

	*/

	// example 2/
	/*
	vector<int> v;
	v.push_back(10);
	v.push_back(5);
	v.push_back(4);
	v.push_back(0);
	v.push_back(8);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it;
	}

	std::cout << maxWater(v) <<" " << std::endl;
	*/
		// example 3/
		/**/
	

	SDL_Rect rect1, rect2;
	SDL_Texture* texture1, * texture2;

	const char* font_path = "C:/Users/ET/source/repos/leetcodecpp/x64/Debug/FreeSans.ttf";


	// 初始化SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return 1;
	}


	TTF_Init();
	TTF_Font* font = TTF_OpenFont(font_path, 24);
	if (font == NULL) {
		fprintf(stderr, "error: font not found\n");
		exit(EXIT_FAILURE);
	}
	SDL_Window* window = SDL_CreateWindow("DFS Path Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}


	//example 5
	//MyAdjlistGraph g1(renderer);
	//test(&g1);
	

	//example 6 test MyTree
	//MyNode* root = new MyNode(0);
	MyTree* p = new MyTree(renderer);
	testMyTree(p);

	// 关闭SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}



