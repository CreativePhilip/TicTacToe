#ifndef UTILS_H
#define UTILS_H

enum Player{ X, O };
enum Page{ Starting, Game };
enum GameState{ Started, Finished };
enum CellType{ Empty, Xs, Os };

struct CellCoordinate{
    int i;
    int j;
};

#endif // UTILS_H
