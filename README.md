# Proiect3_POO

This project aims to implement two design patterns and a template. The complexity level of this project is low as it aims to understand the concepts and present them in an accessible manner. The project's theme is managing a personal shopping. Users are in the position of delivery persons. They need to select the products that customers want and to specify, depending on the choice, certain characteristics. Finally, they display the total order and the price of each product.

The classes presented are:

OfertaZilei, a class within which different objects will be returned, depending on the user's choice. We used the Factory Pattern.
Aperitiv, a template class. It will be useful when we want to display the final price of a product (price/kg * quantity).
Rulada, a class with the attributes: - weight (int) - priceKg (int) - calories (int)
Chec, a class with the attributes: - weight (int) - priceKg (int) - sugar (int)
Desert, a class with the attributes: - servingType (string - "cold"/"hot") - price (int)
Meniu, a class that can only have one instance of this kind. This class is the core of the code.
The specific functions of each class are as follows:

OfertaZilei
oferta(int) -> returns a specific object
afisarePret() -> pure virtual function
Aperitiv
afisarePret() -> returns final price of a product
Desert
afisarePret()
Meniu
generareUnic() -> generates a Meniu object. (One single, unique)
start() -> illustrates the interactive menu
cos() -> displays a shopping cart
Desert and Aperitiv are derived classes of OfertaZilei in order to use the Factory Pattern.
The data and the order in which they need to be entered by the user from the keyboard are indicated by the program. The code being elementary, it does not treat exceptions, so the data must comply with the imposed restrictions.

Acest proiect are ca scop implementarea a două design pattern-uri și a unui template. Gradul de complexitate al acestuia este unul redus întrucât urmărește înțelegerea conceptelor și prezentarea lor într-o manieră accesibilă. Proiectul are ca temă gestiunea unui personal shopping. Utilizatorii se află în poziția de livratori. Aceștia trebuie să selecteze produsele pe care clienții le doresc și să specifice, în funcție de alegere, anumite caracterstici. În cele din urmă aceștia afișează totalul comenzii, dar și prețul fiecărui produs. 

## Prezentarea claselor 

**OfertaZilei** constituie o clasă, în interiorul căreia se vor returna diferite obiecte, în funcție de alegerea utilizatorului. Am folosit *Factory Pattern*.

**Aperitiv** constituie o clasă *template*. Acesta va fi folositoare în momentul în care vom vrea să afișăm prețul final al unui produs (pret/kg * cantitate).

**Rulada** constituie o clasă cu atributele : - gramaj (int)
                                              - pretKg (int)
                                              - calorii (int)

**Chec** constituie o clasă cu atributele : - gramaj (int)
                                            - pretKg  (int)
                                            - zahar (int)
                                            
**Desert** constituie o clasă cu atributele : - tipServire (string - "rece"/"cald")
                                              - pret (int)
                                              
**Meniu** constituie clasa care poate avea o singură instanță de acest fel. Această clasă constituie nucleul codului. 

## Prezentarea funcțiile specifice fiecărei clase

**OfertaZilei** 

- oferta(int) -> returnează un obiect specific

- afisarePret() -> funcție virtuală pură

**Aperitiv** 

- afisarePret() -> returnează pretuș final al unui produs

**Desert** 

- afisarePret()

**Meniu** 

- generareUnic() -> generează un obiect de tip meniu. (Unul singur, unic)

- start() -> ilustrarea meniului interactic
          
- cos() -> afiseaza un desen :shopping_cart:
                                              
Desert și Aperitiv sunt clase derivate ale clasei OfertaZilei pentru a putea folosi Factory Pattern.

Datele și ordinea în care acestea trebuie introduse de la tastatură de către utilizator sunt indicate și de program. Codul fiind unul elementar, nu tratează excepții, spre urmare datele trebuie să respecte restricțiile impuse. 
