#ifndef VISUAL_H
#define VISUAL_H

#include "anthill.h"

class Visualizer {
public:
    static void visualize(Anthill& anthill);
private:
    static void enableVTMode(); // Добавьте это
};

#endif