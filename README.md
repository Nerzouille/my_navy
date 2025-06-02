
# my_navy

Réalisation d'une bataille navale se jouant à travers deux invités de commande en C.

## Le projet:

Recréation du célèbre jeu dans le but de travailler sur les signaux et la communication avec d'autres programmes, par binômes.

Un des premiers projet de groupe.



## Installation

```bash
Downloads> git clone git@github.com:Nerzouille/my_navy.git
...
Downloads/my_navy> make
...
```
    
## Usage/Examples

```bash
my_navy> ./my_navy -h
    USAGE
        ./navy [pid_player_1] navy_positions
DESCRIPTION
        pid_player_1: only for the 2nd player. pid of the first player.
        navy_positions: file representing the positions of the ships.
```
#### Joueur 1 :
```bash
my_navy> ./my_navy map1.txt
    my_pid: [pid_player_1]

    waiting for ennemy connection...
    <game starting when player 2 connected>
```
#### Joueur 2 :
```bash
my_navy> ./my_navy [pid_player_1] map2.txt
    my_pid: [pid_player_2]

    successfully connected
    <game>
```


## Result

|**Test**|**Result**|**Mouli**|
|--|--|--|
|00 - Cheater|1 / 1|100%|
|01 - Basic signal|2 / 2|100%|
|02 - Rigor|8 / 8|100%|
|03 - Protocol|4 / 4|100%|
|04 - Game|7 / 8|87.5%|
|**__Total__**|22 / 23 |**95.7%**|
|Coding Style|1 / 1|

## Authors

- DELEGER Nathan ([LinkedIn](https://www.linkedin.com/in/nathan-deleger-0a057a2a0/))

- SMOTER Noa ([LinkedIn](https://www.linkedin.com/in/noa-smoter/) / [Portfolio](https://nerzouille.github.io/))
