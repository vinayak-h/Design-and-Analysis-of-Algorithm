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
void merge(int A[], int B[], int p, int C[], int q) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = C[j];
            j++;
        }
        k++;
    }
    while (i < p) {
        A[k] = B[i];
        i++;
        k++;
    }
    while (j < q) {
        A[k] = C[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int size) {
    if (size < 2) {
        return; 
    }
    int mid = size / 2;
    int B[mid];
    int C[size - mid];
    for (int i = 0; i < mid; i++) {
        B[i] = A[i];
    }
    for (int i = mid; i < size; i++) {
        C[i - mid] = A[i];
    }

    mergeSort(B, mid);
    mergeSort(A, size - mid);

    merge(A, B, mid, C, size - mid);
}

int main(int argc, char **argv)
{
	FILE *fp;
	struct timeval tv;
	double dStart, dEnd;
	int Arr[100000],i;
	fp=fopen("mergetimeC.txt","w");
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
		fprintf(gnuplotPipe, "set title 'Time Efficiency of Merge Sort'\n");
		fprintf(gnuplotPipe, "set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 0.5\n");
		fprintf(gnuplotPipe, "set style line 2 lc rgb '#006ae90' lt 2 lw 2 pt 8 ps 0.5\n");
		fprintf(gnuplotPipe, "plot 'mergetimeC.txt' using 1:2 with linespoints ls 1 title 'Actual Time',%d*x**2 with lines ls 2 title 'Estimated Time'\n",(i*log(i)) / 1000000.0);
		fprintf(gnuplotPipe, "set term png\n");
		fprintf(gnuplotPipe, "set output 'mergesort_efficiencyC.png'\n");
		fprintf(gnuplotPipe, "replot\n");
		fflush(gnuplotPipe);
		fprintf(gnuplotPipe, "exit\n");
		pclose(gnuplotPipe);
	}
	return 0;
}		