def is_prime(n):
	for i in range(2, int(n**0.5)):
		if n%i==0:
			return False
	return True

max_factor = 1
value = 600851475143
for i in range(1, int(value**.5)):
	if value%i and is_prime(i):
		max_factor = i


print(max_factor)
