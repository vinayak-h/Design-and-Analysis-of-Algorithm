#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

double measureTimeSequential(int arr[], int n, int key)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    sequentialSearch(arr, n, key);

    gettimeofday(&end, NULL);

    double timeTaken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    return timeTaken;
}

void stringMatching(char text[], char pattern[], int n, int m, int *index)
{
    int i, j, count = 0;
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            index[count++] = i;
        }
    }

    index[count] = -1;
}

char *generateRandomString(int length)
{
    char *str = (char *)malloc((length + 1) * sizeof(char));
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; i++)
    {
        str[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    str[length] = '\0';
    return str;
}

double measureTimeStringMatching(char text[], char pattern[], int n, int m)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int *index = (int *)malloc((n + 1) * sizeof(int));
    stringMatching(text, pattern, n, m, index);

    gettimeofday(&end, NULL);

    double timeTaken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    free(index);
    return timeTaken;
}

void plotGraph(int n, double actualTime[], double estimatedTime[], char *fileName, char *graphTitle)
{
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe != NULL)
    {
        FILE *fp = fopen(fileName, "w");
        if (fp != NULL)
        {
            for (int i = 0; i < n; i++)
            {
                fprintf(fp, "%d %lf %lf\n", (i + 1) * 500, actualTime[i], estimatedTime[i]);
            }
            fclose(fp);

            fprintf(gnuplotPipe, "set xlabel 'Input Size (n)'\n");
            fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
            fprintf(gnuplotPipe, "set title '%s'\n", graphTitle);
            fprintf(gnuplotPipe, "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5\n");
            fprintf(gnuplotPipe, "set style line 2 lc rgb '#006ae90' lt 2 lw 2 pt 8 ps 0.5\n");
            fprintf(gnuplotPipe, "plot '%s' using 1:2 with linespoints ls 1 title 'Actual Time', '%s' using 1:3 with linespoints ls 2 title 'Estimated Time'\n", fileName, fileName);
            fprintf(gnuplotPipe, "set term png\n");
            fprintf(gnuplotPipe, "set output '%s_graph.png'\n", fileName);
            fprintf(gnuplotPipe, "replot\n");
            fflush(gnuplotPipe);
            fprintf(gnuplotPipe, "exit\n");
        }
        pclose(gnuplotPipe);
    }
}

int main()
{
    const int minN_seq = 100;
    const int maxN_seq = 10000;
    const int step_seq = 500;
    const int numPoints_seq = (maxN_seq - minN_seq) / step_seq + 1;

    double actualTime_seq[numPoints_seq];
    double estimatedTime_seq[numPoints_seq];

    int arr_seq[maxN_seq];

    for (int i = 0, n = minN_seq; n <= maxN_seq; i++, n += step_seq)
    {
        generateRandomArray(arr_seq, n);
        int key = rand() % 1000;
        actualTime_seq[i] = measureTimeSequential(arr_seq, n, key);
        estimatedTime_seq[i] = n;
    }

    plotGraph(numPoints_seq, actualTime_seq, estimatedTime_seq, "sequential_search_content.txt", "Time Efficiency of Sequential Search");

    const int minN_str = 100;
    const int maxN_str = 10000;
    const int step_str = 500;
    const int numPoints_str = (maxN_str - minN_str) / step_str + 1;
    const int minM_str = 10;
    const int maxM_str = 100;
    const int stepM_str = 10;
    const int numPointsM_str = (maxM_str - minM_str) / stepM_str + 1;

    double actualTime_str[numPoints_str][numPointsM_str];
    double estimatedTime_str[numPoints_str][numPointsM_str];

    char text[maxN_str];
    char pattern[maxM_str];

    for (int i = 0, n = minN_str; n <= maxN_str; i++, n += step_str)
    {
        for (int j = 0, m = minM_str; m <= maxM_str; j++, m += stepM_str)
        {
            generateRandomString(n);
            generateRandomString(m);
            actualTime_str[i][j] = measureTimeStringMatching(text, pattern, n, m);
            estimatedTime_str[i][j] = n * m;
        }
    }

    plotGraph(numPoints_str, actualTime_str, estimatedTime_str, "brute_force_string_matching_content.txt", "Time Efficiency of Brute Force String Matching");

    return 0;
}
