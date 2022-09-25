
#include <iostream>
#include <stdexcept>
#include "histogram.h"

// entry point
auto main()->int
{
	try
	{
		std::vector<float> data{ -0.01f, 0.0f, 2.2f, 2.2f, 2.2f, -0.01f, 0.0f, 0.0f, 2.2f, 0.0f, -0.01f, 3.05f, 3.05f };
		std::cout << "\n\tdata: ";
		for (auto& e : data)
			std::cout << e << ' ';

		auto datahist{ histogram(data.begin(), data.end()) };
		std::cout << "\n\n\tdata histogram: ";
		for (auto& e : datahist)
			std::cout << '(' << e.first << ':' << e.second << ") ";

		auto datacont{ contour(datahist) };
		std::cout << "\n\n\tdata contour: ";
		for (auto& e : datacont)
		{
			std::cout << '(' << e.first << ':';
			for (auto i{ 0 }; i < (int)e.second.size() - 1; ++i)
				std::cout << e.second.data()[i] << ',';
			std::cout << e.second.back() << ") ";
		}
		std::cout << "\n\n";

		return EXIT_SUCCESS;
	}
	catch (const std::exception& xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}
