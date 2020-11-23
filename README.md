# SZE-MOSZE-2020-Cminusminus

Ez a program egy RPG játékot fog szimulálni.
Jelenleg 2 **fájlból** beolvasott karakter jön létre, majd harcol egymás ellen, amíg az egyiknek az élete el nem éri a 0-t.

A fájlok **JSON** formátumúak, és az alábbi képpen néznek ki:

```json
{
    "name": "Béla",
    "hp": 1500000,
    "dmg": 14
}
```
**Feladat 2** \
A program először leellenőrzi, hogy a parancssori argumentumok száma megfelelő-e *(Kettő fájl van-e megadva)*, majd, ha igen, akkor, annak a két fájlnak a létezését ellenőrzi le a **fileExists** nevű függvénnyel. Ha bármely fájl nem létezik a program kilép és kiírja melyik fájl az, amelyik nem létezik. Ha mindkét fájl létezik, akkor lefut a **battle** nevű függvény és kiírja, hogy *character_name* wins. Remaining HP: *xxx*.

**Attack speed** \
A **JSON** fájl kiegészül egy újabb sorral **attackCooldown** néven, amely felvehet nem egész értéket is.
```json
{
    "name": "Béla",
    "hp": 1500000,
    "dmg": 14,
    "attackCooldown": 10.7
}
```
A **battle** nevű függvény, annyiban változott így, hogy a karakterek akkor támadják csak meg a másikat, ha az *attackCooldown* eléri a 0-t.


**Dokumentáció link** 

https://teaching-projects.github.io/SZE-MOSZE-2020-Cminusminus--Closed/

**Feladat 3 - Level up** \
A program kiegészül egy új osztállyal, amely a **Character** osztályból származik és **Player** a neve. A **Player** annyiban különbözik a **Character**-től, hogyha az **XP**-je eléri a *100*-at, akkor szintet lép, amely következtében a **damage** megnövekszik *10*%-kal, valamint a **maxHP** szintúgy megnövekszik *10*%-kal és a **HP** a **maxHP**-vel lesz egyenlő.

**Feladat 3 - JSON Parser** \
Ebben a feladatban egy json parsert valósítottam meg, ami 3 féle képpen képes működni. Paraméterként kaphat egy fájl **nevet**, fájl **tartalmát** vagy egy **istreamet**.

**Feladat 4 - Documentation** \
A program kimaradt függvényeit kiegészítettük, amelyekben hiányoztak a doxygen-hez szükséges kommentek.

**Feladat 4 - Makefile** \
Ebben a feladatrészben a ,,miniscripteket" egységesen egy **Makefile** fájlba helyeztük, ami kicsit egységesíti a GHA kódokat és a doxygen dokumentáció generálást.

**Feladat 4 - Unittests** \
Ebben a feladatban különböző **Unittesteket** hoztunk létre a különböző funkciók teszteléséhez.

**Feladat 4 - Refactor** \
Ebben a feladatban egy adott **main.cpp**-hez kellett a programot igazítani, illetve átalakítani a megfelelő működés elérésének érdekében.

**Feladat 5 - Docker** \
Ebben a feladatrészben **Docker** segítségével a különböző sudo-kat, installokat helyeztük egységesen egy **imagebe**, **containerbe**.

**Feladat 6 - JSONPimp** \
Ebben a feladatrészben a main.cpp-ben és a különböző scenariok-ban lévő változtatásokhoz kiegészítettük a JSON parzerünket, és hozzáadtuk a listbe való parzolást is.

**Feladat 7 - Map** \
Ebben a feladatban egy új osztály került létrehozásra, melynek **Map** a neve, és a célja az, hogy egy adott fájlból egy térképet töltsön be. 