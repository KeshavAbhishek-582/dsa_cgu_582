def xor_parity(L, R):
    xor_result = 0
    for i in range(L, R + 1):
        xor_result ^= i

    if xor_result % 2 == 0:
        print("even")
    else:
        print("odd")

# Input
L, R = map(int, input().split())

# Output
xor_parity(L, R)