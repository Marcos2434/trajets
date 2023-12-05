# Trajets
Small academic project to find all possible routes between stations and methods of transportation defined in the console user interface. C++

- [X] Report (1 page)
- [X] UML Diagram
- [X] DMAP


Structure du Code
Le code est divisé en plusieurs classes, chacune avec son propre fichier d'en-tête et de source :

Trajet (trajet.h, trajet.cpp) : Une classe abstraite représentant un trajet. Elle contient des méthodes virtuelles pures pour afficher le trajet et obtenir les points de départ et d'arrivée.

TrajetSimple (trajetsimple.h, trajetsimple.cpp) : Une classe dérivée de Trajet représentant un trajet simple avec un moyen de transport spécifié. Elle implémente les méthodes de Trajet et inclut des membres pour stocker les points de départ et d'arrivée, ainsi que le moyen de transport.

TrajetCompose (trajetcompose.h, trajetcompose.cpp) : Une classe dérivée de Trajet représentant un trajet composé de plusieurs trajets simples. Elle stocke un tableau de pointeurs vers des trajets simples, ainsi que le nombre de trajets.

Catalogue (catalogue.h, catalogue.cpp) : Une classe pour gérer un catalogue de trajets. Elle peut ajouter des trajets, les afficher et effectuer des recherches avancées.

Corrections
Fuites de mémoire : Les fuites de mémoire ont été corrigées en utilisant correctement les opérateurs new et delete. Les tableaux dynamiques sont redimensionnés lorsque nécessaire pour éviter les débordements de mémoire.

Utilisation de const : Les méthodes qui ne modifient pas l'état de l'objet ont été marquées avec le qualificateur const.

Utilisation de l'opérateur == : L'opérateur == a été corrigé pour comparer les valeurs au lieu d'assigner.

Utilisation du Programme
Le programme principal (dans la fonction main()) crée des trajets simples et composés, les ajoute à un catalogue, puis propose un menu interactif pour l'utilisateur. Les options incluent l'ajout de trajets au catalogue, l'affichage du catalogue, la recherche simple et avancée de trajets, ainsi que la sortie du programme.

Conclusion
Le code a été amélioré en organisant la logique du programme dans des classes distinctes, ce qui facilite la maintenance et la compréhension du code. Les problèmes de mémoire ont été résolus, rendant le programme plus robuste. Les fonctionnalités du programme permettent à l'utilisateur de gérer efficacement des trajets simples et composés dans un catalogue.