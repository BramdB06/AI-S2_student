#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Procedureel programmeren in Python
Formatieve evaluatie

(c) 2024 Hogeschool Utrecht,
Peter van den Berg (peter.vandenberg@hu.nl)

Opdracht: beantwoord de vragen en implementeer de functies zoals aangegeven staat bij elke opgave.

TIP: Bij elke functie staat een voorbeeldaanroep met daarbij de verwachte uitkomst. 
     Als je nog niet zeker bent van je oplossing, kun je meer van dit soort testjes maken.

LET OP! Het is niet toegestaan om bestaande modules te importeren en te
        gebruiken, zoals `math` en `statistics` (builtins en/of random mogen wel gebruikt worden).
"""

import builtins
import random
from tkinter.tix import InputOnly

GREEN = "\x1b[32m"
RED = "\x1b[31m"
BLACK = "\x1b[0m"


# Opgave 1. Leg uit wat het verschil is tussen de onderstaande stukken code:

# Stuk code 1
# if <conditie_1>:
#     <code_blok_1>
# if <conditie_2>:
#     <code_blok_2>

#  Stuk code 2
# if <conditie_1>:
#     <code_blok_1>
# elif <conditie_2>:
#     <code_blok_2>

# TODO: <Bij stuk code 1 zijn het twee aparte if-statements. Als conditie 1 klopt dan voert hij code blok 1 uit en anders niks (want er is geen else), dan gaat hij door naar de tweede if-statement en doet hij hetzelfde. bij code stuk 2 is het één samengesteld if-statement met drie mogelijke uitkomsten: conditie 1 klopt en blok 1 wordt uitgevoerd, conditie 2 klopt en blok 2 wordt uitgevoerd, of er gebeurt niks omdate er weer geen else is.>


# Opgave 2. Wat doet break in een for-loop? En continue?

# TODO: <Een break gooit je uit een for loop, een continue brengt je terug naar het begin >


# Opgave 3. De range() functie kan drie argumenten meekrijgen. 
# Geef een voorbeeld van een range() functie met drie argumenten en leg uit wat de argumenten betekenen.

# TODO: <bv. for i in range(0,10,2). hierbij begint het bij 0 en gaat hij tot 10 met stappen van 2. dus 0, 2, 4, 6, 8.>


# Opgave 4. Wat is het verschil tussen onderstaande functies

# def functie_1():
#     print(<expressie_1>)

# def functie_2():
#     return <expressie_1>

# TODO: <bij de bovenste print je een string, bij de onderste return je een variabele.>


# Opgave 5. Wat is het belangrijkste verschil tussen een tuple en een list? Geef een voorbeeld van een tuple.

# TODO: <lists kan je verandere, tuples niet.>


# Opgave 6. Implementeer de functie trek_twee_kaarten() zoals beschreven in de desbetreffende docstring.

def trek_twee_kaarten():
    J, Q, K = 10, 10, 10
    A = 11
    kaarten = [2,3,4,5,6,7,8,9,10,J,Q,K,A]
    return int(random.choice(kaarten) + random.choice(kaarten))
    pass


# Test de functie `trek_twee_kaarten()`
verwachtte_waarde = 21
random.seed(6)  # Zorgt ervoor dat de random getallen altijd hetzelfde zijn.
print(f"trek_twee_kaarten() =? {verwachtte_waarde}: ", end='')

if trek_twee_kaarten() == verwachtte_waarde:
    print(GREEN + 'de functie `trek_twee_kaarten()` geeft het juiste antwoord!' + BLACK)
else:
    print(RED + 'de functie `trek_twee_kaarten()` geeft niet het juiste antwoord...' + BLACK)


# Opgave 7. Implementeer de functie beste_speler(scores) zoals beschreven in de desbetreffende docstring.

def beste_speler(scores):

    """
    Vindt de spelersnaam met de hoogste score uit de gegeven scores.

    Args:
        scores (dict): De spelers (keys) met hun bijbehorende scores (values).

    Returns:
        string: De naam van de speler die de hoogste score heeft.
    """
    pass


# Test de functie `beste_speler()`
gegeven_argument = {'Sanne': 10, 'Isabella': 20, 'Yassine': 30}
verwachtte_waarde = 'Yassine'

print(f"beste_speler({gegeven_argument}) =? {verwachtte_waarde}: ", end='')
if beste_speler(gegeven_argument) == verwachtte_waarde:
    print(GREEN + 'de functie geeft het juiste antwoord!' + BLACK)
else:
    print(RED + 'de functie geeft niet het juiste antwoord...' + BLACK)


# Opgave 8. Implementeer de functie vraag_getal_onder_n(n) zoals beschreven in de desbetreffende docstring.

def vraag_getal_onder_n(n):
    getal = int(input("geef een getal: "))
    while getal >= n or getal < 1:
        getal = int(input("probeer het opnieuw: "))
    return getal
    pass


# Test de functie `vraag_getal_onder_n()`
gegeven_argument = 11
verwachtte_waarde = 3
inputs = ["12", "3"]  # Simuleert de input; eerst een 12 en dan een 3
builtins.input = lambda _: inputs.pop()  # Past deze simulatie toe op de daadwerkelijke input

print(f"vraag_getal_onder_n({gegeven_argument}) =? {verwachtte_waarde}: ", end='')
if vraag_getal_onder_n(gegeven_argument) == verwachtte_waarde:
    print(GREEN + 'de functie geeft het juiste antwoord!' + BLACK)
else:
    print(RED + 'de functie geeft niet het juiste antwoord...' + BLACK)
