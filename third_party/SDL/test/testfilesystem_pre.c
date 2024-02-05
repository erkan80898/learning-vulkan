/*
  Copyright (C) 1997-2023 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/
/* Call SDL_GetPrefPath to warm the SHGetFolderPathW cache */

/**
 * We noticed frequent ci timeouts running testfilesystem on 32-bit Windows.
 * Internally, this functions calls Shell32.SHGetFolderPathW.
 */

#include "SDL.h"

int main(int argc, char *argv[])
{
    Uint64 start;
    (void)argc;
    (void)argv;
    SDL_Init(0);
    start = SDL_GetTicks();
    SDL_GetPrefPath("libsdl", "test_filesystem");
    SDL_Log("SDL_GetPrefPath took %" SDL_PRIu64 "ms", SDL_GetTicks() - start);
    SDL_Quit();
    return 0;
}
