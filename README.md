# Proiect3_POO

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
