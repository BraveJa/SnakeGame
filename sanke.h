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
		//������
		int x;
		int y;
		//ָ����
		Point* next;

	};
	//��ʼ����
	void initSnake();
	//������
	void destoryPoint();
	//�������
	void addPoint(int x,int y);
	//ɾ���ڵ�
	void deletPoint();
	//�ƶ��߲���
	//����ֵ�����ƶ��Ƿ�ɹ�
	bool move(char key);

	//��ͷ�ڵ�
	Point* pHead;
	//��ʼ����ʱ��Ͱ�wall������
	Wall& wall; 
	//ʳ��
	Food& food;
	bool isRool; //�ж�ѭ����ʾ
};

