# Debugger 101 antwoorden
Bram de Bondt <br>
12-09-2025


> **Oefening 1.**
>
> Plaats een breakpoint op regel 40 van `debugger.py`. Dit kan je doen door met de muis te klikken op de plek van het rode bolletje in het onderstaande plaatje.
>
> Draai de debugger. Je ziet nu dat deze op regel 40 stopt.
>
> ![Breakpoint](images/breakpoint.png)
> 
> Uitgevoerd, geen antwoord gevraagd.


> **Oefening 2.**
>
> Plaats nog een breakpoint op regel 45 en draai de debugger opnieuw. De code stopt nu als het goed is op regel 40. Druk op ![continue](images/continue.png) om het programma door te laten draaien tot regel 45.
> Druk nogmaals op ![continue](images/continue.png). Wacht even en druk op ![pause](images/pause.png). Waar in de code bevinden we ons? Je kan ervoor kiezen om het programma verder te laten draaien. Of, als je denkt dat
> dit te lang gaat duren, druk je op ![stop](images/stop.png).
> 
> Antwoord: <br>
> Na het pauzeren bevinden we ons op regel 48. 


> **Oefening 3.**
>
> Start wederom de debugger. Wanneer je code op regel 40 is gestopt. Ga je met ![Step over](images/step_over.png) naar regel 41.
> Vervolgens ga je met ![Step into](images/step_into.png) de methode `change_name()` in. Bekijk de code, wat valt je op? Als je de functie hebt bestudeerd,
> ga je uit de functie met ![Step out](images/step_out.png). Sluit vervolgens je sessie met ![Stop](images/stop.png).
> 
> Antwoord: <br>
> In de functie staat "self.naem", dit zorgt ervoor dat er een nieuw attribuut voor object student aangemaakt wordt i.p.v. dat de huidige naam wordt veranderd. Dit zou dus "self.name" moeten zijn.


> **Oefening 4.**
>
> Zet een breakpoint op regel 42 en draai de debugger tot het programma daar stopt. Bevestig dat op de call stack nu alleen
> "\<module\>, debugger.py:42" staat. Het programma is op dit moment dus bezig met het uitvoeren van de module `debugger.py`.
>
> Ga vervolgens de functie `get_serial()` in met
> ![step into](images/step_into.png). Nu zie je dat er een call aan de stack is toegevoegd: "set_serial, debugger.py".
>
> Ga door tot de regel waar de functie `join()` van de _standard library_ wordt aangeroepen. Je kan daarvoor drie maal ![step into](images/step_into.png) drukken.
> Nu zie je "\<genexpr\>" en "choice, random.py".
>
> Tot slot een leuk feitje: de website 'stackoverflow.com' heeft te maken met de stack die we in ons frames window zien groeien en krimpen naar mate
> we meer function calls doen. Een overflow is wanneer er teveel calls op de stack komen en de stack vol raakt. Hoe groot de stack mag worden kan vaak ingesteld worden in je IDE maar dit is meestal 1MB aan RAM.
> 
> Uitgevoerd, geen antwoord gevraagd.


> **Oefening 5.**
>
> Elke variabele heeft een plek in het geheugen van je computer. Dat adres kan je opvragen door de functie `id()` te gebruiken.
>
> Op regel 10 in de code staat `print(id(name))`: deze print het geheugenadres van de variabele `name`. Plaats een breakpoint op regel 40, en voeg een watch toe voor `id(name)`.
> Dit kan door in de evaluation bar "adres=id(naam)" te typen en op enter te drukken. Bepaal nu het volgende:
> - Doe op regel 40 een ![step into](images/step_into.png): is het adres nog beschikbaar in de huidige scope?
>   - Antwoord: Ja het adres is in de huidige scope nog steeds beschikbaar.
> - Is het adres gelijk aan dat van name? Zo ja, wat betekent dat eigenlijk?
>   - Antwoord: Ja deze twee adressen zijn hetzelfde. Dit betekent dat naam en name in dit geval naar hetzelfde object verwijzen.
> - Op regel 11 staat `name = "Davis"` wat zijn de adressen van `naam` en `name` nu respectievelijk? Verklaar de resultaten.
>   - Antwoord: Het adres van naam is nu 1430610776672, die van name is nu 1430610772880. Ze zijn nu niet meer gelijk. Dit komt omdat na regel 11 id(name) nu het id is van "Davis", de variabele "naam" blijft onveranderd en is nog steeds "David".
> - Op regel 6 staat `x=2`, probeer te bepalen of `x` beschikbaar is in de scope van de `__init__()` call. Gebruik de evaluation bar.
>   - Antwoord: Bij het gebruiken van "globals().get("x")" is er te zien dat voor regel 13 geldt dat x = 2, hij heeft dus toegang tot x. Na regel 13 geldt x = 4, dan wordt het gezien als een lokale x.
> - Ga terug naar de scope in de \<module\> call en bepaal of `name` nog beschikbaar is.
>   - Antwoord: Nee, daar is name niet beschikbaar. Dat komt omdat daar nog alleen "naam" is gedefinieerd. "name" wordt pas bepaald in "__init__" en daar zijn we hier nog niet voorbij.
> - Is de waarde van x aangepast? Probeer te beredeneren wat er is gebeurd.
>   - Antwoord: Nee, x is niet aangepast. x = 2 is globaal en blijft 2, in regel 13 met x = 4 wordt de waarde veranderd voor een lokale variabele die alleen binnen die functie bestaat. Ze blijven dus apart.
> - Wat zou er gebeuren als we `global x` bovenaan onze `__init__()` methode zouden toevoegen?
>   - Antwoord: Dan zou na regel 13 ook de globale x veranderen van waarde. globale x wordt dan ook 4.


> **Oefening 6.**
>
> *Conditional breakpoints* zijn breakpoints die alleen getriggerd worden onder bepaalde omstandigheden. Door met rechter
> muisknop op een breakpoint te klikken kan je een conditie toevoegen.
>
> - Maak gebruik van een conditional breakpoint om erachter te komen wat de waarde van `what_am_i` is op het moment dat `v1` en `v2` voor het eerst gelijk zijn aan elkaar.
> - Wat is de waarde van `what_am_i` op dit moment?
>   - Antwoord: Door een conditional breakpoint op regel 34 te gebruiken, is er bij deze uitvoering te zien dat what_am_i = 2.2254363327930515 als v1 == v2 geldt. 
> - Na hoeveel iteraties kwam dit voor?
>   - Antwoord: Dit kwam voor na 71 iteraties.
> - Ga door tot regel 36, hier staat de conditie `if self.name == "David":` en pas `self.name` aan zodat deze gelijk is aan `David` met behulp van de evaluation bar.
>   - Geen antwoord gevraagd.