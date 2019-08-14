# My awesome project

### **GOLYÓK**

~~~~
* Függvény: x, y, vx, vy alapján ferde hajítást csinál
* Függvény: ha a falnak megy, visszapattan, ha viszont a földnek, akkor a méretétől (súly) függően nagyobbat pattan felfelé
* Függvény: spawnol egy labdát malloccal (lesz +1 labda típusú elem a pályán) + fix magasság, de random bal/jobb oldal
* Labda: x, y, vx, vy, méret (random függvény alapján), szín (mérettől függ -> sebzés hatására színt vált
* Ha az életük a felére csökken, akkor a méretük a felére nő, és kétszereződik
* X élet alatt már nem feleződik, hanem meghal
* Ha meghalt, akkor spawnol pénzt, és valami P eséllyel képességet
* (+) Forognak folyton
~~~~

### **PÉNZEK**

~~~~
* Véletlenszerű értékeik lesznek
* Értéktől függő szín
* Ők is pattognak (ferde hajítás szerűen)
* Ha a játékos hozzájuk ér, akkor az értékük hozzáadódik a számlálóhoz, és felszabadulnak
~~~~

### **JÁTÉKOS**

~~~~
*~~ Mozog a nyilakkal / egér pozícióval~~
* Valami txt filetol függően lő lövedékeket (valahányat egymás mellől, szintén valami filebol kiszedett sebességgel
* Ha hozzáér valamelyik labda, akkor vége a játéknak
~~~~

### **LÖVEDÉKEK**

~~~~
* A játékos "fejétől" indul, azaz mindig középre van rendezve
* A sebességtől, és hogy mennyi golyó van egy sorban függ a mennyiségük (amennyit le kell foglalni)
* Konstans felfelé mozognak, de a pálya tetejét elérve fel lesznek szabadítva, és az alján új spawnol
* Ha valamelyik érintkezik valamelyik labdával, fel lesz szabadítva
* Ha hozzáér valamelyik labdához, akkor a labda élete lemegy a sebzés nagyságával
~~~~