#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int sequentialSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
}

double measureTime(int arr[], int n, int key)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    sequentialSearch(arr, n, key);

    gettimeofday(&end, NULL);

    double timeTaken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    return timeTaken;
}

void plotGraph(int n, double actualTime[], double estimatedTime[])
{
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe != NULL)
    {
        FILE *fp = fopen("sequential_search_graph.txt", "w");
        if (fp != NULL)
        {
            for (int i = 0; i < n; i++)
            {
                fprintf(fp, "%d %lf %lf\n", (i + 1) * 500, actualTime[i], estimatedTime[i]);
            }
            fclose(fp);

            fprintf(gnuplotPipe, "set xlabel 'Input Size (n)'\n");
            fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
            fprintf(gnuplotPipe, "set title 'Time Efficiency of Sequential Search'\n");
            fprintf(gnuplotPipe, "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5\n");
            fprintf(gnuplotPipe, "set style line 2 lc rgb '#006ae90' lt 2 lw 2 pt 8 ps 0.5\n");
            fprintf(gnuplotPipe, "plot 'sequential_search_graph.txt' using 1:2 with linespoints ls 1 title 'Actual Time', 'sequential_search_graph.txt' using 1:3 with linespoints ls 2 title 'Estimated Time'\n");
            fprintf(gnuplotPipe, "set term png\n");
            fprintf(gnuplotPipe, "set output 'sequential_search_graph.png'\n");
            fprintf(gnuplotPipe, "replot\n");
            fflush(gnuplotPipe);
            fprintf(gnuplotPipe, "exit\n");
        }
        pclose(gnuplotPipe);
    }
}

int main()
{
    const int minN = 100;
    const int maxN = 10000;
    const int step = 500;
    const int numPoints = (maxN - minN) / step + 1;

    double actualTime[numPoints];
    double estimatedTime[numPoints];

    int arr[maxN];
    int key = 42; 

    for (int i = 0, n = minN; n <= maxN; i++, n += step)
    {
        generateRandomArray(arr, n);
        actualTime[i] = measureTime(arr, n, key);
        estimatedTime[i] = 0.5 * n;
    }

    plotGraph(numPoints, actualTime, estimatedTime);

    return 0;
}
