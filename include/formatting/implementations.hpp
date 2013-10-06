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

#ifndef FORMATTING_IMPLEMENTATIONS_H_
#define FORMATTING_IMPLEMENTATIONS_H_

#include <vector>

namespace formatting
{
	namespace internal
	{
		namespace
		{

			template <typename T, bool special> 
			struct GenericIfSpecial
			{
			};
			template <typename T> 
			struct GenericIfSpecial<T,true>
			{
				FMTG_INLINE std::string operator()(const T& value) const
				{
#ifdef FMTG_USE_CXX11
					return std::to_string(value);
#else
					std::stringstream string_stream;
					string_stream << value;
					return string_stream.str();
#endif
				}
			};
			template <typename T> 
			struct GenericIfSpecial<T,false>
			{
				FMTG_INLINE std::string operator()(const T& value) const
				{
					std::stringstream string_stream;
					string_stream << value;
					return string_stream.str();
				}
			};

			template <typename T, typename U>
			struct is_same
			{
				enum { value = 0 };
			};
			template <typename T>
			struct is_same<T,T>
			{
				enum { value = 1 };
			};
			template <typename T>
			struct is_char
			{
				enum { value = is_same<char, T>::value || 
				               is_same<signed char, T>::value || 
				               is_same<unsigned char, T>::value };
			};

			template <typename T>
			struct dispatchImplementation
			{
				FMTG_INLINE std::string operator()(const T& value) const 
				{
					return GenericIfSpecial<T,
						   std::numeric_limits<T>::is_specialized && 
						   !is_char<T>::value 
						>()(value);
				}
			};
			template <typename T>
			struct dispatchImplementation< std::vector<T> >
			{
				FMTG_INLINE std::string operator()(const std::vector<T>& vector_) const 
				{
					std::stringstream string_stream;
					string_stream << "[";
					for (size_t i=0; i<vector_.size()-1; i++)
						string_stream << vector_[i] << ", ";
					string_stream << vector_[vector_.size()-1];
					string_stream << "]";
					return string_stream.str();
				}
			};
			template <typename T>
			struct dispatchImplementation<T*>
			{
				FMTG_INLINE std::string operator()(T* value) const 
				{
					std::stringstream string_stream;
					string_stream << *value;
					return string_stream.str();
				}
			};
			template <>
			struct dispatchImplementation<std::string>
			{
				FMTG_INLINE std::string operator()(const std::string& value) const 
				{
					return value;
				}
			};
			template <>
			struct dispatchImplementation<const char*>
			{
				FMTG_INLINE std::string operator()(const char* const value) const 
				{
					return value;
				}
			};
			template <>
			struct dispatchImplementation<bool>
			{
				FMTG_INLINE std::string operator()(bool value) const 
				{
					return value ? "true" : "false";
				}
			};
		}

		class ValueWrapperImplementationBase
		{
		public:
			virtual ~ValueWrapperImplementationBase() { }
			virtual std::string representation() const = 0;
		};

		template <typename T>
		class ValueWrapperImplementation : 
			public ValueWrapperImplementationBase
		{
		public:
			ValueWrapperImplementation(const T& value) :
				value_(value) { }
			FMTG_INLINE virtual std::string representation() const 
			{
				return dispatchImplementation<T>()(value_);
			}
		private:
			const T value_;
		};
	}
}
#endif
