def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        min = i
        for j in range(i+1, n):
            if arr[j] < arr[min]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]


numbers = input("Enter numbers separated by spaces: ").split()
numbers = [int(num) for num in numbers]
print("Original list:", numbers)
selection_sort(numbers)
print("Sorted list:", numbers)



# def Sequential_Sort(array):
#     n = len(array)
    
#     max_index = 0
#     for i in range(1, n):
#         if array[i] > array[max_index]:
#             max_index = i
#     array[max_index], array[n-1] = array[n-1], array[max_index]
    
#     for i in range(n-2):
#         min_index = i
#         for j in range(i+1, n-1):
#             if array[j] < array[min_index]:
#                 min_index = j
#         array[i], array[min_index] = array[min_index], array[i]
    
#     return array

# # Test the function
# num = input("Enter numbers: ")
# num = [int(x) for x in num.split()]
# print("Given:", num)
# sorted_nums = Sequential_Sort(num)
# print("Sorted:", sorted_nums)


# def brute_force_string_match(pattern, text):
#     m = len(pattern)
#     n = len(text)
    
#     for i in range(n - m + 1):
#         j = 0
#         while j < m and text[i + j] == pattern[j]:
#             j += 1
        
#         if j == m:
#             return i
    
#     return -1

# # Test the function
# text = input("Enter the text: ")
# pattern = input("Enter the pattern to search: ")

# index = brute_force_string_match(pattern, text)

# if index != -1:
#     print("Pattern found at index", index)
# else:
#     print("Pattern not found in the text.")



def sequential_search_sentinel(arr, target):
    n = len(arr)
    last_element = arr[n - 1]  # Store the last element as the sentinel
    arr[n - 1] = target  # Replace the last element with the target value

    i = 0
    while arr[i] != target:
        i += 1

    arr[n - 1] = last_element  # Restore the last element

    if i < n - 1 or arr[n - 1] == target:
        return i
    else:
        return -1

# Test the function
nums = [4, 2, 6, 1, 7, 5]
target = 6

index = sequential_search_sentinel(nums, target)

if index != -1:
    print("Target found at index", index)
else:
    print("Target not found in the list.")
