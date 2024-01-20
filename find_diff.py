import sys

def extract_string_from_file(file_path):
    with open(file_path, 'r') as file:
        return file.read().strip()

def find_differences(string1, string2):
    for index, (char1, char2) in enumerate(zip(string1, string2), start=1):
        if char1 != char2:
            return index
    return None

if len(sys.argv) != 3:
    print("Usage: python find_diff.py <file1_path> <file2_path>")
    sys.exit(1)

file1_path = sys.argv[1]
file2_path = sys.argv[2]

string1 = extract_string_from_file(file1_path)
string2 = extract_string_from_file(file2_path)

index = find_differences(string1, string2)

if index is not None:
    if len(string1) > len(string2):
        print(f"Extra character '{string1[index-1]}' at position {index} in {file1_path}")
    elif len(string2) > len(string1):
        print(f"Extra character '{string2[index-1]}' at position {index} in {file2_path}")
    else:
        print(f"Difference at position {index}: '{string1[index-1]}' vs '{string2[index-1]}'")
else:
    print("No differences found")
