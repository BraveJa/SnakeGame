#pragma once
#include<iostream>
#include "wall.h"
#include "food.h"
using namespace std;

class Snake
{
public:
	Snake(Wall &tempWall,Food &tempFood);

	enum 
	{
		UP='w',
		DOWN='s',
		RIGHT='d',
		LEFT='a'
	};

	struct Point
	{
		//数据域
		int x;
		int y;
		//指针域
		Point* next;

	};
	//初始化蛇
	void initSnake();
	//销毁蛇
	void destoryPoint();
	//添加蛇身
	void addPoint(int x,int y);
	//删除节点
	void deletPoint();
	//移动蛇操作
	//返回值代表移动是否成功
	bool move(char key);

	//蛇头节点
	Point* pHead;
	//初始化的时候就把wall复制了
	Wall& wall; 
	//食物
	Food& food;
	bool isRool; //判断循环标示
};

