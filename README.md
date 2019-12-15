# Fillit_42

Fillit is the last of all projects found on the common branch. The most entertaining one to do too. It is based off the concept of the famous video game called Tetris.
The task is to place a set of tiles in the most upper left corner of a map. Both the map and the shape most be of the smallest size possible.

There are few very important details:
1. The tiles must be read from a file. The file must be formatted in a very specific way to be considered valid.
2. The tiles must be placed in order of appearance in the file. To ease output reading, the first tile must be drawn with 'A', second with 'B', (...).

Evogel and myself implemented a bruteforce recursive backtrack to our code to solve the Fillit problem. Each tile found in the file ends up stored in its individual linked-list node. That allows us to backtrack while in the recursion when a tile has been wrongfully placed in the map in order to retry it placement elsewhere. The downside is that the complexicity of our program exponentially increases as the number of tiles found in file does.

A map over 16 tiles will take 40-ish minutes to be solved.

