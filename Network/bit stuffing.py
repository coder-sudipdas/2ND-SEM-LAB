data = input("Enter binary data: ")

count = 0
stuffed = ""

for bit in data:
    stuffed += bit

    if bit == '1':
        count += 1
        if count == 5:
            stuffed += '0'
            count = 0
    else:
        count = 0

print("After Bit Stuffing:", stuffed)

