def fact(num):
    num = int(num)
    if is_prime(num):
        print ("This number is prime: ", num)
        return True

    factors = getfact(num)
    print("Here are your facors: ", factors)

    return True

def getfact(num):
    i = 2
    factors = []
    while i < num:
        if num%i ==0:
            if is_prime(i):
                factors.append(i)
        i = i + 1
    return factors

def is_prime(number):
    i = 2
    while i < number:
        if number%i == 0:
            return False
        i = i + 1

    return True

number = input("Enter Number:")
fact(number)
