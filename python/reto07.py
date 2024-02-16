primes = [2, 3, 5, 7, 11, 13]
idx = 6;
prime = 14;
while(idx<10001):
	i = 0
	while i < idx:
		if(prime%primes[i]==0):
			break
		i+=1
	if(i==idx):
		primes.append(prime)
		idx+=1
	prime+=1
print(prime-1)



