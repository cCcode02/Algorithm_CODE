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
		// �ش� ������ ������ ���� B ���� ũ�ٸ� �ݺ��� Ż��
		if (Limit_cnt == 1)
			break;
		else
		{
			int temp = 1;
			// �ӽ� ���� ������ ���� ��� ��� ����
			for (int Repeat = 0; Repeat < N_input; Repeat++)
				temp *= i;

			Compare_arr[i - 1] = temp;
			// ������ ���� B ������ ū�� Ȯ��
			if (temp > B_input)
				Limit_cnt = 1;

			// ó�� �ݺ����� ���� ����� �⺻ ��(�ݺ� ������ �ʱⰪ)�� ����
			if (i == 1)
				the_Closest_num = i;
			else
			{
				// B �� ����� ������ Ȯ���ϴ� ���� 
				// ���� ���� �����
				Compare_arr[the_Closest_num - 1] -= B_input;
				Compare_arr[i - 1] -= B_input;

				// �ش� ������ ���� 0 �̶�� ������ ���̹Ƿ� ���� ����� ���� ����
				if (Compare_arr[the_Closest_num - 1] == 0 || Compare_arr[i - 1] == 0)
				{
					if (Compare_arr[the_Closest_num - 1] != 0)
						the_Closest_num = i;

					break;
				}
				else
				{
					// ������ ���� ������ �ȴٸ� ������ ���� �� �����Ƿ�
					// - 1 �� ���� ��� �� ���� �� ���ϴ� �κ�
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
	// ���� ����� �� ���
	printf("%d\n", the_Closest_num);

	return 0;
}