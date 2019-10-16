from ctypes import *

m = cdll.LoadLibrary('./strnins.so')

s = create_string_buffer(b"hhh", 20)
t = create_string_buffer(b"ddd", 20)

print(s.value)
m.strnins(s, t, 1)
print(s.value)