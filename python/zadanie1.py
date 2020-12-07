#Olivia Koszykowska

xcor = int(input("Podaj współrzędną X: "))
ycor = int(input("Podaj współrzędną Y: "))

if xcor > 0 and ycor > 0:
    print("Punkt leży w I ćwiartce.\n\n")

elif xcor < 0 and ycor > 0:
    print("Punkt leży w II ćwiartce.\n\n")

elif xcor < 0 and ycor < 0:
    print("Punkt leży w III ćwiartce.\n\n")

elif xcor > 0 and ycor < 0:
    print("Punkt leży w IV ćwiartce.\n\n")

elif xcor == 0 and ycor == 0:
    print("Punkt leży w środku układu współrzędnych")

else:
    print("Podano złe dane wejściowe.\n\n")