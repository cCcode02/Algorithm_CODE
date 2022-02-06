#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �ƽ�Ű �ڵ� ���� �̿��� ���ڸ� ������ ���
#define transform_int 48
#define array arr

// ���ڿ��� ������ ġȯ
void Change_int(char str[], char Str[], int str_index, int Str_index)
{
	int i;
	for (i = 0; i < (str_index > Str_index ? str_index : Str_index); i++)
	{
		if (i < str_index)
			str[i] -= transform_int;
		if (i < Str_index)
			Str[i] -= transform_int;
	}
}

// ���� �ʱ�ȭ�� ���� ���� ���� ����
char A_arr[10001] = { '\0', };
char B_arr[10001] = { '\0' };

int main()
{
	scanf("%s\n%s", A_arr, B_arr);

	// ���ڿ��� ���� 
	int A_Length = (int)strlen(A_arr);
	int B_Length = (int)strlen(B_arr);

	Change_int(A_arr, B_arr, A_Length, B_Length);

	// �ڸ����� ���߱� ���� ���ڿ� ������ ���� ���� 
	// �ش� ���� ��ŭ ���� �迭�� �����ֱ� ���ؼ�
	int deff_degit = 0;
	int Bigger_length = 0;
	// �ε��� ���ߴ� ���� 
	int An_a = 0;
	int An_b = 0;

	// �� �迭 ����
	if (A_Length > B_Length)
	{
		Bigger_length = A_Length;
		deff_degit = Bigger_length - B_Length;

		An_b = deff_degit;
	}
	else
	{
		Bigger_length = B_Length;
		deff_degit = Bigger_length - A_Length;

		An_a = deff_degit;
	}

	// �ڸ��� �ø�
	int carry = 0;
	int* Plate = malloc(sizeof(int) * Bigger_length);

	int i;
	int Plate_index = 0;
	if (Plate)
	{
		for (i = Bigger_length - 1; i >= 0; i--)
		{
			if (i < deff_degit)
			{
				if (Bigger_length != B_Length)
					Plate[Plate_index] = A_arr[i] + carry;
				else
					Plate[Plate_index] = B_arr[i] + carry;
			}
			else
				Plate[Plate_index] = A_arr[i - An_a] + B_arr[i - An_b] + carry;

			// ���� �ڸ��� �ִٸ� �ڸ����� �ö󰡰� ���ٸ� �ʱ�ȭ
			carry = Plate[Plate_index] / 10;

			// ���� �ڸ��� ����
			Plate[Plate_index] %= 10;
			Plate_index += 1;
		}
	}

	for (i = Plate_index - 1; i >= 0; i--)
	{
		if (i == Plate_index - 1 && carry == 1)
			printf("1");
		printf("%d", Plate[i]);
	}

	free(Plate);
	return 0;
}

// �Է� ���� ���� �д� �����Ͱ� �޶����� ������ ��� �߻���
// �����ص� ��� ����.
