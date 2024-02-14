i = 1
div = 1
while(True):

	if(i%div!=0):
		i+=1
		div = 1
		continue
	if div == 20:
		print(i)
		break
	div+=1
