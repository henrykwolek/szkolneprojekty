import io

fileOpener = open("dane7.txt", "r")

myList = []
roznice = []
zgody = []

for line in fileOpener:
    myList.append(int(line))

i = 0
while i < len(myList) - 1:
    roznice.append(abs(myList[i] - myList[i + 1]))
    i += 1

j = 0
while j < len(roznice) - 1:
    if roznice[j] == roznice[j + 1]:
        if not roznice[j] in zgody:
            zgody.append(roznice[j])
    j += 1

final = []
appender = 0

for element in roznice:
    if element in zgody:
        appender += 1
    else:
        final.append(appender)
        appender = 0

max_occ = max(final)

k = 0
occ = 0
while k < len(roznice) - 1:
    if roznice[k] == roznice[k + 1]:
        occ += 1
    if occ == max(final):
        with io.open("odp_2.txt", "w", encoding="utf-8") as fileWriter:
            fileWriter.write(str(roznice[k])) 
        break
    k += 1

fileOpener.close()
fileWriter.close()