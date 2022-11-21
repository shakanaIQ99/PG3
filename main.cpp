#include <stdio.h>
#include<Windows.h>
#include <stdlib.h>
#include <time.h>
#include<functional>

int main(void)
{


	int choicenum;
	int timer = 3;

	printf("”¼‚©’š‚©\n1:”¼ 2:’š\n");
	scanf_s("%d", &choicenum);

	const int dicesize = 6;
	int dice;

	srand(time(NULL));
	dice = rand() % dicesize + 1;

	std::function<void()>choice = [&]() {printf("%s\n", (choicenum == 1) ? "‘I‘ð‚Í”¼" : "‘I‘ð‚Í’š"); };


	std::function<void()>anser = [&]() {printf("%s\n", (dice % 2) ? "“š‚¦‚Í”¼" : "“š‚¦‚Í’š"); };

	std::function<void(std::function<void()>, int)> setTimeout = [](std::function<void()> fx, int second) {fx(); Sleep(second * 1000); };

	setTimeout(choice, timer);
	anser();

	system("pause");
	return 0;
}