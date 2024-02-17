def reto09():
    for a in range(3, 10000):
        for b in range(3, 10000):
            c = (a * a + b * b) ** 0.5
            if c % 1 == 0:
                if a + b + c == 1000:
                    return a * b * c

    return 1
