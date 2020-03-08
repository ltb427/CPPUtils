#ifndef __IMMUTABLE_STRING_H__
#define __IMMUTABLE_STRING_H__

namespace yukai {
	constexpr size_t buffer_size = 16;

	class ImmutableString {
	public:
		ImmutableString(const char* str);
		~ImmutableString();
		const char* getStr() const;

	private:
		union 
		{
			char* m_String_ptr;
			char m_String_Buffer[buffer_size];
		};

		const size_t m_Size;
	};
}

#endif // !__IMMUTABLE_STRING_H__

