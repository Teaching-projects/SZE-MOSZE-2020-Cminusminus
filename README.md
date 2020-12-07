# SZE-MOSZE-2020-Cminusminus

Csapattagok: \
	* Mihalovics Fruzsina - I6283S(@fruzsin)
	* Kurucz Ádám - VPX27T(@kurucc)
	* Bólya Richárd - DAWOBY(@bricsi0000000000000)
		

Ez a program egy RPG játékot szimulál, amelyben egy *Hero* küzd meg egy vagy több *Monster*rel, egy adott pályán. A játék elindításához, a futtatni kívánt *game* fájlt kell megadni parancssori argumentumként. A harc addig tart, amíg a *Hero* le nem győzi a pályán lévő összes *Monster*t vagy meg nem hal. 



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

**Feladat 8 - Defense** \
Ebben a feladatban a *Monster* és a *Hero* osztályokhoz kellett új funkciókat bevezetni. A karakterek támadás során védekezni is tudnak.

**Feladat 9 - Damage** \
Ebben a feladatrészben a *Monster* és *Hero* osztályok sima *int damage* változója egy *struct Damage*- re cserélődött. Amelynek a felépítése az alábbi:
```struct Damage
{
    int physical;
	int magical;
}
```
Támadás során a karakterek *defense* változója csak a *physical damage* ellen védekezik, a *magical damage* ellen viszont nem.

**Feladat 10 - Game** \
Ebben a feladatban egy új osztályt hoztunk létre *Game* néven, amely betölt egy térképet, és ezen a térképen elhelyez *Herokat* és *Monstereket*, majd a ,,north", ,,east", ,,west", valamint a "south" parancsokkal lehet irányítani a Herot, és ha az azonos mezőn van egy Monsterrel, vagy több Monsterrel, akkor harcol velük, és ez mindaddig megy, amíg a Hero meg nem hal, vagy meg nem öli a térképen található összes Monstert. Példa kimenet megtalálható a *good-outputs.txt* fájlban.