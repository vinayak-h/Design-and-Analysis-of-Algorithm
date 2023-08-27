def sequential_search_sentinel(arr, key):
    n = len(arr)
    arr.append(key)  # Append the key as a sentinel value
    
    i = 0
    while arr[i] != key:
        i += 1
    
    arr.pop()  # Remove the sentinel value
    
    if i < n:
        return i  # Key found, return the index
    else:
        return -1  # Key not found

# Example usage
my_list = [5, 2, 8, 1, 4]
search_key = 8
result = sequential_search_sentinel(my_list, search_key)
if result != -1:
    print(f"The key {search_key} was found at index {result}.")
else:
    print("The key was not found.")
