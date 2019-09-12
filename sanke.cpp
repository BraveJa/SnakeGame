#include "sanke.h"

Snake::Snake(Wall& tempWall,Food &tempFood):wall(tempWall),food(tempFood)
{
	pHead = NULL;
	isRool = false;
}

void Snake::initSnake()
{
	destoryPoint();
	addPoint(5,3);
	addPoint(5,4);
	addPoint(5,5);

}

void Snake::destoryPoint()
{
	Point* pCur = pHead;
	while (pHead!=NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{
	//创建新节点
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//如果原来的头不为空 ,应该变为身体
	if (pHead!=NULL)
	{
		wall.setWall(pHead->x,pHead->y,'=');

	}
	newPoint->next = pHead;

	pHead = newPoint;
	wall.setWall(x,y,'@');
}

void Snake::deletPoint()
{
	if (pHead ==NULL ||pHead->next==NULL)
	{

		return;
	}

	Point* pCur = pHead->next;
	Point* pPre = pHead;

	while (pCur->next!=NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//删除节点
	wall.setWall(pCur->x,pCur->y,' ');
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case RIGHT:
		y++;
		break;
	case LEFT:
		y--;
		break;
	default:
		break;
	}
	//判断 如果是下一步碰到的是尾巴，不应该死亡
	Point* pCur = pHead->next;
	Point* pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->x == x && pCur->y == y)
	{
		//碰到尾巴 循环
		isRool = true;
	}
	else
	{
		//判断用户到达位置是否成功
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			addPoint(x, y);
			deletPoint();
			system("cls");
			wall.drawWall();
			cout << "GAME OVER!!!" << endl;
			return false;
		}
	}
	//移动成功 分两种  
	//吃到食物  未吃到食物
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);

		//重新设置食物
		food.setFood();
	}
	else
	{
		addPoint(x, y);
		deletPoint();
		if (isRool == true)
		{
			wall.setWall(x, y, '@');
		}

	}

	return true;

}
