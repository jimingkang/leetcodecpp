#include "leetcode.h"
#include "MyNode.h"
int maxWater(vector<int>& v) {
	int left = 0;
	int right = v.size() - 1;
	int result = 0;
	while (left < right) {
		if (v[left] > v[right])
		{
			result = std::max(result, v[right] * (right - left));

			right--;
		}
		else {
			result = std::max(result, v[left] * (right - left));
			left++;
		}



	}
	return result;
}

// 示例地图
std::vector<std::vector<int>> grid = {
    {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
    {0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1}
};

void drawGrid() {
    // 设置背景为白色
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for (int row = 0; row < GRID_ROWS; ++row) {
        for (int col = 0; col < GRID_COLS; ++col) {
            SDL_Rect cell = { col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            if (grid[row][col] == 1) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // 蓝色代表陆地
            }
            else if(grid[row][col] == 2) {
                SDL_SetRenderDrawColor(renderer, 255, 0,0 , 255); // 红色代表已经访问的陆地
            }
            else {
                SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // 灰色代表水
            }
            SDL_RenderFillRect(renderer, &cell);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 黑色网格线
            SDL_RenderDrawRect(renderer, &cell);
        }
    }
    SDL_RenderPresent(renderer);
}

// 深度优先搜索标记岛屿
void dfs(int row, int col) {
    if (row < 0 || row >= GRID_ROWS || col < 0 || col >= GRID_COLS || grid[row][col] != 1) {
        return;
    }

    grid[row][col] = 2; // 标记为已访问
    drawGrid();         // 更新显示
    SDL_Delay(500);     // 延迟以便观察

    // 四个方向搜索
    dfs(row + 1, col);
    dfs(row - 1, col);
    dfs(row, col + 1);
    dfs(row, col - 1);
}

int countIslands() {
    int islandCount = 0;
    for (int row = 0; row < GRID_ROWS; ++row) {
        for (int col = 0; col < GRID_COLS; ++col) {
            if (grid[row][col] == 1) {
                ++islandCount;
                dfs(row, col); // 对每个新的岛屿进行DFS搜索
            }
        }
    }
    return islandCount;
}

int removeElement(vector<int>& nums, int val) {
    int val_cnt=0;
    int i = 0;
    int j = nums.size() - 1;
    while(i<=j)
        {
            if (nums[j] == val)
            {
                val_cnt++;
                if(j>0)
                j--;
            }
               

            if (nums[i] == val && nums[j] != val)
            {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                val_cnt++;
                i++;
                j--;

            }
            else if ((nums[i] != val))
            {
                i++;

            }
        }

    return nums.size()-val_cnt;
}


int getMinimumDifference(MyNode* root) {
     int min = 10000;

    minimumDifference(root,min);
    return min;
}



void minimumDifference(MyNode* root, int & min) {
    static int pre=-1;
    
    if (root == nullptr)
        return ;
  
    
       minimumDifference(root->left,min);
       if(pre!=-1)
       min = std::min(min, abs(root->val - pre));
 
    
       pre = root->val;


       minimumDifference(root->right,min);
    



}
bool isSameTree(MyNode* p, MyNode* q) {

    if ((p == nullptr && q == nullptr))
        return true;
    else if ((p != nullptr && q == nullptr) && (p == nullptr && q != nullptr))
        return false;
    bool flag = true;
    if((p != nullptr && q != nullptr))
        flag= p->val == q->val;


    return flag&&isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int ret;
int kthSmallest(MyNode* root, int k) {
  
    find(root, k);
    return ret;


}
void find(MyNode* root, int k) {
    static int cnt;
    if (root == nullptr)
        return;


    find(root->left, k);
    cnt++;
    if (cnt == k)
        ret = root->val;

    find(root->right, k);
}

int tmpmax;
int maxPathSum(MyNode* root) {
    //method1
    
      //  maxV(root);
      //  return tmpmax;

    int sum = 0;
    int total = -10000;
    vector<int> v;
    inOrder(root, v);
    for (int item : v) {
        if (sum < 0)
            sum = 0;
        sum =  sum + item;
        total = max(total, sum);

    }
    return total;
}

//method1
int maxV(MyNode* root) {
    if (root == nullptr)
    {
        return 0;
    }

    int     leftValue = maxV(root->left);
    int   rightValue = maxV(root->right);

   // tmpmax = max(tmpmax, max(root->val, root->val + max({ leftValue, rightValue,leftValue + rightValue })));


    return  max(root->val, root->val + max(leftValue, rightValue));
}
//method2
void inOrder(MyNode* root, vector<int> & v) {
    if (root == nullptr)
        return;
    inOrder(root->left, v);
    v.push_back(root->val);
    inOrder(root->right, v);

}


//leetcode 129

int sumNumbers(MyNode* root) {
    int sum = 0;
    sumNumber(root, sum);
    return sum;
}
int sumNumber(MyNode* root, int& sum) {
    if (root == nullptr)
    {
        return  0;
    }
    if (root != nullptr && root->left == nullptr && root->right == nullptr)
    {
        return  root->val;
    }
    sum += root->val*10;
    

    int l = sumNumber(root->left, sum);
    int r = sumNumber(root->right, sum);
    sum +=l;
    sum +=r;
    return sum;


}


