import ctypes
import numpy as np


lib = ctypes.CDLL("./lib.so")
lib.vector_dot_product.restype = ctypes.c_double
lib.vector_dot_product.argtypes = [ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int]

n = 1000
v1 = [1 for i in range(n)]
v2 = [i + 1 for i in range(n)]

v1_ptr = (ctypes.c_double * len(v1))(*v1)
v2_ptr = (ctypes.c_double * len(v2))(*v2)

result = lib.vector_dot_product(v1_ptr, v2_ptr, n)

print("Dot product:", result)