// Declaration of template for_each function

#pragma once

// includes

#include <iostream>
#include <list>
#include <vector>
#include <future>
#include <algorithm>

// glob

namespace jinx
{	
	/*
	for_each
	*/
	template<typename Iter, typename K>
	void for_each_async(Iter itBegin, Iter itEnd, K func)
	{
		// vars

		auto startPoint = itBegin;
		auto endPoint = itEnd;
		size_t min_size = 5;
		auto curr_size = std::distance(startPoint, endPoint);

		if (curr_size <= min_size)
		{
			std::for_each(startPoint, endPoint, func);
		}
		else
		{
			auto mid = startPoint;
			std::advance(mid, curr_size / 2);
			auto ft = std::async(std::launch::async, [=]() { jinx::for_each_async(mid, endPoint, func); });
			auto remain_size = std::distance(startPoint, mid);
			std::for_each(startPoint, mid, func);
			ft.get();
		}		
		
	} // !for_each_async

	/*
	for_each
	*/
	template<typename Iter, typename K>
	void for_each_deffered(Iter itBegin, Iter itEnd, K func)
	{
		// vars

		auto startPoint = itBegin;
		auto endPoint = itEnd;
		size_t min_size = 5;
		auto curr_size = std::distance(startPoint, endPoint);

		if (curr_size <= min_size)
		{
			std::for_each(startPoint, endPoint, func);
		}
		else
		{
			auto mid = startPoint;
			std::advance(mid, curr_size / 2);
			auto ft = std::async(std::launch::deferred, [=]() { jinx::for_each_deffered(mid, endPoint, func); });
			auto remain_size = std::distance(startPoint, mid);
			std::for_each(startPoint, mid, func);
			ft.get();
		}

	} // !for_each_deffered

} // !jinx