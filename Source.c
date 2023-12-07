﻿#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	run();
}

int run(void)
{
	int taskNumber;
	printf("Task number: "); scanf_s("%d", &taskNumber);

	switch (taskNumber)
	{
	case 0:
		exit(1);
	case 1:
		task1(); printf("\n"); run();
	case 2:
		task2(); printf("\n"); run();
	case 3:
		task3_1(); printf("\n"); run();
	case 4:
		task4(); printf("\n"); run();
	case 10:
		task10(); printf("\n"); run();
	case 11:
		task1_1(); printf("\n"); run();
	default:
		printf("error");
	}
}


#define I1 7
#define I2 7
int task1_1(void)
{
	int M[I1][I2];
	unsigned i, j;
	for (i = 0; i < I1; i++)     //rows
		for (j = 0; j < I2; j++) //cols
			M[i][j] = i * j;
	do {
		printf("Enter indexes:\n");
		printf("Exit: enter indexes > 7 \n");
		scanf_s("%d", &i);
		scanf_s("%d", &j);
		if (i <= I1 && j <= I2)
			printf("M[%d][%d] == %d\n", i, j, M[i][j]);
		else break;
	} while (1);

	for (i = 0; i < I1; i++)
	{
		for (j = 0; j < I2; j++)
			printf("\t%d", M[i][j]);
		printf("\n");
	}   printf("For exit enter any key...\n");

	getch();
}

#define MI1 3
#define MI2 3
int task1(void)
{
	int M[MI1][MI2];
	int sum = 0, minSum;
	int i, j;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10; // % 10 - from 0 to 10
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}	

	for (j = 0; j < MI2; j++) {
		sum = sum + M[0][j]; 
	}
	minSum = sum;

	for (i = 0; i < MI1; i++) {
		sum = 0;
		for (j = 0; j < MI2; j++) {
			sum = sum + M[i][j]; 
		}
		printf("%d", sum); printf("\n");

		if (minSum > sum) {
			minSum = sum;
		}
	}

	printf("min sum = %d", minSum); printf("\n");
}

int task2(void)
{
	int M[MI1][MI2];
	int total = 0, closest = 0, closestElt;
	float average;
	int i, j, x = 0, y = 0;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10; // % 10 - from 0 to 10
		}
	}
	closestElt = M[0][0];

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			total += M[i][j];
		}
	}

	printf("total = %d", total); printf("\n");

	average = ((float)total / (MI1 * MI2));
	printf("avg = %.2lf", average); printf("\n");

	closest = abs((average - M[0][0]));

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			if (closest > abs((average - M[i][j]))) {
				closest = abs((average - M[i][j]));
				closestElt = M[i][j];
				x = i; y = j;
			}
		}
	}

	printf("closest to average is M[%d][%d] = %d", x, y, closestElt);
}

int task3(void)
{
	int M[MI1][MI2];
	int count = 0;
	int final = 0;
	int i, j, x, y;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}


	
	for (i = 0; i < MI1; i++)
	{
		for (j = i+1; j < MI2; j++)
		{
			if (M[i] == M[j]) {
				count++;
				break;
			}
		}
	}


	printf("%d", count);
}

#define ROWS 3
#define COLS 3
int task3_1(void)
{
	int array[ROWS][COLS];
	int i, j, total = 0;
	int counts[10] = { 0 }; // Предполагаем, что работаем только с цифрами от 0 до 9


	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			array[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("\t%d", array[i][j]);
		}
		printf("\n");
	}

	// Подсчет повторяющихся цифр
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			int currentDigit = array[i][j];

			// Увеличиваем счетчик для текущей цифры
			counts[currentDigit]++;
		}
	}

	// Вывод результатов
	for (int i = 0; i < 10; i++) {
		if (counts[i] > 1) {
			printf("Digit %d repeats %d times.\n", i, counts[i]);
			total += counts[i];
		}
	}

	printf("total - %d", total);

	return 0;
}

int task4(void)
{
	int M[MI1][MI2];
	int k = 0, i, j, index = -1;
	int a;

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			M[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < MI1; i++) {
		for (j = 0; j < MI2; j++) {
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	printf("input a: "); scanf("%d", &a);

	for (i = 0; i < MI1; i++) {
		k = 0;
		for (j = 0; j < MI2; j++) {
			if (M[i][j] % a == 0) {
				k++;
			}
			if (k == MI2) {
				if (index < i) {
					index = i;
				}
			}
		}
	}
	printf("%d", index);
}

int task10(void)
{
	int M[MI1][MI2];
	int i, j, sum, fsum = 100;

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			M[i][j] = rand() % 10; // % 10 - from 0 to 10
		}
	}

	for (i = 0; i < MI1; i++)
	{
		for (j = 0; j < MI2; j++)
		{
			printf("\t%d", M[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < MI1; i++)
	{
		for (j = 1; j < MI2; j++)
		{
			sum = M[i][j] + M[i + i][j ]; //arrays way of work
		}

		if (fsum > sum) {
			fsum = sum;
		}

	}

	printf("%d", fsum);

}