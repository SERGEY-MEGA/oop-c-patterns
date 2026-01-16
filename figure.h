#ifndef FIGURE_H
#define FIGURE_H

typedef struct Figure {
    double (*area)(struct Figure*);
    double (*perimeter)(struct Figure*);
} Figure;

#endif
