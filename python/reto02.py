a = 0
b = 1
s = 0
while True:
	fibo = a + b
	if fibo > 4000000:
		break
	if fibo%2 == 0:
		s += fibo
	a = b
	b = fibo
print(s)
