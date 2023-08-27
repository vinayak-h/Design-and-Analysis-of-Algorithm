#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>
void fnGenRandInput(int X[], int n)
{
	int i;
	srand(time(NULL)); 
	for(i=0;i<n;i++)
	X[i]=rand()%10000;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int r) {
    int P = A[r];  
    int i = (l - 1);      

    for (int j = l; j <= r - 1; j++) {
        if (A[j] <= P) {
            i++;  
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return (i + 1);
}

void quickSort(int A[], int l, int r) {
    if (l < r) {
        int S = partition(A, l, r);

        quickSort(A, l, S - 1);
        quickSort(A, S + 1, r);
    }
}

int main(int argc, char **argv)
{
	FILE *fp;
	struct timeval tv;
	double dStart, dEnd;
	int Arr[100000],i;
	fp=fopen("quicktimeC.txt","w");
	for(i=100;i<15000;i+=500)
	{
		fnGenRandInput(Arr,i);
		gettimeofday(&tv, NULL);
		dStart=tv.tv_sec+(tv.tv_usec/1000000.0);
		dEnd=tv.tv_sec+(tv.tv_usec/1000000.0);
		fprintf(fp,"%d\t%lf\t%d\n",i,dEnd-dStart,(i*log(i)) / 1000000.0);
	}
	fclose(fp);

	FILE *gnuplotPipe=popen("gnuplot -persistent","w");
	if(gnuplotPipe!=NULL)
	{
		fprintf(gnuplotPipe, "set xlabel 'Input Size'\n");
		fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
		fprintf(gnuplotPipe, "set title 'Time Efficiency of Quick Sort'\n");
		fprintf(gnuplotPipe, "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5\n");
		fprintf(gnuplotPipe, "set style line 2 lc rgb '#006ae90' lt 2 lw 2 pt 8 ps 0.5\n");
		fprintf(gnuplotPipe, "plot 'quicktimeC.txt' using 1:2 with linespoints ls 1 title 'Actual Time',%d*x**2 with lines ls 2 title 'Estimated Time'\n",(i*log(i)) / 1000000.0);
		fprintf(gnuplotPipe, "set term png\n");
		fprintf(gnuplotPipe, "set output 'quicksort_efficiencyC.png'\n");
		fprintf(gnuplotPipe, "replot\n");
		fflush(gnuplotPipe);
		fprintf(gnuplotPipe, "exit\n");
		pclose(gnuplotPipe);
	}
	return 0;
}		