#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

void fnGenRandInput(int X[], int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		X[i] = rand() % 10000;
}

int binarySearch(int A[], int n, int k)
{
	int l = 0;
	int r = n - 1;
	int m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (A[m] == k)
		{
			return m;
		}
		else if (A[m] < k)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}

	return -1;
}

int main(int argc, char **argv)
{
	FILE *fp;
	struct timeval tv;
	double dStart, dEnd;
	int Arr[100000], i;
	fp = fopen("binarytimeC.txt", "w");
	for (i = 100; i < 15000; i += 500)
	{
		fnGenRandInput(Arr, i);
		gettimeofday(&tv, NULL);
		dStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
		// Perform binary search on Arr here if needed
		dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);
		fprintf(fp, "%d\t%lf\t%d\n", i, dEnd - dStart, (int)((log(i) / log(2)) / 1000000.0));
	}
	fclose(fp);

	FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
	if (gnuplotPipe != NULL)
	{
		fprintf(gnuplotPipe, "set xlabel 'Input Size'\n");
		fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
		fprintf(gnuplotPipe, "set title 'Time Efficiency of Binary Search'\n");
		fprintf(gnuplotPipe, "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5\n");
		fprintf(gnuplotPipe, "set style line 2 lc rgb '#006ae90' lt 2 lw 2 pt 8 ps 0.5\n");
		fprintf(gnuplotPipe, "plot 'binarytimeC.txt' using 1:2 with linespoints ls 1 title 'Actual Time', %f*x**2 with lines ls 2 title 'Estimated Time'\n", ((log(i) / log(2)) / 1000000.0));
		fprintf(gnuplotPipe, "set term png\n");
		fprintf(gnuplotPipe, "set output 'binarysearch_efficiencyC.png'\n");
		fprintf(gnuplotPipe, "replot\n");
		fflush(gnuplotPipe);
		fprintf(gnuplotPipe, "exit\n");
		pclose(gnuplotPipe);
	}
	return 0;
}
