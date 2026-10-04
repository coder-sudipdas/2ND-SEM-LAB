data = input("Enter data: ")

flag = 'FLAG'
escape = 'ESCAPE'

stuffed = flag

for ch in data:
    if ch == flag or ch == escape:
        stuffed += escape
    stuffed += ch

stuffed += flag

print("After Byte Stuffing:", stuffed)