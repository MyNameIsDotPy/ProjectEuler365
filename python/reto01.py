def reto01():
	return sum([i if i%3==0 or i%5==0 else 0 for i in range(1000)])
print(reto01())
