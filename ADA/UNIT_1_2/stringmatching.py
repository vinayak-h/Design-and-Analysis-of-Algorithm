def string_matching(text, pattern):
    text_length = len(text)
    pattern_length = len(pattern)

    for i in range(text_length - pattern_length + 1):
        j = 0
        while j < pattern_length:
            if text[i+j] != pattern[j]:
                break
            j += 1

        if j == pattern_length:
            return i  # Pattern found at index i

    return -1  # Pattern not found


text = input("Enter the text: ")
pattern = input("Enter the pattern to search: ")

index = string_matching(text, pattern)

if index != -1:
    print("Pattern found at index", index)
else:
    print("Pattern not found.")
