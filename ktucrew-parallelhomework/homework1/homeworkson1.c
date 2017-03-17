#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//time_t start, end, diff;
clock_t begin,end;
double time_spent;

int main()
{

	float **ptr1, **ptr2, **ptr3;

	short int row1, col, col2;

	short int i, j, k;

	printf("\nEnter number of rows for first matrix : ");
	scanf("%hd", &row1);
	printf("\nEnter number of columns for first matrix and rows for second matrix : ");
	scanf("%hd", &col);
	printf("\nEnter number of columns for second matrix : ");
	scanf("%hd", &col2);
  begin = clock();
  FILE *f;
   f = fopen("1000x1000.txt", "a");
	ptr1 = (float **)malloc(sizeof(float *)* row1);
	ptr2 = (float **)malloc(sizeof(float *)* col);
	ptr3 = (float **)malloc(sizeof(float *)* row1);

	for (i = 0; i<row1; i++)
		ptr1[i] = (float *)malloc(sizeof(float)* col);
	for (i = 0; i<col; i++)
		ptr2[i] = (float *)malloc(sizeof(float)* col2);
	for (i = 0; i<row1; i++)
		ptr3[i] = (float *)malloc(sizeof(float)* col2);


	for (i = 0; i< row1; i++)
	{
		for (j = 0; j< col; j++)
		{
			ptr1[i][j] = 1.0;
		}
	}


	for (i = 0; i< col; i++)
	{
		for (j = 0; j< col2; j++)
		{
			ptr2[i][j] = 1.0;
		}
	}

	//start = clock();

	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col; j++)
		{
			ptr3[i][j] = 0;
			for (k = 0; k<col2; k++)
				ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j];
		}
	}




	fprintf(f,"\n\nResultant matrix :");
	for (i = 0; i< row1; i++)
	{
		fprintf(f,"\n");
		for (j = 0; j < col2; j++)
			fprintf(f,"%.1f\t", ptr3[i][j]);
	}
  fclose(f);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%lf\n",time_spent);
	//printf("\n\n Running Time : %lf ms\n",diff);
	return(0);
}
