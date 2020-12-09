# Tagok

| Név | Github azonosito  | Javasolt relatív érdemjegy | Becsült óra | Indoklás  | 
| --- | ---- | --- | ------------------ | --------- |
| Kurucz Ádám| @kurucc | 0 | 40-50 | Amelyik feladat ki lett osztva neki, azt mindig megcsinálta, szépen kidolgozta. Miután Richárd csapattársunknak nem volt ideje csinálni a saját részét, akkor ha kellett átvette azokat. |
| Mihalovics Fruzsina | @fruzsin | 0 | 40-50 | Minden feladatát megcsinálta időre, rendesen. És ő is átvett feladatokat miután Richárdnak nem volt ideje rá. |
| Bólya Richárd | @bricsi0000000000000 | -4 | <10 |Eleinte megcsinálta a feladatait időre, viszont később már nem volt ideje ezekre, ezért megcsúszott a határidőkkel és később pedig már nem is vállalt feladatokat.|


# Videók

 - [Gameplay](/videos/gameplay.mp4)
 - [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat | Merge ideje a határidóhöz (nap) | Change request körök | Reviewer | 
| ------- | ------------------------------- | -------------------- | -------- |
| Feladat 1 | 0 | 3 | @hegyhati| 
| Feladat 2 | +6 | 1 | @hegyhati |
| attackspeed | 0 | 1 | @vizvezetek |
| levelup | +2 | 3 | @oliverosz |
| jsonparser | +31 | 2 | @wajzy / CLOSE (11.04) után: @fruzsin |
| documentation | +12 | 0 | @fruzsin |
| makefile | +13 | 0 | @fruzsin |
| unittest | +14 | 0 | @kurucc |
| refactor | +17 | 0 | @kurucc |
| docker | +19 | 0 | @fruzsin |
| jsonpimp | Merge: 11.23 | 0 | @kurucc |
| map | Merge: 11.23 | 0 | @fruzsin |
| defense | Merge: 11.24 | 0 | @kurucc |
| damage | Merge: 11.24 | 0 | @fruzsin |
| game | Merge: 11.26 | 0 | @fruzsin |
| markedmap | Merge: 11.29 | 0 | @fruzsin |
| light radius | Merge: 11.29 | 0 | @kurucc |
| preparedgame | Merge: 11.30 | 0 | @kurucc |
| rendering | Merge: 12.09 | 0 | @kurucc |
| report | Merge: 12.09 | 0 | @fruzsin |

# Unit tesztek

| Osztály | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| --- | --- | --- | --- |
| `Monster` | 17 | 9 | 3 |
| `Hero` | 7 | 5 | 4 | 
| `JSON` | 8 | 2 | 3 |
| `ParseException` | 1 | 1 | 1 |
| `Map` | 7 | 5 | 5 |
| `WrongIndexException` | 1 | 2 | 4 |
| `MarkedMap` | 3 | 3 | 6 |
| `Game` | 16 | 6 | 6 |
| `AlreadyHasHeroException` | 1 | 1 | 1 |
| `AlreadyHasUnitsException` | 1 | 1 | 1 |
| `GameAlreadyStartedException` | 1 | 0 | 0 |
| `NotInitializedException` | 1 | 1 | 1 |
| `OccupiedException` | 1 | 1 | 1 |
| `PreparedGame` | 1 | 0 | 0 |
| `Renderer` | 2 | 0 | 0 |
| `TextRenderer` | 4 | 0 | 0 |
| `HeroTextRenderer` | 3 | 0 | 0 |
| `ObserverTextRenderer` | 3 | 0 | 0 |
| `SVGRenderer` | 2 | 1 | 1 |
| `CharacterSVGRenderer` | 2 | 1 | 1 |
| `ObserverSVGRenderer` | 2 | 1 | 1 |


# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| --- | --- | --- | 
| `Monster` | - | - |
| `Hero` | - | - |
| `JSON` | - | - |
| `ParseException` | - | - |
| `Map` | - | - |
| `WrongIndexException` | - | - |
| `MarkedMap` | - | - |
| `Game` | - | - |
| `AlreadyHasHeroException` | - | - |
| `AlreadyHasUnitsException` | - | - |
| `GameAlreadyStartedException` | - | - |
| `NotInitializedException` | - | - |
| `OccupiedException` | - | - |
| `PreparedGame` | - | - |
| `Renderer` | - | - |
| `TextRenderer` | - | - |
| `HeroTextRenderer` | - | - |
| `ObserverTextRenderer` | - | - |
| `SVGRenderer` | - | - |
| `CharacterSVGRenderer` | - | - |
| `ObserverSVGRenderer` | - | - |


# Mindenféle számok

 - Összes cpp kódsor : 1281
 - Egyéb kódsor (make,doxyfile,shellscript,main_test,workflow) : 3128
 - cppcheck
   - warning : 0
   - style : 0
   - performance : 1
   - unusedFunction : 0
   - missingInclude : 0
 
# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - alapvető shell scripting
 - `std::variant`
 - videószerkesztés
 - SVG fájl készítés
 - Linux használat

# Feedback
 

# Üzenet a jövőbe
Egyszerűbb, ha Linuxot használunk.