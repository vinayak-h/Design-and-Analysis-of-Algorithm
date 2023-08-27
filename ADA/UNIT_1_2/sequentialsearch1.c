#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void fnGenRandInput(int X[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		X[i] = rand() % 10000;
}

int sequentialSearch(int a[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	FILE *fp;
	struct timeval tv;
	double dStart, dEnd;
	int Arr[100000], i, key;

	srand(time(NULL)); // Initialize the random seed once

	fp = fopen("sequentialtimeC.txt", "w");
	for (i = 100; i <= 15000; i += 500)
	{
		fnGenRandInput(Arr, i);
		key = Arr[i - 1]; // Selecting a random key from the generated array
		gettimeofday(&tv, NULL);
		dStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
		sequentialSearch(Arr, i, key);
		gettimeofday(&tv, NULL);
		dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);
		fprintf(fp, "%d\t%lf\t%d\n", i, (dEnd - dStart), i);
	}
	fclose(fp);

	FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
	if (gnuplotPipe != NULL)
	{
		fprintf(gnuplotPipe, "set xlabel 'Input Size'\n");
		fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
		fprintf(gnuplotPipe, "set title 'Time Efficiency of Sequential Search'\n");
		fprintf(gnuplotPipe, "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5\n");
		fprintf(gnuplotPipe, "set style line 2 lc rgb '#006ae90' lt 2 lw 2 pt 8 ps 0.5\n");
		fprintf(gnuplotPipe, "plot 'sequentialtimeC.txt' using 1:2 with linespoints ls 1 title 'Actual Time',%d*x with lines ls 2 title 'Estimated Time'\n", i);
		fprintf(gnuplotPipe, "set term png\n");
		fprintf(gnuplotPipe, "set output 'sequentialsort_efficiencyC.png'\n");
		fprintf(gnuplotPipe, "replot\n");
		fflush(gnuplotPipe);
		fprintf(gnuplotPipe, "exit\n");
		pclose(gnuplotPipe);
	}
	return 0;
}
