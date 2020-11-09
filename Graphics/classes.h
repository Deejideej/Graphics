#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

class Sphere {
public:
    float h, k, l, r;
    Sphere (float, float, float, float);
    bool Inside(float x, float y, float z) {return (pow(x-h, 2) + pow(y-k, 2) + pow(z-l, 2)) < pow(r, 2);}
};

Sphere::Sphere(float setH, float setK, float setL, float setRadius) {
    h = setH; k = setK; l = setL; r = setRadius;
}

class Camera {
public:
    float x, y, z, xR, yR, zR, fovX, fovY;
    Camera(float, float, float, float, float, float, float);
};

Camera::Camera(float a, float b, float c, float d, float e, float f, float g) {
    x = a; y = b; z = c; xR = d; yR = e; fovX = f; fovY = g;
}

class Line {
public:
    float m, n, h, k;
    Line (float, float, float, float);
    float x(float z) {return z * m + h;}
    float y(float z) {return z * n + k;}
};

Line::Line(float a, float b, float c, float d) {
    m = a; n = b; h = c; k = d;
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

float Rad(float degrees) {
    return degrees * (M_PI / 180);
}
