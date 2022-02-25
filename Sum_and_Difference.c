#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Sum, difference;
	scanf("%d\n%d", &Sum, &difference);

	int Cnt = 0;
	int First_element = 2, Second_element = 0;
	// 조건문이 모두 false 가 되야 반복이 멈추기 때문에
	// || (Or) 연산자를 이용해 위 조건을 모두 만족해야 반복이 멈추도록 함.
	// 조건 1) 두 요소의 합이 Sum 과 동일할 때
	// 조건 2) 두 요소의 차(순서 상관없음)가 difference 와 동일할 때 
	while (First_element + Second_element != Sum || First_element - Second_element != difference && Second_element - First_element != difference)
	{
		// 처음 반복일 경우
		if (Cnt != 1)
		{
			First_element = (Sum / First_element) + (Sum % First_element);
			Second_element = Sum - First_element;
		}
		else
			Second_element = Sum - First_element;

		// 두 요소의 합이 Sum과 동일할 때 (조건 1) 만족할 때)
		if (Second_element + First_element == Sum)
		{
			if (First_element > Second_element)
			{
				if (First_element - Second_element == difference)
					printf("%d\n%d\n", First_element, Second_element);
				else
				{
					First_element -= 1;
					Second_element = 0;
				}
			}
			else
			{
				if (Second_element - First_element == difference)
					printf("%d\n%d\n", Second_element, First_element);
				else
				{
					First_element -= 1;
					Second_element = 0;
				}
			}
			Cnt = 1;
		}
	}

	return 0;
}
