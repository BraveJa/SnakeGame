// SankeGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "wall.h"
#include"sanke.h"
#include"food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>
int main()
{
	bool isDead = false;
	char preKey = NULL;
	//添加随机种子
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();

	
	Food food(wall);
	food.setFood();
	Snake snake(wall,food);
	snake.initSnake();
	snake.move('w');
	snake.move('w');
	snake.move('a');
	wall.drawWall();

	while (!isDead)
	{
		//接收用户输入
		char key = getchar();
		if (preKey ==NULL&&key==snake.LEFT)//第一次按左键不能激活游戏
		{
			continue;
		}
		do
		{
			if (key == snake.LEFT|| key == snake.RIGHT|| key == snake.DOWN|| key == snake.UP)
			{
				//判断本次按键 是否与上次冲突
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;
				}
				else
				{
					preKey = key; //不是冲突按键  可以更新按键
				}

				if (snake.move(key) == true)
				{
					//移动成功
					system("cls");//清屏
					wall.drawWall();
					Sleep(100);//睡眠
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key == preKey;
			}
		} while (!_kbhit());//没有输入的时候一直返回0
		
	}
	
}

