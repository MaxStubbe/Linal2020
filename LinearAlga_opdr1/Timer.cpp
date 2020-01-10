#include "Timer.h"
#include <SDL.h>

Timer::Timer() {
}

void Timer::start()
{
	running_ = true;
	start_time_ = SDL_GetTicks();
}

void Timer::stop()
{
	running_ = false;
}

void Timer::reset()
{
	start_time_ = SDL_GetTicks();
}

bool Timer::is_running()
{
	return running_;
}

uint32_t Timer::get_ticks()
{
	return SDL_GetTicks() - start_time_;
}

Timer::~Timer() {

}