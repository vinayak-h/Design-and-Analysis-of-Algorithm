#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide the input size.\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (n * 10 - 10 + 1) + 10;
    }

    FILE *plotFile = fopen("plot-data.txt", "w");

    for (int i = 0; i < n; i++)
    {
        int *unsortedArr = (int *)malloc(i * sizeof(int));
        for (int j = 0; j < i; j++)
        {
            unsortedArr[j] = rand() % (n * 1000 - 10 + 1) + 10;
        }

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        double estimatedTime = i * i;

        fprintf(plotFile, "%d %lf %lf\n", i, timeTaken, estimatedTime);

        free(unsortedArr);
    }

    fclose(plotFile);

    FILE *gnuScript = fopen("plot.gnu", "w");
    const char *scriptContent = "set xlabel \"Input size\"\n"
                                "set ylabel \"Time taken(secs)\"\n"
                                "set title \"Time Efficiency of Selection Sort\"\n"
                                "plot \"plot-data.txt\" u 1:2 w lp pt 1 title 'Actual Time', '' u 1:3 w lp pt 1 title 'Estimated Time'\n"
                                "set term png\n"
                                "set output \"sorteff.png\"\n"
                                "replot\n";

    fprintf(gnuScript, "%s", scriptContent);

    fclose(gnuScript);

    system("gnuplot -persist plot.gnu");

    free(arr);

    return 0;
}