#pragma warning(disable:4244)
#pragma warning(disable:4996)
#include <iostream>
//#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include <stdio.h>
#include "tree.h"
using namespace std;
//��������� �������
Tree tournament;
void Game(char Commands[][20], int N)
{
	int i, j;
	int p1, p2; //����
	//������ ������� ������ � ������ �� 2 ���� -
	//���� � � ������
	int k;
	Elem* temp;
	for (k = 0; k < 2; k++)
		for (i = 0; i < N - 1; i++)
		{
			for (j = i + 1; j < N; j++)
			{
				temp = new Elem;
				if (k == 0)
				{
					//1 ����
					strcpy(temp->Name, Commands[i]);
					strcpy(temp->Opponent, Commands[j]);
				}
				else
				{
					//2 ����
					strcpy(temp->Name, Commands[j]);
					strcpy(temp->Opponent, Commands[i]);
				}
				p1 = rand() % 6;
				p2 = rand() % 6;
				if (p1 > p2)
				{
					temp->OwnerPoints = 3;
					temp->OppPoints = 0;
				}
				else if (p1 == p2)
				{
					temp->OwnerPoints = 1;
					temp->OppPoints = 1;
				}
				else
				{
					temp->OwnerPoints = 0;
					temp->OppPoints = 3;
				}
				//������ �����
				sprintf(temp->Match, " %d : %d ", p1, p2);
				//���������� ������
				tournament.Insert(temp);
			}
		}
}
int main()
{
	srand(time(0));
	const int N = 4;
	char Commands[4][20] =
	{
	"Arsenal",
	"Liverpool",
	"Lids United",
	"Manchester United"
	};
	//����
	Game(Commands, N);
	//����� �����������
	tournament.Print(tournament.GetRoot());
	return 0;
}