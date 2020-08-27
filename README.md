# TPA 2020 - Genetic Algorithm
Questa repository contiene il testo dell'esame del corso "Tecniche di Programmazione Avanzata" del Dipartimento di Ingegneria Industriale, anno accademico 2019/2020.

# Istruzioni
L'esercizio consiste nella progettazione e nell'implementazione di un software C++ per l'ottimizzazione mediante algoritmi genetici. Il software deve essere scritto mediante il paradigma di programmazione ad oggetti, quindi utilizzando ad esempio (ove possibile e sensato):
 * classi
 * incapsulamento
 * ereditarietà
 * polimorfismo
 * passaggio per riferimento
 * passaggio per riferimento costante
 * puntatori
 * metodi const
 * operatori
 * overload
 * valori di default
 * template

Nessun codice di partenza è fornito. Lo studente deve occuparsi sia della progettazione che dell'implementazione. Si consiglia di sottomettere anche il progetto del software, soprattutto se l'implementazione dovesse essere incompleta (ad esempio per mancanza di tempo). Il progetto sarà tenuto in conto nella valutazione finale. Formati accettabili per il progetto sono formati visuali (come pdf o jpeg) o formati testuali semplici (come txt o rtf). Idealmente l'implementazione dovrebbe includere anche una serie di test per verificare il corretto funzionamento del codice scritto.

# Descrizione
Un algoritmo genetico è un algoritmo euristico utilizzato per risolvere problemi di ottimizzazione. In sintesi gli algoritmi genetici partono da un insieme casuale di soluzioni (come se fossero diversi individui biologici) e ricombinandole (analogamente alla riproduzione biologica sessuata) producono nuove soluzioni (nuovi individui) che vengono valutate scegliendo le migliori (selezione ambientale) nel tentativo di convergere verso soluzioni "di ottimo".

Un tipico algoritmo genetico, nel corso della sua esecuzione, fa evolvere delle soluzioni (popolazione) secondo il seguente schema di base:
1. Generazione casuale della prima popolazione di N soluzioni (individui).
2. Calcolo della funzione di fitness per le soluzioni (individui) dell'attuale popolazione.
3. Selezione delle M (<N) soluzioni migliori (ovvero soluzioni con valore più alto della funzione di fitness).
4. Generazione di M soluzioni ibride (usando la tecnica del crossover, spiegata in seguito) a partire dalle M soluzioni scelte al punto 3.
5. Sostituzione delle M soluzioni peggiori (ovvero con valore più basso della funzione di fitness) con le M soluzioni generate al punto 4.
6. Riesecuzione a partire dal punto 2 con la nuova popolazione creata al punto 5.

I parametri N (numero di individui nella popolazione) ed M (numero di individui sostituiti ad ogni iterazione dell'algoritmo) devono essere specificati dall'utente, come il numero totale di iterazioni (generazioni) dell'algoritmo.

#### Esempio
La seguente figura mostra l'esecuzione di un algoritmo genetico per l'ottimizzazione di un vettore binario di 5 elementi. 
La funzione di fitness è la somma degli elementi del vettore, e quindi la soluzione ottima è `x=[1, 1, 1, 1, 1]`.

![Esempio](https://github.com/andreadelprete/tpa2020_genetic_algorithm/blob/master/GA_esempio.png)

L'algoritmo lavora con una popolazione di `N=5` individui, ed ad ogni iterazione (generazione) viene sostituito `M=1` individuo.
L'algoritmo converge dopo 4 iterazioni, trovando la soluzione ottima.

# Consegna
Scrivere un software ad oggetti in C++ per l'ottimizzazione basata su algoritmi genetici. In particolare, il software deve essere in grado di risolvere le due classi di problemi descritti di seguito. L'obiettivo è progettare il codice in modo tale da non duplicare porzioni di codice, ma invece cercare di condividere più codice possibile per risolvere i due problemi. A questo scopo, lo studente è incoraggiato ad utilizzare ereditarietà e polimorfismo.

## 1- Ottimizzazione a dimensione fissa
In questo problema l'obiettivo è trovare il valore della variabile (vettoriale) x che massimizza una data funzione matematica f(x). La dimensione del vettore x è costante e viene specificata dall'utente. Nel caso più semplice in cui la dimensione del vettore x sia uno, allora x è semplicemente un numero scalare.
Nel linguaggio degli algoritmi genetici:
uno specifico valore del vettore x (non di un suo elemento, ma di tutto il vettore) corrisponde ad un individuo
 la funzione da massimizzare f(x) corrisponde alla funzione di fitness. 

#### Crossover
La procedura di crossover può essere implementata in diversi modi, ma deve prendere in ingresso due individui, x1 ed x2, e restituire un nuovo individuo x3 dato dal "mescolamento" di x1 ed x2. Un modo per implementare il crossover può essere quello di spezzare i vettori x1 ed x2 in due parti (effettuando il taglio in un punto casuale), e quindi generare x3 utilizzando la prima parte di x1 e la seconda parte di x2. Ad esempio, supponendo di avere dei vettori di dimensione 5:
```
x1 = [3, 5, 7, 9, 11]
x2 = [2, 4, 6, 4, 2]
```
Se il "taglio" dei vettori dovesse avvenire dopo il secondo elemento, avremmo:
```
x3 = [3, 5, 6, 4, 2]
```
La scelta delle coppie di individui (x1, x2) per il crossover dall'insieme degli M individui migliori identificati al punto 3 può avvenire in diversi modo. Un modo potrebbe essere quello di scegliere casualmente, per M volte, due individui tra gli M disponibili. Un altro modo, supponendo che gli M individui migliori siano salvati in un array/vettore, potrebbe essere di accoppiare ogni individuo j con i suoi due vicini (j-1) e (j+1).

## 2- Ottimizzazione a dimensione variabile
Gli algoritmi genetici possono essere utilizzati anche nel caso in cui la variabile del problema di ottimizzazione abbia una dimensione variabile. Ad esempio, possiamo immaginare il problema di progettare un circuito elettrico, del quale non conosciamo a priori il numero di componenti. Oppure possiamo pensare al problema di selezionare un sottoinsieme di elementi da una lista, senza sapere però quanti elementi debbano essere selezionati per avere la scelta ottimale.
In questo tipo di problemi, gli individui possono essere sempre rappresentati come vettori x, ma la cui dimensione è variabile. La differenza fondamentale rispetto al problema con dimensione fissa è che la procedura di crossover dovrà gestire due vettori in ingresso x1 ed x2 di dimensione potenzialmente diversa. Lo studente è libero di scegliere una procedura di crossover ragionevole che generi x3 a partire da x1 ed x2. Ad esempio, nel caso in cui x1 abbia 3 elementi, ed x2 abbia 5 elementi, potrebbe essere ragionevole che la nuova soluzione generata x3 debba avere tra i 3 ed i 5 elementi. 

