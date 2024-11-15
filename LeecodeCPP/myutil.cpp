#include "myutil.h"
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
	int moveSelectedNode = -1;
	int moveSelectedNodeVal = -1;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONUP) {
				int x = e.button.x;
				int y = e.button.y;
				switch (e.button.button)
				{
				
				case SDL_BUTTON_RIGHT:
				{
					//int nodeIndex = g->getNodeIndexAtPosition(x, y);
					if(moveSelectedNode!=-1)
					{
						g->vertices[moveSelectedNode]->p->x = x;
						g->vertices[moveSelectedNode]->p->y = y;
						
						g->drawGraph();
					}
					
				}
				break;

				default:
					//SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
					break;
				}
				break;
				moveSelectedNode = -1;
				selectedNode = -1; // 重置选择状态


			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x = e.button.x;
				int y = e.button.y;
				switch (e.button.button)
				{
				case SDL_BUTTON_LEFT:
				{
				

					int nodeIndex = g->getNodeIndexAtPosition(x, y);
					if (nodeIndex == -1) {
						g->addNode(x, y); // 在点击位置添加新节点
					}
					else {
						if (selectedNode == -1) {
							selectedNode = nodeIndex; // 选择第一个节点
							// 绘制节点
						//	SDL_SetRenderDrawColor(g->renderer, 0, 255, 0, 255); // green色节点
						//	g->drawCircle(g->vertices[selectedNode], NODE_RADIUS);
						//	SDL_RenderPresent(g->renderer);
						//	_sleep(250);
						}
						else {
							g->addEdge(selectedNode, nodeIndex); // 创建边
							selectedNode = -1; // 重置选择状态
						}
					}
					g->drawGraph();
				}
				break;
				case SDL_BUTTON_RIGHT:
				{
					 moveSelectedNode = g->getNodeIndexAtPosition(x, y);
				//	 g->vertices.erase(g->vertices.begin()+moveSelectedNode);
				//	 moveSelectedNodeVal = g->vertices[moveSelectedNode]->data;
				//	g->vertices[moveSelectedNode]->p->x = x;
				//	g->vertices[moveSelectedNode]->p->y = y;
					//selectedNode = -1; // 重置选择状态
				//	g->drawGraph();
				}
				break;

				default:
					//SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
				break;
				}
				break;
				
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {

				//example 7
				//g->levelOrderTraversal(g->root);
				
				//example 8
				//printf("max height:%d\n", g->maxHeight(g->root));
				

				//example 9
				//g->invertTree(g->root);
				//g->updateNodeXY(g->root,200);
				//g->drawTree(g->root);

				//example 10
				// MyNode * common=g->lowestCommonAncester(g->root, 41, 0);
				//printf("common :%d\n", common->data);
		
				//example 11
				g->hasPathSum(75);

				//g->root->p->x = g->root->p->x + 100;
 				//g->dfsPreorder(g->root);
				//g->levelOrderTraversal(g->root);
				//g->drawTree(g->root);
			}
		}

	}
	return 0;

}
int testLinkedList(MyLinkedList* list) {
	// 绘制链表
	list->drawLinkedList();
	


	// 等待退出
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
	return 0;

}