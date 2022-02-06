#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define Change_to_integral 48

// 입력 값들
char A[1000] = { '\0', };
char B[1000] = { '\0', };

int main()
{
	scanf("%s %s", A, B);

	// 두 입력값이 동일하다면 0으로 처리
	if (strcmp(A, B) == 0)
	{
		printf("0\n");
		return 0;
	}

	int Atr_Length = (int)strlen(A);
	int Btr_Length = (int)strlen(B);

	// 두 자릿수의 차를 저장하는 변수
	int Set_degit = 0;
	// 각 자릿수 차를 이용해 같은 자릿수끼리 계산하게 하는 변수
	int A_n = 0;
	int B_n = 0;
	// 가장 큰 길이
	int the_Big_Length = 0;

	// 두 입력의 길이가 동일할 때 
	// 입력의 크기 비교하는 변수
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
			// 뒤에 나오는 입력이 더 길다면 (자릿수가 더 크다면)
			// 음수이므로 (-) 부호 개별 출력
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
				// 길이가 동일할 때
				// 같은 자릿수의 수를 보고
				// 뒤에 나오는 입력 자릿수 정수의 크기가 더 크다면 음수 이므로
				// (-) 부호 개별 출력
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

	// 문자열 정수를 정수형 정수로 치환하는 부분
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
		// 뺄셈 연산 전부터 분기문을 통해 앞자리 수를 가져온 후 연산하고,
		// 길이에 따라 입력값의 위치를 앞뒤로 바꿔 연산하기 때문에
		// 해당 반복문을 통한 결과로는 음수가 나올 수 없다.

		// 따라서 개별적인 음수 처리가 필요함.
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
		// 두 입력값의 연산 결과가 두 입력값의 길이보다 짧다면 나오는
		// 0을 처리하기 위한 변수
		int non_exist_zero = 0;
		for (int i = the_Big_Length - 1; i >= 0; i--)
		{
			// result 의 값이 0이고 zero 체크 변수가 0 일 경우
			if (result[i] == 0 && non_exist_zero == 0)
				continue;
			// result 의 값에 0 이 아닌 정수가 들어오면
			// zero 체크 변수에 0이 아닌 값을 주고 
			// 그 다음 인덱스부터는 정상적으로 출력시키는 부분
			else
				non_exist_zero = 1;

			printf("%d", result[i]);
		}
	}

	// 메모리 해제
	free(result);
	return 0;
}