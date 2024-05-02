# Extended Euclidean Algorithm to find the modular inverse

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % m

# Calculate the modular inverse of k_e modulo p-1
p = 877
k_e = 215

# Calculate the modular inverse of k_e
k_e_inv = modinv(k_e, p-1)
k_e_inv

print(k_e_inv)