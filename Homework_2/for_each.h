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
	for_each overload for std::list<T>
	*/
	template<typename K>
	void for_each(typename std::list<K>::iterator itBegin, typename std::list<K>::iterator itEnd, void (&func)(K input))
	{		
		// vars

		typename std::list<K>::iterator startPoint = itBegin;
		typename std::list<K>::iterator endPoint = itEnd;
		size_t min_size = 5;
		auto curr_size = std::distance(startPoint, endPoint);

		if (curr_size <= min_size)
		{
			std::for_each(startPoint, endPoint, func);
		}
		else
		{
			typename std::list<K>::iterator mid = startPoint;
			std::advance(mid, curr_size / 2);
			auto ft = std::async(std::launch::deferred, [=]() { jinx::for_each(mid, endPoint, func); });
			auto remain_size = std::distance(startPoint, mid);
			std::for_each(startPoint, mid, func);
			ft.get();
		}

		/* OLD VERSION
		if (curr_size <= min_size)
		{
			for (int i = 0; i < curr_size; ++i)
			{
				func(*startPoint);
				++startPoint;
			}
		}
		else
		{
			typename std::list<K>::iterator mid = startPoint;
			std::advance(mid, curr_size / 2);
			// auto ft = std::async([=]() { jinx::for_each(mid, endPoint, func); });
			auto ft = std::async(std::launch::deferred, [=]() { jinx::for_each(mid, endPoint, func); });

			auto remain_size = std::distance(startPoint, mid);

			for (int i = 0; i < remain_size; ++i)
			{
				func(*startPoint);
				++startPoint;
			}

			ft.get();
		}
		*/
	} // !for_each for std::list

	/*
	for_each overload for std::vector<T>
	*/
	template<typename K>
	void for_each(typename std::vector<K>::iterator itBegin, typename std::vector<K>::iterator itEnd, void (func)(K input))
	{
		// vars

		typename std::vector<K>::iterator startPoint = itBegin;
		typename std::vector<K>::iterator endPoint = itEnd;
		size_t min_size = 5;
		auto curr_size = std::distance(startPoint, endPoint);

		if (curr_size <= min_size)
		{
			std::for_each(startPoint, endPoint, func);
		}
		else
		{
			typename std::vector<K>::iterator mid = startPoint;
			std::advance(mid, curr_size / 2);
			auto ft = std::async(std::launch::deferred, [=]() { jinx::for_each(mid, endPoint, func); });
			auto remain_size = std::distance(startPoint, mid);
			std::for_each(startPoint, mid, func);
			ft.get();
		}

		/* OLD VERSION
		if (curr_size <= min_size)
		{
			for (int i = 0; i < curr_size; ++i)
			{
				func(*startPoint);
				++startPoint;
			}
		}
		else
		{
			typename std::vector<K>::iterator mid = startPoint;
			std::advance(mid, curr_size / 2);
			// auto ft = std::async([=]() { jinx::for_each(mid, endPoint, func); });
			auto ft = std::async(std::launch::deferred, [=]() { jinx::for_each(mid, endPoint, func); });

			auto remain_size = std::distance(startPoint, mid);
						
			for (int i = 0; i < remain_size; ++i)
			{
				func(*startPoint);
				++startPoint;
			}

			ft.get();
		}
		*/
		
	} // !for_each for std::vector

} // !jinx