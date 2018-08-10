import math

def find_pi(n_digit):
    pi_round = round(math.pi, n_digit)
    return pi_round



n_digit = int(input("Which digit of pi are you looking for: "))
print(find_pi(n_digit))
