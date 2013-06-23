Formatting is a simple header-only C++ library to format strings with
automatic type inference. It resembles (with some simplifications though) 
the SLF4J Java library and Python's format method.

The simplest example of usage is:

	std::string formatted = formatting::format("{} + {} is {} and that's {}", 2, 2, 2+2, true);

This makes the `formatted` string contain `2 + 2 is 4 and that's true`.

For other examples please check the unit-tests in the `test/` folder of the repository.

To use the library in your code just copy the headers from the `include/` folder
and include them. There is an attempt to avoid using compiler-specific in the code 
and it is supposed to be portable enough. In case of any troubles with the code 
please don't hesitate to fire 
[an issue at github](https://github.com/lisitsyn/formatting/issues/new).

This project uses [Travis CI](https://travis-ci.org/lisitsyn/formatting).
