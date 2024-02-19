primes = [2]
prime = 3
suma = 0

while prime < 200000:
	for i in primes:
		if prime % i == 0 or i > prime:
			break
	else:
#		print(prime)
		primes.append(prime)
		suma += prime
	prime += 2

print(suma)
