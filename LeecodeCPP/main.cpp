#include <memory>


#include "myutil.h"

 int NODE_WIDTH = 60;      // 节点宽度
 int NODE_HEIGHT = 40;     // 节点高度
 int NODE_SPACING = 80;    // 节点之间的间隔

 int SCREEN_WIDTH = 800;
 int SCREEN_HEIGHT = 600;
 int NODE_RADIUS = 20;
 int DFS_DELAY_MS = 100; // 每次绘制路径之间的延迟时间（毫秒）
  int GRID_ROWS = 10;  // 网格行数
  int GRID_COLS = 10;  // 网格列数
  int CELL_SIZE = 40;  // 每个单元格的大小（像素）;;
// example 5//


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

  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
int main(int argc,char ** argv) {
	// example 1
	/*
	 MyLinkedList *l = new MyLinkedList();
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
	 window = SDL_CreateWindow("DFS Path Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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

	//example7 MyList
	//MyLinkedList list(renderer);
	//list.addAtHead(3);
	//list.addAtHead(2);
	//list.addAtHead(1);
	//list.addAtHead(4);
	//list.addAtHead(5);
	//testLinkedList(&list);

	//leetcode island issue
	//drawGrid();
	//int islandCount = countIslands();
	//std::cout << "Number of islands: " << islandCount << std::endl;

	// 关闭SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}



