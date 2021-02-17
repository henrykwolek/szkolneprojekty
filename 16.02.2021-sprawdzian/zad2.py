import io
import more_itertools

def znajdz_zakres(tablica):
    for el in more_itertools.consecutive_groups(tablica):
        el = list(el)
        if len(el) == 0:
            yield el[0]
        else:
            yield el[0], el[-1]

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

print(list(znajdz_zakres(roznice)))

