#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Sphere {
public:
    double h, k, l, radius;
    Sphere (double, double, double, double);
};

Sphere::Sphere(double setH, double setK, double setL, double setRadius) {
    h = setH; k = setK; l = setL; radius = setRadius;
}

void printToConsole(bool plane[100][100]) {
    for(size_t y = 0; y < 100; y++) {
        char line[200];
        for(size_t x = 0; x < 100; x++) {
            if(plane[x][y]) {
                line[x * 2] = '0';
                line[x * 2 - 1] = '0';
            } else {
                line[x * 2] = ' ';
                line[x * 2 - 1] = ' ';
            }
        }
        std::cout << line << std::endl;
    }
}

int Hemisphere(int x, int z, int h, int k, int l, int r, int mod) {
    int newY = (int)(k + mod * sqrt(pow(r, 2) - pow(x - h, 2) - pow(z - l, 2)) + 0.5 * mod);
    if (newY != -2147483648) {
        return newY;
    } else {
        return 0;
    }
}
