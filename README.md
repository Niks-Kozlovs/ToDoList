# ToDoList
Šī programma tika veidota ar Visual Studio 2017 un Desktop development with C++ Workload.
Lai palaistu exe failu vajag būt ielādētam:

Microsoft Visual C++ 2015 Redistributable Update 3
https://www.microsoft.com/en-us/download/details.aspx?id=53840

.NET Framework: v4.0.30319
https://www.microsoft.com/en-us/download/details.aspx?id=17851

Viss vajadzīgais jau ir ielikts failā Redistributables, ja slinkums pašam lādēt

SAVĀDĀK PROGRAMMA NEPALAIDĪSIES UN BŪS ERROR!
==================================Apraksts===================================
Šī programma ļauj izveidot sarakstu ar lietām ko tu vēlies izdarīt, lai būt vieglāk sekot līdzi tam.

Ir arī iespēja sakārtot visu pēc vērtībām (vai burtiem), un filtrēt nevajadzīgās lietas ārā.
Lai filtrētu vai sortotu vajag uzspiest uz pašas augšējās kolonas nosaukuma, tad tiks atslēgta iespēja sortot un filtrēt.
Kad darbs ir pabeigts vai sorton vai filtrēt nevajag vairs vajag uzspiest reset, tad viss tiks atgrezts kā parasti.

Ir iespēja arī izmantot vairākus sarakstus, kas ļau kategorizēt savus darbus, lai būt vieglāk tam sekot līdzi.
Lai to izdarīvu vajag ieiet Lists un uzspiest Add new list. Tad vajadzēs ievadīt saraksta vārdu.

Programmai ir trīs galvenās pogas:
Add new item = pievieno jaunu darbu ko vajag izpildīt
Edit = Rediģē izvēlēto priekšmetu
Delete item = Izdēš izvēlēto priekšmetu (ja tiek izvēlēti vairāki, tad programma tikai izdzēsīs pirmo izvēlēto)

More info poga netika izveidota kā es to gribēju. Bija plānots pievienot daudz vairāk informācijas par izvēlēto priekšmetu, bet tam nepietika laika,
tapēc tas parāda jau redzamu informāciju.

=============================Problēmas========================================
Daudz problēmu nav, ir tikai viena it kā liela problēma. Kad lietotājs izdēš failus ar sarakstiem, tad programma nestrādā līdz
lietotājs nenommaina saglabāšanās vietu (jo nebija ielikta pārbaude vai ir eksistē tāds folder). Visam citam vajadzētu strādāt.
Tikai obligāti vajag izmantot latīņu burtus, jo te tiek izmantoti ASCII characteri. Visam citam vajadzētu strādād, jo ir ieliktas limitācijas
un veiktas pārbaudes.


