#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <string>
#include "window.h"

Window::Window(const char* title, int x, int y, int window_w, int window_h, Uint32 flags)
{
  window = SDL_CreateWindow(title, x, y, window_w, window_h, flags);

  if(window == NULL){
    std::cout << "Error opening window " << SDL_GetError() << std::endl;
  }

  Surface = SDL_GetWindowSurface(window);

  if(Surface == NULL){
    std::cout << "Error getting surface" << SDL_GetError() << std::endl;
  }
}

SDL_Surface* Window::get_surface(){
  return Surface;
}

void Window::Update(){
  SDL_UpdateWindowSurface(window);
}

Window::~Window(){
  SDL_DestroyWindow(window);
}
