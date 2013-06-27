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

namespace formatting
{

namespace wrappers 
{
	template <typename T>
	struct HexWrapper
	{
		explicit HexWrapper(T value) : value_(value) { }
		T value_;

		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, const HexWrapper<U>& h);
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& out, const HexWrapper<T>& h)
	{
		out << "0x" << std::hex << std::uppercase << h.value_;
	}

	template <typename T>
	struct OctWrapper
	{
		explicit OctWrapper(T value) : value_(value) { }
		T value_;

		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, const HexWrapper<U>& h);
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& out, const OctWrapper<T>& h)
	{
		out << "0" << std::oct << std::uppercase << h.value_;
	}

}

/** Returns a wrapper that makes the provided 
 * value represented as hex when formatting.
 *
 * E.g. formatting::hex(10) => '0xA'
 *
 * @param value a numerical value to be presented as hex
 */
template<typename T>
wrappers::HexWrapper<T> hex(T value) 
{
	return wrappers::HexWrapper<T>(value);
}

/** Returns a wrapper that makes the provided
 * value represented as oct when formatting.
 *
 * E.g formatting::oct(9) => '011'
 *
 * @param value a numerical value to be presented as oct
 */
template<typename T>
wrappers::OctWrapper<T> oct(T value)
{
	return wrappers::OctWrapper<T>(value);
}

/** Returns a wrapper that makes the provided
 * pointer represented as hex value of a pointer.
 *
 * @param value a pointer to be represented as hex
 */
template<typename T>
wrappers::HexWrapper<T> raw(T* value) 
{
	return wrappers::HexWrapper<T>(reinterpret_cast<T>(value));
}

}
