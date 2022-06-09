/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
	int i, j, k, p, t1, t2, t3, t4, t5, t6, t7, t8;
	if (M == 32 && N == 32)
	{
		for (i = 0; i < M; i = i + 8)
		{
			for(j = 0; j < N; j++)
			{
				t1 = A[j][i];
				t2 = A[j][i + 1];
				t3 = A[j][i + 2];
				t4 = A[j][i + 3];
				t5 = A[j][i + 4];
				t6 = A[j][i + 5];
				t7 = A[j][i + 6];
				t8 = A[j][i + 7];
				B[i][j] = t1;
				B[i + 1][j] = t2;
				B[i + 2][j] = t3;
				B[i + 3][j] = t4;
				B[i + 4][j] = t5;
				B[i + 5][j] = t6;
				B[i + 6][j] = t7;
				B[i + 7][j] = t8;
			}
		}
	}
	if (N == 64 && M == 64)
	{
		for (int i = 0; i < M; i += 8)
			for (int j0 = i; j0 < N + i; j0 += 8)
			{
				int j = j0 % N;
				if (i == j)
				{
					for (int k = 0; k < 4; k++)
						for (int l = 0; l < 8; l++)
							B[j + k][(i + l + 8) % N] = A[j + k][i + l];
					for (int k = 4; k < 8; k++)
						for (int l = 0; l < 8; l++)
							B[j + k - 4][(i + l + 16) % N] = A[j + k][i + l];

					for (int l = 0; l < 8; l++)
					{
						for (int k = 0; k < 4; k++)
							B[i + l][j + k] = B[j + k][(i + l + 8) % N];
						for (int k = 4; k < 8; k++)
							B[i + l][j + k] = B[j + k - 4][(i + l + 16) % N];
					}
				}
				else
				{
					for (int k = 0; k < 4; k++)
					{
						for (int l = 0; l < 4; l++)
							B[i + l][j + k] = A[j + k][i + l];
						for (int l = 4; l < 8; l++)
							B[i + l - 4][j + k + 4] = A[j + k][i + l];
					}
					for (int l = 0; l < 4; l++)
					{
						int a0 = B[i + l][j + 4];
						int a1 = B[i + l][j + 5];
						int a2 = B[i + l][j + 6];
						int a3 = B[i + l][j + 7];

						for (int k = 4; k < 8; k++)
							B[i + l][j + k] = A[j + k][i + l];

						B[i + l + 4][j + 0] = a0;
						B[i + l + 4][j + 1] = a1;
						B[i + l + 4][j + 2] = a2;
						B[i + l + 4][j + 3] = a3;
					}
					for (int k = 4; k < 8; k++)
						for (int l = 4; l < 8; l++)
							B[i + l][j + k] = A[j + k][i + l];
				}
			}
	}
	if (M == 61 && N == 67)
	{
		for (i = 0; i < N; i = i + 19)
		{
			for (j = 0; j < M; j = j + 19)
			{
				for (k = i; k < i + 19 && k < N; k++)
				{
					for (p = j; p < j + 19 && p < M; p++)
					{
						t1 = A[k][p];
						B[p][k] = t1;
					}
				}
			}
		}
	}
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

 /*
  * trans - A simple baseline transpose function, not optimized for the cache.
  */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
	int i, j, tmp;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			tmp = A[i][j];
			B[j][i] = tmp;
		}
	}

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
	/* Register your solution function */
	registerTransFunction(transpose_submit, transpose_submit_desc);

	/* Register any additional transpose functions */
	//registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; ++j) {
			if (A[i][j] != B[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

