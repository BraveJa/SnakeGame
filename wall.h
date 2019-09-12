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

	void initWall(); //��ʼ��ǽ��ֵ
	void drawWall();  //����ǽ
	void setWall(int x,int y,char c);//����ǽ
	char getWall(int x,int y);       //��ȡǽ
private:
	char gameArray[ROW][COL];
};

