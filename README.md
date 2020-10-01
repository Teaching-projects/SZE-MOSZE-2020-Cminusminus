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
**Feladat 2**
A program először leellenőrzi, hogy a parancssori argumentumok száma megfelelő-e *(Kettő fájl van-e megadva)*, majd, ha igen, akkor, annak a két fájlnak a létezését ellenőrzi le a **fileExists** nevű függvénnyel. Ha bármely fájl nem létezik a program kilép és kiírja melyik fájl az, amelyik nem létezik. Ha mindkét fájl létezik, akkor lefut a **battle** nevű függvény és kiírja, hogy *character_name* wins. Remaining HP: *xxx*.

