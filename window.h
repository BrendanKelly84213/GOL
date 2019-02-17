#ifndef WINDOW_H
#define WINDOW_H

class Window{
protected:
  SDL_Window* window;
  SDL_Surface* Surface;
  SDL_Event event;
  bool running;
public:
  Window(const char* title,
    int x=SDL_WINDOWPOS_UNDEFINED,
    int y=SDL_WINDOWPOS_UNDEFINED,
    int window_w=640,
    int window_h=480,
    Uint32 flags=SDL_WINDOW_RESIZABLE);
  SDL_Surface* get_surface();
  void Update();
  ~Window();

};

#endif
