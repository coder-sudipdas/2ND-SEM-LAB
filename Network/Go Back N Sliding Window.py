window = int(input("Enter Window Size: "))

total = int(input("Enter Total Frames: "))

sent = 0

while sent < total:

    for i in range(window):
        if sent < total:
            print("Frame", sent, "has been transmitted.")
            sent += 1

    ack = int(input("Enter last Acknowledgement received: "))

    if ack >= sent - 1:
        print("Acknowledgement received.")
    else:
        print("Resending from Frame", ack)
        sent = ack

print("All frames sent successfully")