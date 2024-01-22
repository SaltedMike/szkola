import random

def SprawdzPesel(numer):
    pesel = []

    try:
        # Sprawdzanie czy wartość to liczba
        for el in numer:
            pesel.append(int(el))

        # Sprawdzanie długości, poprawności
        if len(pesel) == 11:
            if (pesel[0] > 2) and ((pesel[2] == 0 and pesel[3] < 1) or (pesel[2] == 1 and pesel[3] > 2)):
                return False
            elif (pesel[4] > 3) or (pesel[4] == 3 and pesel[5] > 1):
                return False
            elif (pesel[0] == 0 or pesel[0] == 1 or pesel[0] == 2) and (pesel[2] < 2 or pesel[2] > 3):
                return False
            else:
                # Liczba kontrolna
                Waga = (pesel[0] + pesel[1] * 3 + pesel[2] * 7 + pesel[3] * 9 + pesel[4] +
                        pesel[5] * 3 + pesel[6] * 7 + pesel[7] * 9 + pesel[8] + pesel[9] * 3 + pesel[10])

                if str(Waga)[-1] != '0':
                    return False
        else:
            return False

    except:
        return False

    return True






import random

def GenerujPesel(Dzien, Miesiac, Rok, Plec):
    # Wymagane wartości
    if (Dzien > 31 or Dzien < 1 or Miesiac < 1 or Miesiac > 12 or Rok > 2024 or Rok < 1900):
        return False

    # Dwie ostatnie litery z podanego roku i uzupełnianie
    if Rok >= 2000:
        Miesiac += 20
                                 
    litery = str(Rok)[-2:] + str(Miesiac).rjust(2, '0') + str(Dzien).rjust(2, '0') #dwie ostatnie liczby roku  i #dopelnianie 0 na poczatku do 2 liczb

    for _ in range(3):
        a = random.randint(0, 9)
        litery += str(a)

    if Plec.lower() == 'kobieta':
        litery += str(random.randint(0, 4) * 2)
    elif Plec.lower() == 'mezczyzna':
        litery += str(random.randint(0, 4) * 2 + 1)
    else:
        return False

    numer = []
    for znak in litery:
        numer.append(int(znak))

    suma_wag = (numer[0] + numer[1] * 3 + numer[2] * 7 + numer[3] * 9 + numer[4] +
                numer[5] * 3 + numer[6] * 7 + numer[7] * 9 + numer[8] + numer[9] * 3) % 10

    numer.append(suma_wag)

    wynik = ''
    for cyfra in numer:
        wynik += str(cyfra)
    return wynik



    




numer = input("Podaj numer PESEL: ")
print(SprawdzPesel(numer))

dzien = int(input("Podaj dzień urodzenia (1-31): "))
miesiac = int(input("Podaj miesiąc urodzenia (1-12): "))
rok = int(input("Podaj rok urodzenia (np. 1990): "))
plec = input("Podaj płeć (Kobieta/Mezczyzna): ")

GeneratorPESELU = GenerujPesel(dzien, miesiac, rok, plec)


while not SprawdzPesel(GeneratorPESELU):
    GeneratorPESELU = GenerujPesel(dzien, miesiac, rok, plec)

if GeneratorPESELU:
    print("Przykładowy PESEL to:", GeneratorPESELU)
else:
    print("Podano błędne dane")

