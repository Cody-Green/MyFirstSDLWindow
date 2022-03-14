//
// Created by CodeWhy on 3/13/2022.
//

#include "SDL.h"
#include "stdio.h"

const int WIDTH     = 1920;
const int HEIGHT    = 1080;

SDL_Window*     mainWindow          = NULL;
SDL_Surface*    mainWindowCanvas    = NULL;
SDL_Surface*    backgroundImage     = NULL;

bool Init();
bool LoadMedia();
void Close();

bool Init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to Initialize SDL_INIT_VIDEO - SDL_ERROR: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        mainWindow = SDL_CreateWindow("MY FIRST SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if (mainWindow == NULL)
        {
            printf("Failed to Create Window - SDL_ERROR: %s\n", SDL_GetError());
            success = false;
        } else
        {
            mainWindowCanvas = SDL_GetWindowSurface(mainWindow);
        }
    }
    return  success;
}

bool LoadMedia()
{
    bool success = true;

    backgroundImage = SDL_LoadBMP("IMAGES/HELLO.gif");
    if (backgroundImage == NULL)
    {
        printf("Failed to Load Image - SDL_ERROR: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

void Close()
{
    SDL_FreeSurface(backgroundImage);
    backgroundImage = NULL;

    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;

    SDL_Quit();
}

int main(int argc, char* args[])
{
    if (!Init())
    {
        printf("Failed to Initialize\n");
    }
    else
    {
        if (!LoadMedia())
        {
            printf("Failed to Load Media\n");
        }
        else
        {
            SDL_BlitSurface(backgroundImage, NULL, mainWindowCanvas, NULL);
            SDL_Delay(5000);
        }
    }
    Close();
    return 0;
}