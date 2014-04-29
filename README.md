* This library is deprecated *

Formatting is a simple header-only C++ library to format strings with
automatic type inference. It resembles (with some simplifications though) 
the SLF4J Java library and Python's format method. The library is distributed
with almost no restrictions due to BSD 2-clause license.

The simplest example of the library usage is:

	std::string formatted = formatting::format("{} + {} is {} and that's {}", 2, 2, 2+2, true);

This makes the `formatted` string contain `2 + 2 is 4 and that's true`. Some other examples include:

	std::vector<int> v;
	v.push_back(100);
	v.push_back(200);
	std::cout << formatting::format("v={}", v); 
	// outputs `v=[100, 200]`

	for (int i=0; i<5; i++)
		std::cout << formatting::format("{} ", width[3](i, '0'));
	// outputs `000 001 002 003 004`

	double pi = 3.14159265;
	double e = 2.718281828;
	std::cout << formatting::format("{} {}", precision[3](pi), precision[5](e));
	// outputs `3.141 2.71828`

Self-explaining unit-tests can be found in the `test/` folder of the repository.

In case of any troubles with the code please don't hesitate to fire 
[an issue at github](https://github.com/lisitsyn/formatting/issues/new).

This project uses [Travis CI](https://travis-ci.org/lisitsyn/formatting).
