#pragma once
#include <iostream>
#include <chrono>
namespace ds { namespace instrumentation {

	class task_time 
	{

		public:	
			task_time(std::string s) : 
				begin_(  std::chrono::steady_clock::now() ),
				str_(s)
			{

			}

			~task_time()
			{
				auto end = std::chrono::steady_clock::now();
				std::cout << " Task " << str_ << " took " 
					<< std::chrono::duration_cast<std::chrono::microseconds>(end - begin_).count() << std::endl;
			}

		private:
			std::chrono::steady_clock::time_point begin_;
			std::string str_;

			
	};



} // instrumentation
} // ds