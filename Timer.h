#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

class Timer{

private:
  static Timer* sInstance;

  unsigned int mstartTicks;
  unsigned int mElapsedTicks;
  float mdeltaTime;
  float mtimeScale;

public:
  static Timer* Instance();
  static void Release();

  void Reset();
  float deltaTime();
  void setTimeScale(float t);
  float getTimeScale();
  void Update();

private:
  Timer();
  ~Timer();

};

#endif
