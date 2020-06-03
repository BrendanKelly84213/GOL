#ifndef WINDOW_H
#define WINDOW_H

class Window{
protected:
  SDL_Window* window;
  SDL_Surface* Surface;
  SDL_Event event;
  int width;
  int height;
  bool running;
public:
  Window(const char* title,
    int x=SDL_WINDOWPOS_UNDEFINED,
    int y=SDL_WINDOWPOS_UNDEFINED,
    int window_w=640,
    int window_h=480,
    Uint32 flags=SDL_WINDOW_RESIZABLE);

  int getW();
  int getH();

  void Update();

  SDL_Surface* get_surface();
  ~Window();
 
};

#endif
