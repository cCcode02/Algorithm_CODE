#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define Change_to_integral 48

// �Է� ����
char A[1000] = { '\0', };
char B[1000] = { '\0', };

int main()
{
	scanf("%s %s", A, B);

	// �� �Է°��� �����ϴٸ� 0���� ó��
	if (strcmp(A, B) == 0)
	{
		printf("0\n");
		return 0;
	}

	int Atr_Length = (int)strlen(A);
	int Btr_Length = (int)strlen(B);

	// �� �ڸ����� ���� �����ϴ� ����
	int Set_degit = 0;
	// �� �ڸ��� ���� �̿��� ���� �ڸ������� ����ϰ� �ϴ� ����
	int A_n = 0;
	int B_n = 0;
	// ���� ū ����
	int the_Big_Length = 0;

	// �� �Է��� ���̰� ������ �� 
	// �Է��� ũ�� ���ϴ� ����
	bool Bigger_A = false;
	if (Atr_Length != Btr_Length)
	{
		if (Atr_Length > Btr_Length)
		{
			Set_degit = Atr_Length - Btr_Length;
			B_n = Set_degit;
			the_Big_Length = Atr_Length;
		}
		else
		{
			// �ڿ� ������ �Է��� �� ��ٸ� (�ڸ����� �� ũ�ٸ�)
			// �����̹Ƿ� (-) ��ȣ ���� ���
			Set_degit = Btr_Length - Atr_Length;
			A_n = Set_degit;
			the_Big_Length = Btr_Length;

			printf("-");
		}
	}
	else
	{
		the_Big_Length = Atr_Length;
		for (int i = 0; i < the_Big_Length; i++)
		{
			if (A[i] == B[i])
				continue;
			else
			{
				// ���̰� ������ ��
				// ���� �ڸ����� ���� ����
				// �ڿ� ������ �Է� �ڸ��� ������ ũ�Ⱑ �� ũ�ٸ� ���� �̹Ƿ�
				// (-) ��ȣ ���� ���
				if (A[i] < B[i])
				{
					Bigger_A = false;

					printf("-");
					break;
				}
				else
					Bigger_A = true;
			}
		}
	}

	// ���ڿ� ������ ������ ������ ġȯ�ϴ� �κ�
	for (int i = 0; i < the_Big_Length; i++)
	{
		if (i < Atr_Length)
			A[i] -= Change_to_integral;
		if (i < Btr_Length)
			B[i] -= Change_to_integral;
	}

	int result_index = 0;
	int Down = 0;
	int* result = malloc(sizeof(int) * the_Big_Length);

	if (result != NULL)
	{
		// ���� ���� ������ �б⹮�� ���� ���ڸ� ���� ������ �� �����ϰ�,
		// ���̿� ���� �Է°��� ��ġ�� �յڷ� �ٲ� �����ϱ� ������
		// �ش� �ݺ����� ���� ����δ� ������ ���� �� ����.

		// ���� �������� ���� ó���� �ʿ���.
		for (int i = the_Big_Length - 1; i >= 0; i--)
		{
			if (Atr_Length > Btr_Length || Bigger_A == true)
			{
				if (i < Set_degit)
				{
					if (Down == 1)
					{
						if (A[i - A_n] - Down < 0)
						{
							A[i - A_n] += 10;
							A[i - A_n] -= Down;
						}
						else
						{
							A[i - A_n] -= Down;
							Down = 0;
						}
					}
					result[result_index] = A[i];
				}
				else
				{
					if (Down == 1)
					{
						A[i - A_n] -= Down;
						Down = 0;
					}

					if (A[i - A_n] < B[i - B_n])
					{
						A[i - A_n] += 10;
						Down = 1;
					}
					result[result_index] = A[i - A_n] - B[i - B_n];
				}
			}
			else if (Atr_Length < Btr_Length || Bigger_A == false)
			{
				if (i < Set_degit)
				{
					if (Down == 1)
					{
						if (B[i - B_n] - Down < 0)
						{
							B[i - B_n] += 10;
							B[i - B_n] -= Down;
						}
						else
						{
							B[i - B_n] -= Down;
							Down = 0;
						}
					}
					result[result_index] = B[i];
				}
				else
				{
					if (Down == 1)
					{
						B[i - B_n] -= Down;
						Down = 0;
					}

					if (B[i - B_n] < A[i - A_n])
					{
						B[i - B_n] += 10;
						Down = 1;
					}
					result[result_index] = B[i - B_n] - A[i - A_n];
				}
			}
			result_index += 1;
		}
		// �� �Է°��� ���� ����� �� �Է°��� ���̺��� ª�ٸ� ������
		// 0�� ó���ϱ� ���� ����
		int non_exist_zero = 0;
		for (int i = the_Big_Length - 1; i >= 0; i--)
		{
			// result �� ���� 0�̰� zero üũ ������ 0 �� ���
			if (result[i] == 0 && non_exist_zero == 0)
				continue;
			// result �� ���� 0 �� �ƴ� ������ ������
			// zero üũ ������ 0�� �ƴ� ���� �ְ� 
			// �� ���� �ε������ʹ� ���������� ��½�Ű�� �κ�
			else
				non_exist_zero = 1;

			printf("%d", result[i]);
		}
	}

	// �޸� ����
	free(result);
	return 0;
}