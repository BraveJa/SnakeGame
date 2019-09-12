#pragma once
#include <iostream>
#include <string>
using namespace std;

class Wall
{
public:
	enum 
	{
		ROW=23,
		COL=23
	};

	void initWall(); //初始化墙的值
	void drawWall();  //画出墙
	void setWall(int x,int y,char c);//设置墙
	char getWall(int x,int y);       //获取墙
private:
	char gameArray[ROW][COL];
};

