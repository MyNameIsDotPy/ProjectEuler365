facts = {0: 1}


def fact(n):
    if n in facts.keys():
        return facts[n]
    factorial = fact(n-1) * n
    facts[n] = factorial
    return factorial


def reto15():
    n = 40
    m = 20
    return fact(n) // (fact(n - m) * fact(m))


print(reto15())
