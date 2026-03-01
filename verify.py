import sys
import numpy as np

def read_matrix(filename):
    with open(filename, 'r') as f:
        n = int(f.readline())
        data = []
        for _ in range(n):
            row = list(map(float, f.readline().split()))
            data.append(row)
    return np.array(data)

A = read_matrix(sys.argv[1])
B = read_matrix(sys.argv[2])
C_cpp = read_matrix(sys.argv[3])

C_np = A @ B

if np.allclose(C_cpp, C_np, atol=1e-6):
    print("Verification successful: results match.")
else:
    print("Verification failed: mismatch detected.")