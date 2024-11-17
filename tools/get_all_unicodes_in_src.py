from pathlib import Path
import re


src_path = Path(__file__).parent.parent / 'src'


def get_files(path):
    files = []
    for file in path.rglob('*.cpp'):
        files.append(file)
    for file in path.rglob('*.c'):
        files.append(file)
    for file in path.rglob('*.ino'):
        files.append(file)
    return files


def extract_unicode_chars(string):
    unicode_chars = []
    for char in string:
        if ord(char) > 127:  # Check if the character is outside ASCII range
            unicode_chars.append(char)
    return unicode_chars

char_set = set()


extra_chars = extract_unicode_chars(Path(__file__).parent.joinpath('extra_chars.txt').read_text(encoding="utf-8"))
char_set.update(extra_chars)


# Get all unicode characters in the source code
for file in get_files(src_path):
    print(file)
    content = file.read_text(encoding="utf-8")
    unicode_chars = extract_unicode_chars(content)
    char_set.update(unicode_chars)
    

print(len(char_set))
li = []
for char in char_set:
    li.append(hex(ord(char)))
with open('unicodes.txt', 'w') as f:
    f.write(', '.join(li))
