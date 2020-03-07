/*
screen类表示一个窗口，每个Screen对象包含一个用于保存Screen内容的string 
成员和三个string::size_type成员，分别表示光标的位置和屏幕的宽高。
*/
#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>

namespace screen_display {
	
	class Screen
	{
	public:
		using pos = std::string::size_type;
		Screen() = default;
		Screen(pos ht, pos wd, pos c = ' ');
		char get() const;
		inline char get(pos ht, pos wd) const;
		Screen& move(pos r, pos c);
		Screen& set(char);
		Screen& set(pos, pos, char);
		Screen& display(std::ostream& os);
		const Screen& display(std::ostream& os) const;

	private:
		pos m_Cursor = 0;
		pos m_Height = 0;
		pos m_Width = 0;
		std::string m_Contents;
		//可变数据成员 为了时const成员函数也可访问修改其值而设定
		//例如inline char get(pos ht, pos wd) const
		mutable size_t m_Access_Ctr;
		void do_display(std::ostream& os) const;
	};

	//注意inline的使用
	inline Screen& Screen::set(char c)
	{
		// TODO: 在此处插入 return 语句
		m_Contents[m_Cursor] = c;
		return *this;
	}

	inline Screen& Screen::set(pos r, pos col, char c)
	{
		// TODO: 在此处插入 return 语句
		m_Contents[r * m_Width + col] = c;
		return *this;
	}

}


#endif // !__SCREEN_H__
