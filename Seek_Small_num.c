#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Input = 0;
	scanf("%d", &Input);

	// ����� �ʱ갪�� 2����
	int divisor = 2;

	// �Է°��� ����� ���� ���� 1�� �� ������ �ݺ�
	while (Input != 1)
	{
		// �Է°��� divisor �� �������� �� �������� 0 �̶��
		// = divisor �� �Է°��� ������
		if (Input % divisor == 0)
		{
			// ��� ���
			printf("%d ", divisor);

			// �Է°��� ������ ���� ������ ���� ����
			Input /= divisor;
			// ������ ���� ó��(2)���� �ٽ� ����
			divisor = 2;
		}
		else
			divisor += 1;
		// ����� �ƴ� ��� ������ ���� 1�� ��� ���� ����� Ž��
	}

	return 0;
}
