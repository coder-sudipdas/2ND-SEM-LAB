# Hamming Code

data = input("Enter 4-bit data: ")

# Positions: 1 2 3 4 5 6 7
#            P1 P2 D1 P4 D2 D3 D4

d1, d2, d3, d4 = map(int, data)

p1 = d1 ^ d2 ^ d4
p2 = d1 ^ d3 ^ d4
p4 = d2 ^ d3 ^ d4

code = [p1, p2, d1, p4, d2, d3, d4]

print("Hamming Code:", ''.join(map(str, code)))

# Receiver
received = input("Enter received code: ")
r = list(map(int, received))

s1 = r[0] ^ r[2] ^ r[4] ^ r[6]
s2 = r[1] ^ r[2] ^ r[5] ^ r[6]
s4 = r[3] ^ r[4] ^ r[5] ^ r[6]

error = s4 * 4 + s2 * 2 + s1

if error == 0:
    print("No Error")
else:
    print("Error at position:", error)

    r[error - 1] ^= 1

    print("Corrected Code:", ''.join(map(str, r)))

