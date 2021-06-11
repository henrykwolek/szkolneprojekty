fs = open("galerie_przyklad.txt", "r")

fw = open("zad_a.txt", "w")
fw.close()

wszystkieKraje = []
ileGalerii = []
kraje = []

for word in fs:
  tempList = word.split()
  #krajeOrazMiasta.append([tempList[0], tempList[1]])
  if not tempList[0] in kraje:
    kraje.append(tempList[0])
  wszystkieKraje.append(tempList[0])

for country in kraje:
  fw_2 = open("zad_a.txt", "a")
  ile = 0
  for i in range(0, 10):
    if country == wszystkieKraje[i]:
      ile += 1
  fw_2.write(country + " " + str(ile) + "\n")
  ileGalerii.append(country + " " + str(ile))
  
fs.close()
fw_2.close()