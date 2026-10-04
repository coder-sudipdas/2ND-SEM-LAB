def crc(data, divisor):
    n = len(divisor)
    temp = list(data + '0' * (n - 1))
    
    # XOR division
    for i in range(len(data)):
        if temp[i] == '1':
            for j in range(n):
                temp[i + j] = '0' if temp[i + j] == divisor[j] else '1'
                
    remainder = ''.join(temp[len(data):])
    return data + remainder

def verify(received, divisor):
    n = len(divisor)
    temp = list(received)
    
    # Run the same XOR division over the received message
    for i in range(len(received) - n + 1):
        if temp[i] == '1':
            for j in range(n):
                temp[i + j] = '0' if temp[i + j] == divisor[j] else '1'
                
    # If any remainder bit is '1', an error occurred
    remainder = ''.join(temp[-(n - 1):])
    return '1' in remainder

# --- SENDER SIDE ---
data = input("Enter data bits: ")
divisor = input("Enter divisor bits: ")

codeword = crc(data, divisor)
print("CRC Codeword to send:", codeword)
print("-" * 30)

# --- RECEIVER SIDE ---
received = input("Enter received codeword: ")

if verify(received, divisor):
    print("Error detected in transmission!")
else:
    print("No error detected. Data received successfully.")

