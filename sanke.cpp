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
	//�����½ڵ�
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//���ԭ����ͷ��Ϊ�� ,Ӧ�ñ�Ϊ����
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
	//ɾ���ڵ�
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
	//�ж� �������һ����������β�ͣ���Ӧ������
	Point* pCur = pHead->next;
	Point* pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->x == x && pCur->y == y)
	{
		//����β�� ѭ��
		isRool = true;
	}
	else
	{
		//�ж��û�����λ���Ƿ�ɹ�
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
	//�ƶ��ɹ� ������  
	//�Ե�ʳ��  δ�Ե�ʳ��
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);

		//��������ʳ��
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
