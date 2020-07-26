def fourthBit(number):
    for i in range(3):
        number //= 2
    return number%2

if __name__ == "__main__":
    print(fourthBit(31))
    print(fourthBit(15))
    print(fourthBit(23))
