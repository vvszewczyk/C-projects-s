Laboratorium 7.

Cel:

• Opanowanie podstaw przetwarzania tablic znaków w C
Zajęcia:

1. Utworzenie katalogu roboczego lab_7
2. Skopiowanie za strony przedmiotu pliku kopiowanie.c do nowego podkatalogu np. kopiowanie
3. Analiza programu kopiowania z stdin do stdout, uruchomienie
◦ modyfikacja polegająca na zastosowaniu skrótowego zapisu (jak na wykładzie)

◦ modyfikacja polegająca na przerwaniu wczytywania także dla znaku końca linii

▪ wariant 1 – umieszczenie dodatkowego warunku w pętli while

▪ wariant 2 – dodanie w treści pętli dodatkowego warunku i instrukcji break

5. Modyfikacja polegająca na wczytywaniu do tablicy znaków:
◦ definicja tablicy o zadanej długości

◦ wczytywanie do tablicy

◦ przerwanie wczytywania w przypadku zbyt długiego strumienia znaków przed EOF lub \n

◦ wypisywanie wartości liczbowych znaków

7. Skopiowanie za strony przedmiotu pliku switch.c do nowego podkatalogu np. zliczanie
8. Analiza programu switch.c zliczającego kolejne cyfry wczytywane ze standardowego wejścia,
uruchomienie programu
9. Modyfikacja programu polegająca na zamianie instrukcji switch, na instrukcje if ... else if ... else
◦ instrukcje if mają sprawdzać nie pojedyncze znaki, lecz zawieranie się wartości liczbowych znaków
w określonym przedziale

Tematy rozszerzające:
1. Rozszerzenie programu wczytującego znaki do tablicy o wykonywanie dalszych działań, np.:
◦ dla napisów: obliczanie długości napisu, kopiowanie napisów, porównywanie napisów

◦ dla tablicy zawierającej litery, zamiana wielkich liter na małe i na odwrót

◦ dla dowolnych tablic zamiana kolejności znaków w tablicy

◦ dla dowolnych tekstów zliczanie znaków, słów, linii, itp. (porównanie z efektami działania takich
funkcji z biblioteki string.h jak np. strlen, wc)

- opracowując kod nowych funkcji można posłużyć się materiałami z wykładu i zawartością pliku
wzorce na stronie przedmiotu

• na ocenę 4.0 wystarczą 3 funkcje z pierwszego punktu

2. Stworzenie własnego programu, np. histogram.c, w nowym podkatalogu np. histogram, który będzie:
◦ wczytywał losowe znaki do tablicy znaków o zadanej długości

◦ obliczał histogram dla napisu, czyli tablicę z liczbą wystąpień każdego znaku

▪ można zacząć od histogramu cyfr, jak w przypadku programu switch.c

▪ wystarczy kilka cyfr i liter

◦ analiza histogramu utworzonej tablicy – jak powinien wyglądać dla bardzo długich tablic?

4. Graficzna prezentacja tworzonego histogramu (pojedyncza linijka - pojedynczy znak, liczba wystąpień
znaku ilustrowana liczbą wydruków wybranego znaku (np. '*')

a ******

b *

c ********* (itd. itp.)

◦ liczba wystąpień bezwzględna – dla krótkich napisów

◦ liczba wystąpień relatywna, np. w procentach (jeden znak '*' na 5% lub 10%) - dla dłuższych
napisów
