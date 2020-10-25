//Start Date: 25/10/20
//Simple graphics rendering engine

#include <classes.h>

int main() {
    bool world[100][100][100] = {{false}}; //world[z][x][y]
    bool plane[100][100] = {{false}};
    printToConsole(plane);
    for(int z = 0; z < 100; z++) {
        for(int x = 0; x < 100; x++) {
            plane[x][Hemisphere(x,z,50,50,50,30,1)] = true;
            plane[x][Hemisphere(x,z,50,50,50,30,-1)] = true;
        }
        for(size_t y = 0; y < 100; y++) {
            for(size_t x = 0; x < 100; x++) {
                world[z][x][y] = plane[x][y];
            }
        }
        for(size_t y = 0; y < 100; y++) {
            for(size_t x = 0; x < 100; x++) {
                plane[x][y] = false;
            }
        }
    }
    for(size_t z = 0; z < 100; z++) {
        printToConsole(world[z]);
        _sleep(5);
        system("cls");
    }
}
