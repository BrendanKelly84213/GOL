#include "Timer.h"

Timer* Timer::sInstance = NULL;

Timer* Timer::Instance(){
  if(sInstance == NULL){
    sInstance = new Timer();
  }
  return sInstance;
}

void Timer::Release(){

  delete sInstance;
  sInstance = NULL;
}

Timer::Timer(){
  Reset();
  mtimeScale = 1.0f;
}

Timer::~Timer(){
  Release();
}

void Timer::Reset(){
  mstartTicks = SDL_GetTicks();
  mElapsedTicks = 0;
  mdeltaTime = 0.0f;
}

float Timer::deltaTime(){
  return mdeltaTime;
}

void Timer::setTimeScale(float t){
  mtimeScale = t;
}

float Timer::getTimeScale(){
  return mtimeScale;
}

void Timer::Update(){
  mElapsedTicks = SDL_GetTicks() - mstartTicks;
  mdeltaTime = mElapsedTicks*0.001;
}
