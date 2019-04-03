Fonctionnalitées implémentées:
	_Un slider pour le choix du nombre de slices, aussi changeable via un spinbox
	_Un bouton Clear pour effacer son dessin
	_Un bouton Undo pour revenir en arrière (aussi disponible dans la toolbar et avec le raccourci Ctrl+Z)
	_Un bouton Redo pour annuler un Undo (aussi disponible dans la toolbar et avec le raccourci Ctrl+Y)
	_Un slider pour choisir l'épaisseur du crayon
	_Un bouton pour pouvoir déterminer la couleur du crayon
	_Un mode Multicouleur
	_Un mode miroir
	_Une sauvegarde possible de son dessin au format .png



Fonctionnalitées non-implémentées:
	_Une version internationale du Mandala
	_Le redimensionnage de l'image 
	_La possibilité de charger sa propre image
	_Affichage de la grille



Répartition du travail au sein du binôme:
	Clément:
		_Implémentation du QPainter dessinable
		_Le mode miroir
		_Le mode multicouleur
		_Les options gérables du pinceau

	Benjamin:
		_Design de l'interface graphique
		_Connexions des différents objet à l'interface
		_Fonctionnalitées Undo,Redo,Save


Choix liés à l'ergonomie:
	Nous avons découpé l'interface en 3 blocs. Le blocs de fonctionnalités sont regroupés de façon logique pour que l'utilisateur ne perde pas de temps à se familiariser avec l'environnement.
	Les 3 blocs sont: Un bloc pour les options liées à l'ardoise, le bloc central est réservé à l'ardoise et le bloc de dessous est utilisé pour les options concernant le pinceau.
	Le menu comporte les différentes fonctionnalitées: Save, Undo, Redo et About.
