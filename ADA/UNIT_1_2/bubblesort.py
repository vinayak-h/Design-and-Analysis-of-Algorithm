import subprocess
import time


def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-1-i):
            if arr[j+1] < arr[j]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Get input from the user
numbers = input("Enter numbers separated by spaces: ").split()
numbers = [int(num) for num in numbers]

print("Original list:", numbers)

# Measure the time taken for sorting
start_time = time.time()
bubble_sort(numbers)
end_time = time.time()

print("Sorted list:", numbers)

# Calculate and print the elapsed time
elapsed_time = end_time - start_time
print("Time taken:", elapsed_time, "seconds")

# Generate the graph
def bubbleGraph():
    gnuplot_script = f'''
    set xlabel "Input Size"
    set ylabel "Time taken (Seconds)"
    set title "Time efficiency of Bubble Sort"
    set term png
    set output "bubblesort_efficiency.png"
    set xrange [*:*]  # Automatic x-axis range
    set yrange [*:*]  # Automatic y-axis range
    plot "bubble_time.txt" with lines title "Actual Time"
    '''
    input_size = len(numbers)
    time_taken_actual = elapsed_time

    with open('bubble_time.txt', 'w') as f:
        f.write(f"{input_size} {time_taken_actual}\n")

    with open('plot.gnu', 'w') as file:
        file.write(gnuplot_script)

    # Run Gnuplot to generate the graph
    subprocess.run(['gnuplot', 'plot.gnu'])

    print("Graph generated as bubblesort_efficiency.png")

# Call the graph generation function
bubbleGraph()
