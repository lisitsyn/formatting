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

#ifndef FORMATTING_H_
#define FORMATTING_H_

#include <string>
#include <stdexcept>
#include <sstream>

#include <formatting/wrappers.hpp>
#include <formatting/implementations.hpp>

namespace formatting
{
	static const int WORLD_VERSION = 0;
	static const int MAJOR_VERSION = 2;
	static const int MINOR_VERSION = 0;

	/** The placeholder of formatter. */
	const std::string placeholder = "{}";

	/** A class that provides a wrapper with ability
	 * to stringify the value it is created from.
	 */
	class ValueWrapper;

	/** An error that is thrown in case of wrong number of placeholders 
	 * in the formatting string.
	 */
	class formatting_error : public std::logic_error
	{
	public:
		explicit formatting_error(const std::string& reason) : 
			std::logic_error(reason)
		{
		}
	};

	/** Internal namespace that contains implementations. */
	namespace internal
	{
		/** Implementation that is used by @ref ValueWrapper.
		 * It is able to convert the underlying value to string. */
		class ValueWrapperImplementationBase;
	}

	class ValueWrapper
	{
	public:
		template<typename T> ValueWrapper(T value) :
			implementation_(new formatting::internal::ValueWrapperImplementation<T>(value))
		{
		}
		ValueWrapper() :
			implementation_(new formatting::internal::ValueWrapperImplementation<const char*>("invalid argument"))
		{
		}
		ValueWrapper(const ValueWrapper& wrapper) :
			implementation_(wrapper.implementation_)
		{
		}
		~ValueWrapper()
		{
			delete implementation_;
		}
		inline std::string representation() const
		{
			return implementation_->representation();
		}
	private:
		formatting::internal::ValueWrapperImplementationBase* implementation_;
	};
	
	namespace internal
	{
		namespace
		{
			std::string formatImplementation(const std::string& formatter_string,
											 const ValueWrapper** handlers,
											 std::size_t n_handlers) 
			{
				std::string formatted = formatter_string;
				std::size_t placeholder_position = 0; 
				for (std::size_t i=0; i<n_handlers; i++)
				{
					placeholder_position = formatted.find(placeholder, placeholder_position);
					if (placeholder_position != std::string::npos)
					{
						const std::string representation = handlers[i]->representation();
						formatted.replace(placeholder_position,placeholder.length(),
										  representation,0,std::string::npos);
						placeholder_position += representation.length();
					}
					else
						throw formatting_error("The number of placeholders doesn't match the number of provided arguments");
				}
				return formatted;
			}
		}
	}

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
	 * @param fmt the formatting string that contains one {} placeholder.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a) 
	{
		const ValueWrapper* handlers[] = {&a};
		return formatting::internal::formatImplementation(fmt, handlers, 1);
	}

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
	 * @param fmt the formatting string that contains 2 {} placeholders.
	 * @param a any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @param b any variable which type has the stream insertion operator
	 *        (operator<<) implemented. 
	 * @return new string with provided parameters put instead
	 *         of placeholders to the provided formatting string.
	 * @throw formatting_error in case the number of placeholders doesn't match
	 *        the number of provided parameters
	 */
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b)
	{
		const ValueWrapper* handlers[] = {&a, &b};
		return formatting::internal::formatImplementation(fmt, handlers, 2);
	}

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
	 * @param fmt the formatting string that contains 3 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b,
			const ValueWrapper& c)
	{
		const ValueWrapper* handlers[] = {&a, &b, &c};
		return formatting::internal::formatImplementation(fmt, handlers, 3);
	}

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
	 * @param fmt the formatting string that contains 4 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b,
			const ValueWrapper& c, const ValueWrapper& d)
	{
		const ValueWrapper* handlers[] = {&a, &b, &c, &d};
		return formatting::internal::formatImplementation(fmt, handlers, 4);
	}

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
	 * @param fmt the formatting string that contains 5 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b, 
			const ValueWrapper& c, const ValueWrapper& d,
			const ValueWrapper& e) 
	{
		const ValueWrapper* handlers[] = {&a, &b, &c, &d, &e};
		return formatting::internal::formatImplementation(fmt, handlers, 5);
	}

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
	 * @param fmt the formatting string that contains 6 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b, 
			const ValueWrapper& c, const ValueWrapper& d,
			const ValueWrapper& e, const ValueWrapper& f) 
	{
		const ValueWrapper* handlers[] = {&a, &b, &c, &d, &e, &f};
		return formatting::internal::formatImplementation(fmt, handlers, 6);
	}

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
	 * @param fmt the formatting string that contains 7 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b, 
			const ValueWrapper& c, const ValueWrapper& d,
			const ValueWrapper& e, const ValueWrapper& f,
			const ValueWrapper& g) 
	{
		const ValueWrapper* handlers[] = {&a, &b, &c, &d, &e, &f, &g};
		return formatting::internal::formatImplementation(fmt, handlers, 7);
	}

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
	 * @param fmt the formatting string that contains 8 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b, 
			const ValueWrapper& c, const ValueWrapper& d,
			const ValueWrapper& e, const ValueWrapper& f,
			const ValueWrapper& g, const ValueWrapper& h) 
	{
		const ValueWrapper* handlers[] = {&a, &b, &c, &d, &e, &f, &g, &h};
		return formatting::internal::formatImplementation(fmt, handlers, 8);
	}

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
	 * @param fmt the formatting string that contains 9 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b, 
			const ValueWrapper& c, const ValueWrapper& d,
			const ValueWrapper& e, const ValueWrapper& f,
			const ValueWrapper& g, const ValueWrapper& h,
			const ValueWrapper& i) 
	{
		const ValueWrapper* handlers[] = {&a, &b, &c, &d, &e, &f, &g, &h, &i};
		return formatting::internal::formatImplementation(fmt, handlers, 9);
	}

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
	 * @param fmt the formatting string that contains 10 {} placeholders.
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
	inline std::string format(const std::string& fmt, 
			const ValueWrapper& a, const ValueWrapper& b, 
			const ValueWrapper& c, const ValueWrapper& d,
			const ValueWrapper& e, const ValueWrapper& f,
			const ValueWrapper& g, const ValueWrapper& h,
			const ValueWrapper& i, const ValueWrapper& j) 
	{
		const ValueWrapper* handlers[] = {&a, &b, &c, &d, &e, &f, &g, &h, &i, &j};
		return formatting::internal::formatImplementation(fmt, handlers, 10);
	}

}
#endif
