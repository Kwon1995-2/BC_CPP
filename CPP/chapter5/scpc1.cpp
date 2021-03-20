#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	 // freopen("input.txt", "r", stdin);

	 /*
		If you remove the statement below, your program's output may not be recorded
		when your program is terminated after the time limit.
		For safety, please use setbuf(stdout, NULL); statement.
	  */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, K;
		scanf("%d %d", &N, &K);
		int A[100];
		int B[100];
		int Max = 0;
		int Minmax[100];
		int count = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &B[i]);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Max <= A[i] + B[j]) {
					Max = A[i] + B[j];
				}
			}
			Minmax[i] = Max;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Minmax[i] <= Minmax[j]) {
					count++;
				}
			}
			if (count == N) {
				Answer = Minmax[i];
				break;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

				 // Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}