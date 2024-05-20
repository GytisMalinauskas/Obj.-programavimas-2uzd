# Programa v1.2
**Sistemos specifikacijos**\
*CPU: 2,6 GHz 6-Core Intel Core i7*\
*RAM: 16 GB 2400 MHz DDR4*\
*HDD: Macintosh HD 500GB*\
\
*Tyrimai yra atliekami su 100000, 1000000 ir 10000000 studentu*\
*Kiekvienas studentas turi 10 namu darbu*\
*Tyrimui naudota 3-oji strategija*\
*Laikai aprasyti sekundes formatu*

## Vector programos su CLASS tyrimas

| `100000 studentu` | -O1 | -O2 | -O3 |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 0.165 | 0.169 | 0.165 |
| Studentu Rikiavimas | 0.068 | 0.068 | 0.065 |
| Studentu Skirstymas | 0.01 | 0.009 | 0.009 |
|`.exe` Failo dydis   | 105 KB | 106 KB | 114 KB |

| `1000000 studentu` | -O1 | -O2 | -O3 |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 1.498 | 1.483 | 1.484 |
| Studentu Rikiavimas | 0.768 | 0.745 | 0.708 |
| Studentu Skirstymas | 0.103 | 0.104 | 0.1 |
|`.exe` Failo dydis   | 105 KB | 106 KB | 114 KB |

| `10000000 studentu` | -O1 | -O2 | -O3 |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 16.473 | 15.955 | 15.534 |
| Studentu Rikiavimas | 9.31 | 9.334 | 8.921 |
| Studentu Skirstymas | 1.25 | 1.205 | 1.196 |
|`.exe` Failo dydis   | 105 KB | 106 KB | 114 KB |

# Naudotojo vadovas

## 1. Parsisiųskite ir paruoškite kodą
1. Parsisiųskite `source_code.zip` arba `source.tar.gz`.
2. Išskleiskite parsisiųstą folderį į programavimo aplinką (parsisiųskite reikalingus C++ ir Makefile plėtinius).
3. Paleiskite terminalą arba Command Prompt.
4. Nunaviguokite į `vector` folderį:
   - Naudokite komandą `cd failoPavadinimas`, kad nueitumėte į kitą folderį.
   - Norėdami grįžti vienu folderiu atgal, naudokite komandą `cd ..`.

## 2. Kompiliavimas ir paleidimas
1. Rašykite `make` ir palaukite, kol sistema sukompiliuos reikiamus failus.
2. Toliau rašykite `./run_01`,`./run_02` arba `./run_03` ir jūsų programa turėtų pasileisti. Jei programa nepasileido, vadinasi, praleidote kažkurį žingsnį.
3. Rašydami `make clean` jūs išvalysite visus `.exe` failus.

## 3. Programos naudojimas
1. Paleista programa jums parodys meniu, kuriame bus prašoma įvesti numerį nuo 1 iki 6, kad pasirinktumėte programos eigą:

    ```
    Enter number
    1 - manual input
    2 - generate grades
    3 - generate names and grades
    4 - reading from file
    5 - generate file
    6 - quit / show results
    Number:
    ```

2. Pasirinkus nuo 1 iki 3, bus prašoma įvesti numerį nuo 1 iki 2, kad pasirinktumėte programos eigą:

    ```
    Enter number
    1 - n and m is given
    2 - n and m is not given
    Number:
    ```

    - Pasirinkus skaičių 1, bus prašoma įvesti studentų skaičių ir namų darbų kiekį.
    - Toliau programos eiga skirsis, priklausomai nuo pasirinkto skaičiaus 8-ame žingsnyje.
    - Pasirinkus skaičių 2, sekite instrukcijas.

3. Pasirinkus skaičių 4 iš meniu, bus parodyti visi `.txt` failai. Vieną jų reikia pasirinkti.
   - Kad programa galėtų pasiekti jūsų `.txt` failą, šį failą reikia įdėti šalia `headers` ir `source` failų.
   - `.txt` failas privalo atitikti tokią struktūrą: `vardas pavarde nd1 nd2 ... egz`.

4. Pasirinkus skaičių 5 iš meniu, bus prašoma įvesti studentų skaičių ir namų darbų kiekį.
    
    ```
    How many students you want to generate in file?:
    Number:
    How many tasks should students have (final counts in)?: 
    Number: 
    ```

    - Įvedus studentų skaičių 10000, atitinkamai bus sukurtas `StudentaiGen10000.txt` failas.

5. Pasirinkus skaičių 6 iš meniu, bus prašoma pasirinkti rezultatų išvedimo būdą `f` arba `c`.
    
    ```
    Choose how to output the results:
    f - To file
    c - To console
    Choice:
    ```
    
    - Tuomet bus prašoma pasirinkti skirstymo strategiją, įrašant skaičių nuo 1 iki 3.
      
      ```
      Choose the strategy for sorting
      1 - to 'k' and 'l' containers
      2 - to 'l' and leaving only good students in a 's' container
      3 - optimized and best strategy
      Choice:
      ```
      
    - Tuomet bus prašoma pasirinkti pagal kokį balą norima rūšiuoti, įrašant raidę `a` arba `m`.
      
      ```
      Choose the output grade:
      a - average
      m - median
      Choice:
      ```
      
    - Tuomet bus prašoma pasirinkti rūšiavimo būdą, įrašant skaičių nuo 1 iki 3.

      ```
      Choose how to sort: 
      1 - By name
      2 - By surname
      3 - By grade
      Choice:
      ```

6. Galiausiai bus parodytas atsakymas:
    - Jei pasirinkote išvesti rezultatus terminale arba konsoleje, tai matysite rezultatus konsoleje.
    - Jei pasirinkote rezultatus rašyti į failą, tai rezultatai bus išvesti į failus `lievi.txt` ir `kieti.txt`.

Sekite šias instrukcijas, kad sėkmingai naudotumėte programą. Jei kyla klausimų ar problemų, patikrinkite, ar visus žingsnius atlikote teisingai.
