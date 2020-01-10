
#ifndef __Timer_h__
#define __Timer_h__

#include <cstdint>

class Timer
{
	private:
		uint32_t start_time_ = 0;
		bool running_ = false;
	public:
		Timer();

		void start();
		void stop();
		void reset();
		bool is_running();

		uint32_t get_ticks();

		~Timer();
};

#endif