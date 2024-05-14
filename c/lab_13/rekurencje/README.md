Laboratorium 13.

Cel:

• Opanowanie programowania z użyciem funkcji rekurencyjnych, wskaźników do funkcji oraz plików

Zajęcia:

1. Utworzenie katalogu roboczego, np. lab_13
2. Skopiowanie pliku potega.c do podkatalogu np. rekurencje
3. Kompilacja i uruchomienie programu (np. tworząc prosty plik Makefile, jako modyfikację pliku
Makefile z poprzedniego laboratorium)
4. Modyfikacja programu polegająca na:
◦ napisaniu (np. na podstawie wykładu) funkcji power_int_rekur obliczającej całkowitą potęgę
liczby całkowitej w sposób rekurencyjny

◦ uzupełnienie kodu o makro assert sprawdzające w funkcji power_int_rekur czy wykładnik jest
liczbą dodatnią

▪ uruchomienie programu z błędnymi danymi – obserwacja zwracanego komunikatu

▪ kompilacja z opcją -DNDEBUG , uruchomienie z błędnymi danymi – obserwacja działania

6. Modyfikacja programu polegająca na przekazywaniu parametrów z linii wywołania programu, np.
przekazanie podstawy i wykładnika – program drukuje podstawa^wykładnik

◦ do przekształcenia w liczby całkowite napisów przekazywanych przez środowisko wywołania i
wskazywanych przez elementy tablicy argv[] można użyć dostarczonej funkcji my_atoi

◦ wywołanie my_atoi można następnie zamienić na wywołanie funkcji bibliotecznej atoi
(ewentualnie strtol) z biblioteki standardowej

8. Modyfikacja kodu poprzez wprowadzenie zmiennej statycznej liczba_wywolan przechowującej liczbę
wywołań funkcji power_int_rekur

◦ liczba_wywolan powinna być inicjowana wartością 0 (takie inicjowanie zmiennej statycznej
dokonywane jest raz na początku wykonywania programu)

◦ liczba_wywolan ma być modyfikowana przy każdorazowym wywołaniu (i ewentualnie drukowana)

◦ power_int_rekur może zwracać komunikat o błędzie w przypadku przekroczenia zadanej (np. przez
#define lub static const int) wartości granicznej

10. Modyfikacja kodu poprzez wczytywanie argumentów funkcji potęgowania z pliku tekstowego
◦ definicja wskaźnika do pliku

◦ otwarcie pliku w trybie odczytu

◦ wczytanie argumentów – użycie fscanf

◦ zamknięcie pliku

◦ wykonanie operacji i wydruk sprawdzający

◦ ewentualnie: otwarcie pliku (w trybie dopisywania), dopisanie wyniku do pliku, zamknięcie pliku

12. Skopiowanie pliku loop_table.c do podkatalogu np. tablice (zamiast pliku loop_table.c można
skopiować plik z kodem zawierającym tworzenie tablic o losowych wartościach napisanym w ramach
poprzednich laboratoriów)

◦ uruchomienie, sprawdzenie poprawności działania (wydruki)

14. Rozszerzenie programu z p.8 o wywołanie funkcji bibliotecznej qsort sortującej utworzoną tablicę
◦ włączenie odpowiednich plików nagłówkowych z prototypami

◦ napisanie funkcji porównywania elementów o odpowiednim prototypie zgodnym z prototypem
funkcji qsort

▪ umieszczenie w kodzie deklaracji i definicji funkcji

• z określeniem inline dla zasugerowania optymalizacji wywołania funkcji (jeśli obsługiwane
przez kompilator)

◦ napisanie wywołania qsort w funkcji main

◦ sprawdzenie działania (kod sprawdzenia wewnątrz dyrektywy kompilacji warunkowej):

▪ poprzez wydruki

▪ poprzez pętlę porównującą dwa kolejne wyrazy dla całej tablicy

• do porównania można użyć makra assert

▪ poprzez porównanie z wynikiem innego algorytmu sortowania, np. napisanym w ramach
poprzednich laboratoriów sortowaniem bąbelkowym

16. Dodanie do programu z p.8 i9 zapisu i odczytu tablic liczbowych do i z pliku tekstowego o wybranej
nazwie
◦ zapis tablicy zaraz po wygenerowaniu – użycie fprintf

◦ odczyt do innej tablicy – użycie fscanf – porównanie wartości w tablicach

▪ poprawność zapisu można także sprawdzić poprzez przeglądanie zawartości pliku w dowolnym
edytorze tekstu

◦ modyfikacja pliku poprzez zmianę wprowadzoną w edytorze tekstu powodującą błąd odczytu

▪ wypisanie informacji o błędzie w trakcie odczytu do standardowego strumienia błędu stderr

◦ wersja początkowa programu może zawierać nazwy plików bezpośrednio wpisane do kodu

◦ wersja ostateczna powinna pobierać nazwę pliku jako argument linii wywołania

▪ nazwa powinna określać pełną ścieżkę do pliku

▪ katalog, w którym mają znajdować się pliki może zostać przekazany jako inny argument linii
wywołania i połączony w jedną nazwę za pomocą odpowiedniej funkcji obsługi napisów, np.
sprintf
