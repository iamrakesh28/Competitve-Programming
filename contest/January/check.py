file1 = open("1.txt", "r")
file2 = open("2.txt", "r")
data1 = file1.readlines()
data2 = file2.readlines()
for i in range(len(data1)):
	if data1[i] != data2[i]:
		print("ERROR")
		break
