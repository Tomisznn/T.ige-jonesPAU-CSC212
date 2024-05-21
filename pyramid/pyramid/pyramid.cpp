#include "pyramid.h"
#include "Renderer3D.h"
#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

//Creates an array of points
std::vector<Point3D> points{
    { Point3D{ -1, 1, 1 }, Point3D{ 1, 1, 1 },
        Point3D{ 1,  1, -1 }, Point3D{ -1, 1, -1},
        Point3D{ 0, -1, 0}}
    };

std::vector<Edge> edges{
    Edge{ 0, 1 },
            Edge{ 1, 2 },
            Edge{ 2, 3 },
            Edge{ 3, 0 },
            Edge{ 0, 4 },
            Edge{ 1, 4 },
            Edge{ 2, 4 },
            Edge{ 3, 4 }, // Base edges
    
         };

int main(int argc, char* argv[])
{
 
    SDL_Window* window;
    SDL_Renderer* renderer;

    window = SDL_CreateWindow("Pyramid Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;

    Renderer3D render3D(window, renderer, points, edges);

    while (running)
    {
        if (SDL_QuitRequested()) { running = false; break; }


        render3D.render();
    }
    return 0;
}
