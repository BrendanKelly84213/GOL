#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>

#include "window.h"
const int WINDOW_WIDTH  = 1920;
const int WINDOW_HEIGHT = 1080;

Window::Window(const char* title, int x, int y, int window_w, int window_h, Uint32 flags )
{
  if(flags==SDL_WINDOW_FULLSCREEN_DESKTOP || flags==SDL_WINDOW_FULLSCREEN){
    window_w = 1920;
    window_h = 1080;
  }

  window = SDL_CreateWindow(title, x, y, window_w, window_h, flags);

  width = window_w;
  height = window_h;

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

int Window::getW(){
  return width;
}

int Window::getH(){
  return height;
}

void Window::Update(){
  SDL_UpdateWindowSurface(window);
}

Window::~Window(){
  SDL_DestroyWindow(window);
}
