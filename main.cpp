#include <stdio.h>
#include<Windows.h>
#include <stdlib.h>
#include <time.h>
#include<functional>



void setTimeout(int second)
{
	Sleep(second * 1000);

}

int main(void)
{
	

	int choicenum;
	int timer = 3;
	

	printf("”¼‚©’š‚©\n1:”¼ 2:’š\n");
	scanf_s("%d", &choicenum);

	std::function<void()>anser = []() 
	{
		srand(time(NULL));
		const int dicesize = 6;
		int dice;

		dice = rand() % dicesize + 1;

		if (dice % 2 == 0)
		{
			printf("o–Ú%d:’š!\n", dice);

		}
		if (dice % 2 == 1)
		{
			printf("o–Ú%d:”¼!\n", dice);
		}
	};

	
	setTimeout(timer);
	anser();
	
	return 0;
}