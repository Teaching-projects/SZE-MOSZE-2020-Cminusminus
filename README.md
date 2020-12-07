# SZE-MOSZE-2020-Cminusminus

Csapattagok:
- Mihalovics Fruzsina I6283S(@fruzsin)
- Kurucz Ádám VPX27T(@kurucc)
- Bólya Richárd DAWOBY(@bricsi0000000000000)

Ez a program egy RPG játékot szimulál, amelyben egy *Hero* küzd meg egy vagy több *Monster*rel, egy adott pályán. A játék elindításához, a futtatni kívánt *game* fájlt kell megadni parancssori argumentumként. A harc addig tart, amíg a *Hero* le nem győzi a pályán lévő összes *Monster*t vagy meg nem hal. 

**Feladat 1**\
A programban két *Character* csatázik egymással, addig amíg valamelyiknek az élete 0 nem lesz.

**Feladat 2** \
A feladat során két fájlt kell megadni parancssori argumentumként, amelyek a *Character*ek adatait tartalmazza, és így épülnek fel:

```json
{
    "name": "Béla",
    "hp": 1500000,
    "dmg": 14,
}
```
A program először leellenőrzi, hogy a parancssori argumentumok száma megfelelő-e *(Kettő fájl van-e megadva)*, majd, ha igen, akkor, annak a két fájlnak a létezését ellenőrzi le a **fileExists** nevű függvénnyel. Ha bármely fájl nem létezik a program kilép és kiírja, hogy valamelyik fájl nem létezik. Ha mindkét fájl létezik, akkor lefut a **battle** nevű függvény és kiírja, hogy *character_name* wins. Remaining HP: *xxx*.

**Feladat 3**
- **Attack speed** \
A **JSON** fájl kiegészül egy újabb sorral **attackCooldown** néven, amely felvehet nem egész értéket is.
```json
{
    "name": "Béla",
    "hp": 1500000,
    "dmg": 14,
    "attackCooldown": 10.7
}
```
A **battle** nevű függvény, annyiban változott így, hogy először megtámadja egymást a két *Character* és csak ezután indul a timer. És így a karakterek már csak akkor támadják meg a másikat, ha az *attackCooldown*juk eléri a 0-t. Ha pedig egyszerre éri el a 0-t ez az érték, akkor pedig az első támadás sorrendjében támadják meg egymást.

**Dokumentáció link** 

https://teaching-projects.github.io/SZE-MOSZE-2020-Cminusminus--Closed/

- **Level up** \
A program kiegészül egy új osztállyal, amely a *Character* osztályból származik és *Player* a neve. A *Player* annyiban különbözik a *Character*-től, hogy rendelkezik *level*lel, valamint *XP*-vel és hogyha az eléri a *100*-at, akkor szintet lép, amely következtében a *damage* megnövekszik *10*%-kal, valamint a *maxHP* szintúgy megnövekszik *10*%-kal és a *HP* a *maxHP*-vel lesz egyenlő.

- **JSON Parser** \
Ebben a feladatban egy json parsert valósítottam meg, ami 3 féle képpen képes működni. Paraméterként kaphat egy fájl **nevet**, fájl **tartalmát** vagy egy **istreamet**.

**Feladat 4** 
- **Documentation** \
A program kimaradt függvényeit kiegészítettük, amelyekben hiányoztak a doxygen-hez szükséges kommentek.

- **Makefile** \
Ebben a feladatrészben a ,,miniscripteket" egységesen egy **Makefile** fájlba helyeztük, ami kicsit egységesíti a GHA kódokat és a doxygen dokumentáció generálást.

- **Unittests** \
Ebben a feladatban különböző **Unittesteket** hoztunk létre a különböző funkciók teszteléséhez.

- **Refactor** \
Ebben a feladatban egy adott **main.cpp**-hez kellett a programot igazítani, illetve átalakítani a megfelelő működés elérésének érdekében.

**Feladat 5** 
- **Docker** \
Ebben a feladatrészben **Docker** segítségével a különböző sudo-kat, installokat helyeztük egységesen egy **imagebe**, **containerbe**.

**Feladat 6**
- **JSONPimp** \
Ebben a feladatrészben a main.cpp-ben és a különböző scenariok-ban lévő változtatásokhoz kiegészítettük a JSON parzerünket, és hozzáadtuk a listbe való parzolást is.

**Feladat 7**
- **Map** \
Ebben a feladatban egy új osztály került létrehozásra, melynek **Map** a neve, és a célja az, hogy egy adott fájlból egy térképet töltsön be.

- **Defense** \
Ebben a feladatban a *Monster* és a *Hero* osztályokhoz kellett új funkciókat bevezetni. A karakterek támadás során most már védekezni is tudnak. Továbbá a *Hero*nak a *defense* tagja szintlépéskor ugyanúgy megnő.

- **Damage** \
Ebben a feladatrészben a *Monster* és *Hero* osztályok sima *int damage* változója egy *struct class Damage*- re cserélődött. Amelynek a felépítése az alábbi:
```struct class Damage
{
    int physical;
	int magical;
}
```
Támadás során a karakterek *defense* változója csak a *physical damage* ellen védekezik, a *magical damage* ellen viszont nem.
A *Hero*nak pedig itt már a *physical* és *magical* damage változói is megnőnek szintlépéskor.

- **Game** \
Ebben a feladatban egy új osztályt hoztunk létre *Game* néven, amely betölt egy térképet, és ezen a térképen elhelyez *Herokat* és *Monstereket*, majd a ,,north", ,,east", ,,west", valamint a "south" parancsokkal lehet irányítani a Herot, és ha az azonos mezőn van egy Monsterrel, vagy több Monsterrel, akkor harcol velük, és ez mindaddig megy, amíg a Hero meg nem hal, vagy meg nem öli a térképen található összes Monstert. Példa kimenet megtalálható a *good-outputs.txt* fájlban.

**Feladat 8** 
- **MarkedMap**\
A **Map** osztályból származik ez az osztály, és ezen a térképen a *Hero* helyét egy *H* betű jelöli, a *Monster*ek helyét pedig számok, attól függően, hogy milyen típusú *Monster* az.

-**Light Radius**\
Ennek a feladat során a **Game** *drawMap* függvénye változott meg, úgy hogy a *Hero* már rendelkezik egy *lightRadius* és egy *lightRadiusBonusPerLevel* taggal, amelynek hatására nem az egész térkép rajzolódik ki, hanem csak a *lightRadius* hatóköre. Ez a *lightRadius* szintlépsékor ugyanúgy növekszik, így a játék lefolyása során egyre több minden rajzolódik ki.

-**Prepared Game**\
A **Game** osztályból származik ez az osztály, a konstruktorában egy *json* filet vár, amely így néz ki:
```json
{
  "map"  : "markedmap.txt",
  "hero" : "hero.json",
  "monster-1" : "fallen.json",
  "monster-2" : "zombie.json",
  "monster-3" : "BloodRaven.json"
}
```
A fájlt betölti és elhelyezi a *Hero*kat és a *Monster*eket, majd itt is, mint a **Game**nél a "north", "south", "east" és "west" parancsokkal lehet irányítani a *Hero*t és a játék addig meg, amíg az meg nem hal vagy az le nem győzi az összes *Monster*t.

-**SVGRendering**\
Az SVGRendering feladatban 7 új osztály került létrehozásra. A **Renderer** osztályból származik a **TextRenderer** és az **SVGRenderer**. A **TextRenderer**ből származik az **ObserverTextRenderer**, valamint a **HeroTextRenderer**. Az **ObserverTextRenderer** az egész map kirajzolását csinálja a coutra, valamint ha nem default constructorral szeretnénk dolgozni, ebben az esetben meg lehet adni egy fájlnevet, ahova logolja a kimenetet. A **HeroTextRenderer** gyakorlatilag ugyanazt csinálja mint az **ObserverTextRenderer**, ellenben itt csak az előzőleg bevezetett karakterünk által látott területet rajzolja ki, és itt szintén meg tudjuk adni, hogy cout-ra történjen a kiíratás, vagy egy fájlba. Az **SVGRenderer**ből származik a **CharacterSVGRenderer**, és az **ObserverSVGRenderer** osztály. Előbbi megadott svg fájlok felhasználásával a karakter által látott területet logolja szintén egy svg fájlba. Utóbbi pedig szintén svg fájlok felhasználásával az egész map területét logolja szintén egy svg fájlba.
