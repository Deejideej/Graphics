//Start Date: 25/10/20
//Simple graphics rendering engine

#include <classes.h>

int main() {
    Sphere roundy(70, 50, 50, 10);
    Sphere circle1(20, 80, 50, 10);
    Sphere tiny(40, 30, 80, 4);
    Camera player(50, 50, 0, 0, 0, 90, 60);
    bool world[100][100][100] = {{false}}; //world[z][x][y]
    bool plane[100][100] = {{false}};
    bool view[100][100] = {{false}};

    printToConsole(plane);
    for(int z = 0; z < 100; z++) {

        for(int x = 0; x < 100; x++) {
            //plane[x][Hemisphere(x,z,50,50,50,30,1)] = true;
            //plane[x][Hemisphere(x,z,50,50,50,30,-1)] = true;
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
    double fovX = 90; //camera will send 100 lines out at a range of -45 to 45 degrees
    double fovY = 90; //camera will send 100 lines out at a range of -45 to 45 degrees
    double incrementX = fovX / 100;
    double incrementY = fovY / 100;
    while (true) {
        for(size_t i = 0; i < 100; i++) {
            for(size_t j = 0; j < 100; j++) {
                Line boop(sin(Rad(incrementX * j - fovX / 2 + player.xR)), sin(Rad(incrementY * i - fovY / 2 + player.yR)), player.x, player.y);
                for (size_t z = 0; z < 100; z++) {
                    if (roundy.Inside(boop.x(z), boop.y(z), z) || circle1.Inside(boop.x(z), boop.y(z), z) || tiny.Inside(boop.x(z), boop.y(z), z)) {
                        view[j][i] = true;
                        //std::cout << boop.x(z) << " " << boop.y(z) << std::endl;
                        z = 100;
                    } else {view[j][i] = false;}
                }
            }
        }
        system("cls");
        printToConsole(view);
        if(GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            player.yR -= 1;
        }
        if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            player.xR -= 1;
        }
        if(GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            player.yR += 1;
        }
        if(GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            player.xR += 1;
        }
        if(GetKeyState('F') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            roundy.l += 5;
            circle1.l += 5;
            tiny.l += 5;
        }
        if(GetKeyState('G') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            roundy.l -= 5;
            circle1.l -= 5;
            tiny.l -= 5;
        }
    }
}
