fs = open("galerie_przyklad.txt", "r")

powierzchnieGaleri = []

for word in fs:
  tempList = word.split()
  surface = 0
  iloscLokali = 0 
  for i in range(2, 140):
    if tempList[i] == 0:
      break
    surface = surface + int(tempList[i]) * int(tempList[i + 1])
    i = i + 2
    iloscLokali += 0.5
  print(iloscLokali)
  #listToInsert = [tempList[0], surface]
  #powierzchnieGaleri.append(listToInsert)