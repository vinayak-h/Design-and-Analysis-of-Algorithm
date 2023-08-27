import random
import subprocess
import time

# Bubble sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


size = 100
numbers = [random.randint(1, 100)for _ in range(size)]

input_sizes = []

for i in range(100, 100000, 500):
    input_sizes.append(i)

time_taken_actual = []
time_taken_estimated = []

for n in input_sizes:
    arr = numbers[:n]
    start_time = time.time()
    end_time = time.time()
    elapsed_time = end_time - start_time
    time_taken_actual.append(elapsed_time)

    elapsed_time = n*n
    time_taken_estimated.append(elapsed_time)

with open('bubble_time.txt', 'w') as f:
    for i, size in enumerate(input_sizes):
        f.write(f"{size} {time_taken_actual[i]} {time_taken_estimated[i]}\n")


# Call gnuplot to generate the graph
def bubbleGraph():
    gnuplot_script = '''
    set xlabel "Input Size"
    set ylabel "Time taken (Seconds)"
    set title "Time efficiency of Bubble Sort"
    plot "bubble_time.txt" using 1:2 with linespoints title "Actual Time", \
        "bubble_time.txt" using 1:3 with linespoints title "Estimated Time"
    
    set term png
    set output "bubblesort_efficiency.png"
    replot
    pause -1
    '''
    with open('plot.gnu', 'w') as file:
        file.write(gnuplot_script)

    # Run Gnuplot in interacvtive mode
    subprocess.run(['gnuplot', '-p', 'plot.gnu'])

    # wait for user input before exiting
    input("Press Enter to Quit....")


#Calling the plot function
bubbleGraph()