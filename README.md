# README


# TODO list

- [x] Ajouter un constructeur a chaque media
- [] Ajouter un destructeur a chaque media 
  > On peut peut-etre utiliser le destructeur par defaut dans le .h ( ex : ~Media()=default)
- [] Ajout les #IFNDEF dans les .h
- [] Faire la classe User
- [] Faire le README
- [] Faire des test unitaire pour les fonctions
  > Pour s'assurer que les fonctions ont le résultat attendu. Voir a ajouter l'extension TestMate dans Visual studio code pour faciliter les tests
- [] Creer une base de donnee pour les medias (dans un fichier texte)
  > Verifier si il y en pas deja une qui viens avec le projet 

- [] Creer des constructeur par defaut pour les media
  > Demandent a l'utilisateur d'entrer les valeurs pour creer le media.

- [] Creer toutes les commandes
  - [] BYE
    > lorsque l’utilisateur lance cette commande, il demande simplement à quitter votre application. Dans ce cas là, vous devez tout simplement fermer proprement votre outil (dans le sens destruction des ressources allouées)
  - [] ADD type:
    > cette commande lancera la procédure permettant de créer une nouvelle ressource en fonction du type spécifié en paramètre
  - [] LOAD filename : 
    > cette commande doit permettre à l’utilisateur de charger un fichier un fichier contenant les ressources disponibles dans la médiathèque. La contenu de ce fichier viendra remplacer les données actuellement chargées dans l’outil.
  - [] SAVE filename :
    > cette commande permet à l’utilisateur de sauvegarder les données actuellement dans l’outil dans le fichier dont le nom est spécifié en paramètre. Le format de sauvegarde des données est laissé à votre discrétion
  - [] SEARCH chaine : 
    > cette fonction permet de rechercher dans la base de données les documents contenant la chaîne de caractères spécifiée en paramètre. Les résultats issus de la recherche remplaceront temporairement la base de données courante pour faire en sorte que si l’utilisateur lance une seconde recherche elle ne s’appliquera que sur les résultats de la première recherche (recherche incrémentale).
  - [] CLEAR :
    > cette commande permet de réinitialiser la base de données courante après une recherche. Si l’utilisateur emploie cette commande après avoir effectué une recherche alors, les résultats sont détruits et la future recherche s’appliquera à l’ensemble des ressources disponibles dans la médiathèque.
  - [] LIST : 
    > cette fonction permet d’afficher de manière compacte les données contenues dans la base de données. Si une recherche a été lancée, alors cette commande ne doit afficher que les résultats de la recherche précédemment lancée
  - [] SHOW id : 
    > cette fonction doit permettre d’afficher les informations détaillées sur une ressource précise contenue dans la médiathèque. Le paramètre passé lors de l’appel de la procédure utilise un identifiant unique que doit posséder toute ressource appartenant à la médiathèque (identifiant de l’objet par exemple => attribut static). 
  - [] DELETE id : 
    > cette méthode permet de supprimer une ressource particulière appartenant à la médiathèque
  - [] RESET : 
    > cette dernière méthode permet de supprimer toutes les ressources contenues dans la bibliothèque. 