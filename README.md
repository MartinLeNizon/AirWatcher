# AirWatcher

## Description
Une agence gouvernementale de protection de l'environnement doit surveiller la qualité de l'air sur un vaste territoire. Pour ce faire, l'agence a installé un certain nombre de capteurs répartis uniformément sur le territoire. Les capteurs génèrent des données à intervalles réguliers.

## Guide d'utilisation
Afin de produire les exécutables, il faut exécuter la commande "make" depuis le répertoire "AirWatcher/Code".
Afin de compiler en mode Debug et/ou en mode performance, il faut modifier les variables DEBUG et PERF dans le makefile.
Pour exécuter l'application, il faut se placer dans le répertoire "AirWatcher/Code", et exécuter la commande "bin/airwatcher".

Afin de réaliser les test : 
    DEBUG et PERFORMANCE doivent être initialisées à "no".
    Il faut se placer dans le répertoire "AirWatcher/Code/Tests"
    Pour exécuter un test en particulier, exécuter la commande "./test.sh TestX.X"
    Pour exécuter tous les tests à la fois, exécuter la commande "./mktest.sh"
    Les résultats des tests apparaîtront dans le fichier "results.csv".

## Auteurs

- Mathis NGUYEN
    mathis.nguyen@insa-lyon.fr
    [@mthsngn](https://github.com/mthsngn)
    
- Hugo SAYSANA
    hugo.saysana@insa-lyon.fr
    [@Weiixiasax](https://github.com/Weiixiasax)
    
- Thibaut CHANTREL
    thibaut.chantrel@insa-lyon.fr
    [@ThibautChantrel](https://github.com/ThibautChantrel)

- Martin NIZON-DELADOEUILLE
    martin.nizon-deladoeuille@insa-lyon.fr
    [@MartinLeNizon](https://github.com/MartinLeNizon)
