
#pragma once
#include <execution>
#include <concepts>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

namespace
{
	// ------------------------------------------------
	//
	// 
	//           yet another concepts and types
	//
	// 
	// ------------------------------------------------

	template<typename T>
	concept arithmetic_value = std::integral<T> || std::floating_point<T>;

	template<typename It>
	concept arithmetic_valued_iterator = std::input_or_output_iterator<It> && arithmetic_value<std::iter_value_t<It> >;

	template<arithmetic_value T>
	using histogram_t = std::map<T, std::size_t, std::less<T> >;

	template<arithmetic_value T>
	using contour_t = std::map<std::size_t, std::vector<T>, std::less<T> >;

	// ------------------------------------------------
	//                  
	//              
	//                 implementations
	//          
	//         
	// ------------------------------------------------
	// histogram
	template<arithmetic_valued_iterator It>
	auto histogram(It b, It e)->histogram_t<std::iter_value_t<It> >
	{
		using value_type = std::iter_value_t<It>;
		histogram_t<value_type> hist{};
		auto it = b;
		while (it != e)
		{
			++hist[*it];
			it = std::next(it);
		}
		return hist;
	}

	// contour
	template<arithmetic_value T>
	auto contour(const histogram_t<T>& hist)->contour_t<T>
	{
		contour_t<T> invhist{};
		for (const auto& elem : hist)
			invhist[elem.second].push_back(elem.first);
		return invhist;
	}
}
