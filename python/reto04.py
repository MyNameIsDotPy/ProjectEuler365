max_palindromic = 0
for i in range(100, 1000):
	for j in range(100, 1000):
		if str(i*j) == str(i*j)[::-1]:
			if i*j > max_palindromic:
				max_palindromic = i*j
print(max_palindromic)

