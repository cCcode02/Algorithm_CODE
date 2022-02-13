#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define array arr

int Compare_arr[1000000] = { 0, };

int main()
{
	int B_input = 0;
	int N_input = 0;
	scanf("%d %d", &B_input, &N_input);

	int the_Closest_num = 0;
	int Limit_cnt = 0;
	for (int i = 1; i <= B_input; i++)
	{
		// 해당 변수의 제곱승 값이 B 보다 크다면 반복문 탈출
		if (Limit_cnt == 1)
			break;
		else
		{
			int temp = 1;
			// 임시 저장 변수에 제곱 계산 결과 대입
			for (int Repeat = 0; Repeat < N_input; Repeat++)
				temp *= i;

			Compare_arr[i - 1] = temp;
			// 제곱승 값이 B 값보다 큰지 확인
			if (temp > B_input)
				Limit_cnt = 1;

			// 처음 반복에선 근접 상수로 기본 값(반복 변수의 초기값)을 대입
			if (i == 1)
				the_Closest_num = i;
			else
			{
				// B 와 가까운 정도를 확인하는 연산 
				// 작을 수록 가까움
				Compare_arr[the_Closest_num - 1] -= B_input;
				Compare_arr[i - 1] -= B_input;

				// 해당 연산의 값이 0 이라면 동일한 수이므로 가장 가까운 수에 대입
				if (Compare_arr[the_Closest_num - 1] == 0 || Compare_arr[i - 1] == 0)
				{
					if (Compare_arr[the_Closest_num - 1] != 0)
						the_Closest_num = i;

					break;
				}
				else
				{
					// 연산의 값이 음수가 된다면 착오가 생길 수 있으므로
					// - 1 을 곱해 양수 중 작은 수 구하는 부분
					if (Compare_arr[the_Closest_num - 1] < 0)
						Compare_arr[the_Closest_num - 1] *= -1;
					if (Compare_arr[i - 1] < 0)
						Compare_arr[i - 1] *= -1;

					if (Compare_arr[the_Closest_num - 1] > Compare_arr[i - 1])
						the_Closest_num = i;
				}
			}
		}
	}
	// 가장 가까운 수 출력
	printf("%d\n", the_Closest_num);

	return 0;
}