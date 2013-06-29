/** A simple formatter that uses simple "{}" placeholder.
 * Resembles SLF4J and Python format.
 *
 * Copyright (c) 2013, Sergey Lisitsyn <lisitsyn.s.o@gmail.com>
 * All rights reserved.
 *
 * Distributed under the BSD 2-clause license:
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, 
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY 
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <string>
#include <stdexcept>
#include <sstream>

#include <formatting/wrappers.hpp>
#include <formatting/implementations.hpp>

namespace formatting
{
	static const int WORLD_VERSION = 0;
	static const int MAJOR_VERSION = 1;
	static const int MINOR_VERSION = 0;

	/** The placeholder of formatter. */
	const std::string placeholder = "{}";

	/** A class that provides a wrapper with ability
	 * to stringify the value it is created from.
	 */
	class FormatTypeHandler;

	/** An error that is thrown in case of wrong number of placeholders 
	 * in the formatting string.
	 */
	class formatting_error : public std::logic_error
	{
	public:
		explicit formatting_error(const std::string& what) : 
			std::logic_error(what)
		{
		}
	};

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param d any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param d any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param e any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param d any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param e any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param f any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param d any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param e any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param f any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param g any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param d any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param e any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param f any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param g any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param h any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g, const FormatTypeHandler h);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param d any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param e any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param f any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param g any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param h any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param i any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g, const FormatTypeHandler h,
			const FormatTypeHandler i);

	/** Constructs a string using the provided formatting string and
	 * arguments. Essentially, replaces all placeholders ("{}") in the 
	 * string with the corresponding string representations 
	 * of provided arguments (in the same order).
	 *
	 * This function performs substitution of one variable.
	 *
	 * Doesn't change the formatting string.
	 * Uses no shared state thus supposed to be thread-safe.
	 *
	 * @param fmt the formatting string.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param c any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param d any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param e any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param f any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param g any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param h any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param i any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param j any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g, const FormatTypeHandler h,
			const FormatTypeHandler i, const FormatTypeHandler j);

	/** Internal namespace that contains implementations. */
	namespace formatting_internal
	{
		/** Stringifier that is used by @ref FormatTypeHandler.
		 * It is able to convert the underlying value to string. */
		class FormatTypeStringifier;

		/** Generic implementation of formatting. */
		std::string formatImpl(const std::string& fmt, const FormatTypeHandler** handlers, std::size_t n_handlers);
	}

	class FormatTypeHandler
	{
	public:
		template<typename T> FormatTypeHandler(T v);
		FormatTypeHandler();
		FormatTypeHandler(const FormatTypeHandler& fth);
		~FormatTypeHandler();
		std::string str() const;
	private:
		formatting_internal::FormatTypeStringifier* impl_;
	};

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a) 
	{
		const FormatTypeHandler* handlers[] = {&a};
		return formatting_internal::formatImpl(fmt, handlers, 1);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b)
	{
		const FormatTypeHandler* handlers[] = {&a, &b};
		return formatting_internal::formatImpl(fmt, handlers, 2);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b,
			const FormatTypeHandler c)
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c};
		return formatting_internal::formatImpl(fmt, handlers, 3);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b,
			const FormatTypeHandler c, const FormatTypeHandler d)
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c, &d};
		return formatting_internal::formatImpl(fmt, handlers, 4);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e) 
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c, &d, &e};
		return formatting_internal::formatImpl(fmt, handlers, 5);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f) 
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c, &d, &e, &f};
		return formatting_internal::formatImpl(fmt, handlers, 6);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g) 
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c, &d, &e, &f, &g};
		return formatting_internal::formatImpl(fmt, handlers, 7);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g, const FormatTypeHandler h) 
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c, &d, &e, &f, &g, &h};
		return formatting_internal::formatImpl(fmt, handlers, 8);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g, const FormatTypeHandler h,
			const FormatTypeHandler i) 
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c, &d, &e, &f, &g, &h, &i};
		return formatting_internal::formatImpl(fmt, handlers, 9);
	}

	std::string format(const std::string& fmt, 
			const FormatTypeHandler a, const FormatTypeHandler b, 
			const FormatTypeHandler c, const FormatTypeHandler d,
			const FormatTypeHandler e, const FormatTypeHandler f,
			const FormatTypeHandler g, const FormatTypeHandler h,
			const FormatTypeHandler i, const FormatTypeHandler j) 
	{
		const FormatTypeHandler* handlers[] = {&a, &b, &c, &d, &e, &f, &g, &h, &i, &j};
		return formatting_internal::formatImpl(fmt, handlers, 10);
	}

	namespace formatting_internal
	{
		std::string formatImpl(const std::string& fmt, const FormatTypeHandler** handlers, std::size_t n_handlers) 
		{
			std::string formatted = fmt;
			std::size_t placeholder_position = 0; 
			for (std::size_t i=0; i<n_handlers; i++)
			{
				placeholder_position = formatted.find(placeholder, placeholder_position);
				if (placeholder_position != std::string::npos)
				{
					const std::string str = handlers[i]->str();
					formatted.replace(placeholder_position,placeholder.length(),str,0,std::string::npos);
					placeholder_position += str.length();
				}
				else
					throw formatting_error("The number of placeholders doesn't match the number of provided arguments");
			}
			return formatted;
		}
	}

	template<typename T>
	FormatTypeHandler::FormatTypeHandler(T v) : 
		impl_(new formatting_internal::FormatTypeStringifierImpl<T>(v))
	{
	}

	FormatTypeHandler::FormatTypeHandler() :
		impl_(new formatting_internal::FormatTypeStringifierImpl<const char*>("invalid argument"))
	{
	}

	FormatTypeHandler::FormatTypeHandler(const FormatTypeHandler& fth) : 
		impl_(fth.impl_)
	{
	}

	FormatTypeHandler::~FormatTypeHandler() 
	{
		delete impl_;
	}

	std::string FormatTypeHandler::str() const 
	{
		return impl_->str();
	}
}
