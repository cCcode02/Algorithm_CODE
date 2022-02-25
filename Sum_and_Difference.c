#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Sum, difference;
	scanf("%d\n%d", &Sum, &difference);

	int Cnt = 0;
	int First_element = 2, Second_element = 0;
	// ���ǹ��� ��� false �� �Ǿ� �ݺ��� ���߱� ������
	// || (Or) �����ڸ� �̿��� �� ������ ��� �����ؾ� �ݺ��� ���ߵ��� ��.
	// ���� 1) �� ����� ���� Sum �� ������ ��
	// ���� 2) �� ����� ��(���� �������)�� difference �� ������ �� 
	while (First_element + Second_element != Sum || First_element - Second_element != difference && Second_element - First_element != difference)
	{
		// ó�� �ݺ��� ���
		if (Cnt != 1)
		{
			First_element = (Sum / First_element) + (Sum % First_element);
			Second_element = Sum - First_element;
		}
		else
			Second_element = Sum - First_element;

		// �� ����� ���� Sum�� ������ �� (���� 1) ������ ��)
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
