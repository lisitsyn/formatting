#include <stdio.h>
#include <sstream>
#include <ctime>
#include <formatting/formatting.hpp>

struct sprintf_impl
{
	void operator()()
	{
		char buffer[256];
		volatile int a = 3;
		volatile char b = 'b';
		volatile const char* c = "test string";
		sprintf(buffer, "hello %d hello %c hello %s hello", a, b, c);
	}
};

struct streams_impl
{
	void operator()()
	{
		volatile int a = 3;
		volatile char b = 'b';
		volatile const char* c = "test string";
		std::stringstream ss;
		ss << "hello " << a << " hello " << b << " hello " << c;
		volatile std::string s = ss.str();
	}
};

struct formatting_impl
{
	void operator()()
	{
		int a = 3;
		char b = 'b';
		const char* c = "test string";
		std::string formatted = 
			formatting::format("hello {} hello {} hello {} hello", a, b, c);
	}
};

template <class T>
clock_t benchmark(T impl, int n_times)
{
	clock_t start = clock();
	for (int i=0; i<n_times; i++)
		impl();
	clock_t end = clock();
	return end-start;
}

int main() 
{
	const int repeats = 100000;
	clock_t sprintf_time = benchmark(sprintf_impl(), repeats);
	printf("Sprintf takes %f\n", double(sprintf_time)/CLOCKS_PER_SEC);
	clock_t streams_time = benchmark(streams_impl(), repeats);
	printf("Streams takes %f\n", double(streams_time)/CLOCKS_PER_SEC);
	clock_t formatting_time = benchmark(formatting_impl(), repeats);
	printf("Formatting takes %f\n", double(formatting_time)/CLOCKS_PER_SEC);
}
