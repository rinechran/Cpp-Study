#pragma once

#include <iostream>
#include <chrono>
#include <thread>


namespace Eun {
	template <class TIME_TYPE, /*std::chrono::milliseconds */
		class KIND_TYPE = std::chrono::steady_clock>

		class StopWatch {
		using TIMEPOINT = typename KIND_TYPE::time_point;
		public:
			StopWatch() {
				this->ok = false;
			}

			void start() {
				this->ok = false;
				this->start = KIND_TYPE::now();

			}

			void end() {
				this->ok = true;
				this->end = KIND_TYPE::now();
			}

			bool ready() {
				return this->ok;
			}
			TIME_TYPE getInterval() {
				if (!this->ok)
					throw std::logic_error("Not Ready");
				return std::chrono::duration_cast<TIME_TYPE>(this->end - this->start);
			}
			//only  std::chrono::system_clock

			time_t getTime_t() {
				TIMEPOINT obj = getInterval() + this->start;
				return std::chrono::system_clock::to_time_t(obj);
			}

		private:
			bool ok;
			TIMEPOINT start, end;
	};

}
