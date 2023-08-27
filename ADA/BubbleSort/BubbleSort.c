#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000; 
    }
}

double measureTime(int arr[], int n)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    bubbleSort(arr, n);

    gettimeofday(&end, NULL);

    double timeTaken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    return timeTaken;
}

void plotGraph(int n, double actualTime[], double estimatedTime[])
{
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe != NULL)
    {
        FILE *fp = fopen("bubble_sort_graph.txt", "w");
        if (fp != NULL)
        {
            for (int i = 0; i < n; i++)
            {
                fprintf(fp, "%d %lf %lf\n", (i + 1) * 500, actualTime[i], estimatedTime[i]);
            }
            fclose(fp);

            fprintf(gnuplotPipe, "set xlabel 'Input Size (n)'\n");
            fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
            fprintf(gnuplotPipe, "set title 'Time Efficiency of Bubble Sort'\n");
            fprintf(gnuplotPipe, "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5\n");
            fprintf(gnuplotPipe, "set style line 2 lc rgb '#006ae90' lt 2 lw 2 pt 8 ps 0.5\n");
            fprintf(gnuplotPipe, "plot 'bubble_sort_graph.txt' using 1:2 with linespoints ls 1 title 'Actual Time', 'bubble_sort_graph.txt' using 1:3 with linespoints ls 2 title 'Estimated Time'\n");
            fprintf(gnuplotPipe, "set term png\n");
            fprintf(gnuplotPipe, "set output 'bubble_sort_graph.png'\n");
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

    for (int i = 0, n = minN; n <= maxN; i++, n += step)
    {
        generateRandomArray(arr, n);
        actualTime[i] = measureTime(arr, n);
        estimatedTime[i] = 0.5 * n * n;
    }

    plotGraph(numPoints, actualTime, estimatedTime);

    return 0;
}
