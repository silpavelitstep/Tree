#pragma warning(disable:4244)
#pragma warning(disable:4996)
#include <iostream>
#include "inner.h"
//#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include <stdio.h>
#include "tree.h"
using namespace std;
//Турнирная таблица
Tree<Inner> tournament;
void Game(char Commands[][20], int N)
{
	int i, j;
	int p1, p2; //Счет
	//Каждая команда играет с каждой по 2 раза -
	//дома и в гостях
	int k;
	Elem<Inner>* temp;
	for (k = 0; k < 2; k++)
		for (i = 0; i < N - 1; i++)
		{
			for (j = i + 1; j < N; j++)
			{
				temp = new Elem<Inner>;
				if (k == 0)//1 игра
				{
					strcpy(temp->inn->Name, Commands[i]);
					strcpy(temp->inn->Opponent, Commands[j]);
				}
				else//2 игра
				{
					strcpy(temp->inn->Name, Commands[j]);
					strcpy(temp->inn->Opponent, Commands[i]);
				}
				p1 = rand() % 6;
				p2 = rand() % 6;
				if (p1 > p2)
				{
					temp->inn->OwnerPoints = 3;
					temp->inn->OppPoints = 0;
				}
				else if (p1 == p2)
				{
					temp->inn->OwnerPoints = 1;
					temp->inn->OppPoints = 1;
					
				}
				else
				{
					temp->inn->OwnerPoints = 0;
					temp->inn->OppPoints = 3;
				}
				//Запись счета

				sprintf(temp->inn->Match, " %d : %d ", p1, p2);
				//Добавление записи
				tournament.Insert(temp);
			}
		}
}
void table() {
	srand(time(0));
	const int N = 4;
	char Commands[N][20] =
	{
	"Arsenal",
	"Liverpool",
	"Lids United",
	"Manchester United"
	};
	//Игра
	Game(Commands, N);
	//Вывод результатов
	tournament.Print(tournament.GetRoot());
}
int main()
{
	table();
	
	system("pause");
	return 0;
}