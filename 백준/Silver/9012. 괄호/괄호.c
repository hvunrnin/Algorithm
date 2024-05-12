#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);

	char input[50];

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &input);
		
		if (input[0] == '(')
		{
			int cnt = 1;
			for (int j = 1; j < strlen(input); j++)
			{
				if (cnt < 0)
					break;
				if (input[j] == '(')
					cnt++;
				else
					cnt--;
			}
			if (cnt == 0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
}
