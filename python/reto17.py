letters = {
    # {-1, 3}, # And
    0: 0,  # Zero
    1: 3,  # One
    2: 3,  # Two
    3: 5,  # Three
    4: 4,  # Four
    5: 4,  # Five
    6: 3,  # Six
    7: 5,  # Seven
    8: 5,  # Eight
    9: 4,  # Nine
    10: 3,  # Ten
    11: 6,  # Eleven
    12: 6,  # Twelve
    13: 8,  # Thirteen
    14: 8,  # Fourteen
    15: 7,  # Fifteen
    16: 7,  # Sixteen
    17: 9,  # Seventeen
    18: 8,  # Eighteen
    19: 8,  # Nineteen
    20: 6,  # Twenty
    30: 6,  # Thirty
    40: 5,  # Forty
    50: 5,  # Fifty
    60: 5,  # Sixty
    70: 7,  # Seventy
    80: 6,  # Eighty
    90: 6,  # Ninety
    100: 7,  # Hundred
    1000: 11  # Thousand
}


def reto17():
    total_sum = 0
    for number in range(1, 1000):
        suma = 0
        decenas = number % 100
        centenas = number // 100
        unidades = number % 10
        if centenas != 0:
            suma += (letters[centenas] + letters[100])
            if decenas != 0:
                suma += 3
        if decenas <= 19:
            suma += letters[decenas]
        else:
            suma += (letters[decenas - unidades] + letters[unidades])
        total_sum += suma
    total_sum += letters[1000]
    return total_sum


print(reto17())
