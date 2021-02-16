import io

def najczesciej(inList): 
    counter = 0
    num = inList[0] 
      
    for i in inList: 
        curr_frequency = inList.count(i) 
        if(curr_frequency> counter): 
            counter = curr_frequency 
            num = i 
  
    return str(num) + " występuje " + str(counter) + " razy"

fileOpener = open("dane7.txt", "r")

myList = []
roznice = []
pojedynczeRoznice = []

for line in fileOpener:
    myList.append(int(line))

i = 0
while i < len(myList) - 1:
    roznice.append(abs(myList[i] - myList[i + 1]))
    i += 1

for element in roznice:
    if not element in pojedynczeRoznice:
        pojedynczeRoznice.append(element)

outStr = str(najczesciej(roznice))

#Zaimportowałem moduł io z powodu występującego problemu
#Moduł io pozwala usawić kodowanie na utf-8

with io.open("odp_3.txt", "w", encoding="utf-8") as fileWriter:
    fileWriter.write(str(najczesciej(roznice))) 

fileOpener.close()
fileWriter.close()
