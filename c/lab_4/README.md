Laboratorium 4.

Cel:
• Opanowanie tworzenia prostych programów w C zapisujących wartości zmiennych różnych typów oraz
wykonujących podstawowe operacje na zmiennych.

Zajęcia:
1. Utworzenie katalogu roboczego lab_4.
2. Skopiowanie ze strony przedmiotu do katalogu programu zmienne.c
3. Kompilacja w terminalu i sprawdzenie działania.
1. Program początkowo nie zawiera instrukcji wykonywalnych (z wyjątkiem printf)
2. W trakcie laboratorium należy czytać kolejne linie programu:
1. linie zaczynające się od ////** stanowią komentarz i instrukcje wykonywania zadań
2. linie zaczynające się od // po odkomentowaniu stanowią poprawny kod, który należy
uruchamiać w trakcie laboratorium
4. Odkomentowywanie i analiza kolejnych linii programu – w grupach zaznaczonych w kodzie
kolejnymi numerami (w kodzie znajdują się także wskazówki konkretnych działań),
połączona z rozszerzeniem wiedzy o kolejnych aspektach traktowania zmiennych w programach
C na podstawie: stron podręcznika systemu Linux (man), materiałów do przedmiotu (slajdy z
wykładu, podręczniki) lub informacji dostępnych w internecie

◦ definicje zmiennych podstawowych typów, ewentualnie połączone z inicjowaniem

▪ dopuszczalne nazwy zmiennych

◦ stałe (literały) występujące w kodzie źródłowym

▪ liczby, znaki, napisy

▪ dyrektywa #define – zamiana tekstu w kodzie na zdefiniowaną wartość

◦ operacje wypisywania wartości zmiennych, funkcja printf

▪ poznanie i przetestowanie rozmaitych opcji formatowania wydruku

◦ operacje na zmiennych typów podstawowych – modyfikacje kodu i ich testowanie

▪ operacja przypisania – jawne i niejawne konwersje typów

▪ operacje arytmetyczne na zmiennych liczbowych – jednoargumentowe i

dwuargumentowe

• niejawne konwersje typów

• kolejność wykonywania operacji

◦ rola nawiasów dla czytelności zapisów, takich jak np. a+++b

• dokładność zmiennych typów float i double

◦ błędy zaokrągleń

▪ operacje logiczne i wartości wyrażeń – prostych i złożonych

Tematy rozszerzające:
1. Wyszukiwanie konkretnych operacji dla których niska precyzja zmiennych float prowadzi do
wyników błędnych z matematycznego punktu widzenia, np.

▪ (1/x)*x != 1 ,

▪ a+b=a (dla b!=0)

• znalezienie granicznej wartości różnicy między a i b , dla której a+b=a:

◦ w przypadku liczb typu float

◦ w przypadku liczb typu double

▪ itp.
