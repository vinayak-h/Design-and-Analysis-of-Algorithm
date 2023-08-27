def sequential_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i  # Element found, return its index
    return -1  # Element not found


n = int(input("Enter the number of elements: "))
arr = []

print(f"Enter {n} elements:")
for _ in range(n):
    element = int(input())
    arr.append(element)

key = int(input("Enter the element to search: "))

index = sequential_search(arr, key)

if index != -1:
    print("Element", key, "found at index", index)
else:
    print("Element", key, "not found.")
