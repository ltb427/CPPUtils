#include "immutable_string.h"
#include <string.h>
#include <stdio.h>

namespace yukai
{
	ImmutableString::ImmutableString(const char* str)
		:m_Size(strlen(str))
	{
		if (m_Size < buffer_size)
		{
			printf("by char[16]\n");
			strcpy_s(m_String_Buffer, buffer_size, str);
		}
		else
		{
			printf("-----------by new\n");
			m_String_ptr = new char[m_Size + 1];
			strcpy_s(m_String_ptr, m_Size + 1, str);
		}
	}

	ImmutableString::~ImmutableString()
	{
		if (m_Size >= buffer_size)
		{
			printf("-----------by delete\n");
			delete[] m_String_ptr;
		}
	}

	const char* ImmutableString::getStr() const
	{
		return (m_Size < buffer_size) ? m_String_Buffer : m_String_ptr;
	}
}