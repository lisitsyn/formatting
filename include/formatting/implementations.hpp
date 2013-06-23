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
	namespace formatting_internal
	{
		class FormatTypeStringifier
		{
		public:
			virtual std::string str() const = 0;
		};

		template <typename T>
		class FormatTypeStringifierImpl : 
			public FormatTypeStringifier
		{
		public:
			FormatTypeStringifierImpl(T value) :
				value_(value) { }
			virtual std::string str() const
			{
				std::stringstream ss;
				ss << std::setprecision(9) << value_;
				return ss.str();
			}
		private:
			T value_;
		};

		template <>
		class FormatTypeStringifierImpl<const char*> :
			public FormatTypeStringifier
		{
		public:
			FormatTypeStringifierImpl(const char* value) :
				value_(value) { }
			virtual std::string str() const
			{
				return std::string(value_);
			}
		private:
			const char* value_;
		};
		
		template <>
		class FormatTypeStringifierImpl<bool> :
			public FormatTypeStringifier
		{
		public:
			FormatTypeStringifierImpl(bool value) :
				value_(value) { }
			virtual std::string str() const
			{
				return value_ ? "true" : "false";
			}
		private:
			bool value_;
		};

		template <>
		class FormatTypeStringifierImpl<std::string> :
			public FormatTypeStringifier
		{
		public:
			FormatTypeStringifierImpl(std::string value) :
				value_(value) { }
			virtual std::string str() const
			{
				return value_;
			}
		private:
			std::string value_;
		};

		template <typename T>
		class FormatTypeStringifierImpl<T*> :
			public FormatTypeStringifier
		{
		public:
			FormatTypeStringifierImpl(T* value) :
				value_(value) { }
			virtual std::string str() const
			{
				std::stringstream ss;
				ss << *value_;
				return ss.str();
			}
		private:
			T* value_;
		};
	}
}
