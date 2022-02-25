#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Input = 0;
	scanf("%d", &Input);

	// 약수의 초깃값은 2부터
	int divisor = 2;

	// 입력값을 약수로 나눈 값이 1이 될 때까지 반복
	while (Input != 1)
	{
		// 입력값을 divisor 로 나누었을 때 나머지가 0 이라면
		// = divisor 이 입력값의 약수라면
		if (Input % divisor == 0)
		{
			// 약수 출력
			printf("%d ", divisor);

			// 입력값에 나누는 수를 나누어 값을 줄임
			Input /= divisor;
			// 나누는 수를 처음(2)부터 다시 시작
			divisor = 2;
		}
		else
			divisor += 1;
		// 약수가 아닐 경우 나누는 수에 1을 계속 더해 약수를 탐색
	}

	return 0;
}
