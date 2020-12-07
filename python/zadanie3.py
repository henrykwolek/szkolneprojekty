#Olivia Koszykowska

a = int(input("Podaj a: "))
b = int(input("Podaj b: "))
c = int(input("Podaj c: "))

if a >= b and a <= c:
    print("Zmienna a wyosząca ", a, " należy do przedziału <", b, " ", c, ">.")
else:
    print("Zmienna a wyosząca ", a, " NIE należy do przedziału <", b, " ", c, ">.")
