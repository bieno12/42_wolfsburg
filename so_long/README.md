# So_Long Game

So_Long is a simple game where the player's goal is to collect every collectible present on the map, then escape by choosing the shortest possible route. The game is developed using the MiniLibX graphics library and C language.

## Game Instructions
- The player should use the W, A, S, and D keys to move the main character.
- The player should be able to move in four directions: up, down, left, right.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- The game uses a 2D view (top-down or profile).
- The game doesn't have to be real-time.

## Graphic Management Instructions
- The program displays the game in a window.
- The management of the window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window's frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

## Map Instructions
- The map has to be constructed with three components: walls, collectibles, and free space.
- The map can be composed of only these 5 characters: 0 for an empty space, 1 for a wall, C for a collectible, E for a map exit, P for the player's starting position.
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- The map must be rectangular.

## How to Play
1. Clone the repository to your local machine.
2. Run `make` command to compile the game.
3. Run `./so_long <map_file>` to start the game with the specified map file.
4. Use W, A, S, and D keys to move the player in the game.
5. Collect all collectibles to win the game.
6. Reach the exit to escape the game.
7. Press ESC or close the game window to quit the game.

## Example Map
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

## Credits
So_Long is a project from the curriculum of 42 School. The game was developed with C language and MiniLibX graphics library.
