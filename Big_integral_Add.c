#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 아스키 코드 값을 이용해 문자를 정수로 취급
#define transform_int 48
#define array arr

// 문자열을 정수로 치환
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

// 스택 초기화로 인해 전역 변수 선언
char A_arr[10001] = { '\0', };
char B_arr[10001] = { '\0' };

int main()
{
	scanf("%s\n%s", A_arr, B_arr);

	// 문자열의 길이 
	int A_Length = (int)strlen(A_arr);
	int B_Length = (int)strlen(B_arr);

	Change_int(A_arr, B_arr, A_Length, B_Length);

	// 자릿수를 맞추기 위해 문자열 길이의 차를 구함 
	// 해당 차이 만큼 작은 배열에 더해주기 위해서
	int deff_degit = 0;
	int Bigger_length = 0;
	// 인덱스 맞추는 변수 
	int An_a = 0;
	int An_b = 0;

	// 긴 배열 기준
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

	// 자릿수 올림
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

			// 십의 자리가 있다면 자릿수로 올라가고 없다면 초기화
			carry = Plate[Plate_index] / 10;

			// 일의 자리만 남김
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

// 입력 값에 따라 읽는 데이터가 달라지기 때문에 경고가 발생함
// 무시해도 상관 없음.
