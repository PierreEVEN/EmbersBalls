# Look at my ball !

![img](./picture.png)

> (note : j'ai eu quelques crash occasionnels du client à la connexion, probablement un cadeau d'UE...)

## Téléchargez Look at my ball !

[Ici : https://fileshare.evenpierre.fr/Pierre/look-at-my-ball/](https://fileshare.evenpierre.fr/Pierre/look-at-my-ball/)

ou bien

[Ici : https://github.com/PierreEVEN/EmbersBalls/releases/tag/V1.0](https://github.com/PierreEVEN/EmbersBalls/releases/tag/V1.0)



## Informations générales

- Version du moteur : UE 5.4.4
- Réalisé à partir du template First person en C++ (en utilisant exclusivement les assets de base du moteur)
- Multijoueur, 4 joueurs maximum

## Gameplay

- 4 joueurs maximum. Chaque joueur a une couleur attribuée : Rouge, Vert, Cyan, Magenta
- Chaque joueur possède un projectile qu'il peut tirer à l'infini
- Lorsque un joueur regarde un projectile, celui-ci gagne de la puissance. Sa puissance maximale est atteinte lorsque tous les joueurs connectés regardent vers celui-ci
- Lorsqu'un joueur est dans la zone d'un projectile, celui-ci peut sauter considérablement plus haut, lui permettant d'atteindre des points inatteignables auparavant.
- Pour atteindre certaines zones, il faudra combiner la puissance de tous les projectiles à leur plein potentiel.

Bon courage !

## Timestamps

- 17h : Je me lance

- 17h30 - Installation UE / VS terminée (30mn)

- 19h30 - Projet en place avec multijoueur fonctionnel + replication des projectiles : ~2h

https://github.com/PierreEVEN/EmbersBalls/commit/7c00da322bd5b9d8afc13b412f2ca024a9be4304

- 20h40 - Ajout des mécaniques de gameplay & comportement du joueur : ~1h10 

https://github.com/PierreEVEN/EmbersBalls/commit/b7b8babea7840e55d3cfa5ab993650455c84842e

- 23h15 - Ajout des effets visuels, fx : ~2h30

https://github.com/PierreEVEN/EmbersBalls/commit/c6217acfc6281816d598168faffd1bceea15faad

- 02h17 - tout est terminé, agrandissement de la map de test + polissage : ~2h

https://github.com/PierreEVEN/EmbersBalls/commit/95979fef21cb3194030bbb2efbb53276504b97a5

## Informations notable

- La partie du code qui détecte si un joueur regarde une balle se trouve dans le code du projectile :
https://github.com/PierreEVEN/EmbersBalls/blob/c72145c73c7b37a494044f97ca57a40c96ff8892/Source/EmbersBalls/EmbersBallsProjectile.cpp#L55 

- Le dossier `Content/FirstPerson` contient l'essentiel des assets gameplay. Les autres dossiers sont ceux du template First Person original sans modification notable. (excepté le master material : `Content/LevelPrototyping/Materials/M_PrototypeGrid`)

- Lorsque le joueur regarde une balle, celle-ci s'illumine et fait apparaître des particules

- Lorsque le joueur rentre dans une zone d'influence, un effet de post processing + audio lui donne une idée de la force du saut. Une barre en bas de l'écran se remplis plus la puissance est proche de la puissance maximale.

- La caméra s'incline sur le coté lorsque le joueur strafe à haute vitesse

- Le FOV s'adapte en fonction de la vitesse de chute pour augmenter la sensation de chute.

- L'arme monte et descend pour accroitre la sensation de vitesse verticale