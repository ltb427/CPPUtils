#include "screen.h"

namespace screen_display {

	Screen::Screen(pos ht, pos wd, pos c)
		:m_Height(ht), m_Width(wd), m_Contents(ht* wd, c)
	{

	}

	char Screen::get() const
	{
		return m_Contents[m_Cursor];
	}

	inline char Screen::get(pos ht, pos wd) const
	{
		pos row = ht * m_Width;
		return m_Contents[row + wd];
	}

	Screen& Screen::move(pos r, pos c)
	{
		// TODO: 在此处插入 return 语句
		pos row = r * m_Width;
		m_Cursor = row + c;
		return *this;
	}

	Screen& Screen::display(std::ostream& os)
	{
		// TODO: 在此处插入 return 语句
		do_display(os);
		return *this;
	}
	const Screen& Screen::display(std::ostream& os) const
	{
		// TODO: 在此处插入 return 语句
		do_display(os);
		return *this;
	}
	void Screen::do_display(std::ostream& os) const
	{
		os << m_Contents;
	}
}
