n = int(input("Enter number of frames: "))
w = int(input("Enter window size: "))

i = 0

while i < n:
    for j in range(i, min(i + w, n)):
        print("Sending Frame", j)

    lost = int(input("Enter lost frame (-1 if none): "))

    if lost == -1:
        i += w
    else:
        print("Resending Frame", lost)

        i = lost + 1

print("All frames sent successfully")

