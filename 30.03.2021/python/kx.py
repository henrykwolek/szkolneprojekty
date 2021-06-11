def maksimum(n):
  #Jeśli zbiór ma mieć mniej niż 0 elementów funkcja zostanie przerwana
  if n <= 0:
    return
  for i in range(0, n):
    a = int(input("Podaj liczbę "))
    if i == 0:
      maks = a
    else:
      if a > maks:
        maks = a
  return maks

m = int(input("Ile elementów "))
print("Najwiekszy element: ", str(maksimum(m)))