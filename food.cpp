#include "food.h"

Food::Food(Wall &tempWall):wall(tempWall)
{
}

void Food::setFood()
{
	while (true)
	{

	foodX = rand() % (Wall::ROW - 2 )+ 1;
	foodY = rand() % (Wall::COL - 2) + 1;
	//如果是蛇身体就不要把食物生成在蛇身上
	if (wall.getWall(foodX,foodY)==' ')
	{
		wall.setWall(foodX, foodY, '#');
		break;
	}

	}

}
