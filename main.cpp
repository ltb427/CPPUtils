#include <iostream>
#include <memory>

//使用函数指针
typedef int(*pfc)(int,int);

int add(int x, int y)
{
	return x+y;
}

int call_fn(pfc ptr, int x, int y)
{
	return ptr(x,y);
}

//Slink方式(c++中使用方法较多)
class IDownLoadFile
{
	public:
		virtual bool OnDownLoadFileFinshed(const char* msg) = 0;
		IDownLoadFile()
		{
			std::cout << __func__ << std::endl;
		}
		virtual ~IDownLoadFile()
		{
			std::cout << __func__ << std::endl;
		}
};

class DownLoadFile
{
	public:
		DownLoadFile(std::shared_ptr<IDownLoadFile> ptr)
			: m_ptr(ptr)
		{
			std::cout << __func__ << std::endl;
			std::cout << "_count:" << m_ptr.use_count() << std::endl;
		}
		~DownLoadFile()
		{
			std::cout << "count:" << m_ptr.use_count() << std::endl;
			std::cout << __func__ << std::endl;
		}
		bool DownLoadFinshed(const char* msg)
		{
			if(m_ptr != nullptr)
			{
				return m_ptr->OnDownLoadFileFinshed(msg);
			}
			else
			{
				return false;
			}
		}
	private:
		std::shared_ptr<IDownLoadFile> m_ptr;
};

class DownLoad : public IDownLoadFile
{
	public:
		DownLoad()
			: v(new int(3))
		{
			std::cout << __func__ << std::endl;
		}
		~DownLoad()
		{
			std::cout << __func__ << std::endl;
		}
		void DownLoadExc()
		{
			DownLoadFile file(std::make_shared<DownLoad>(*this));
			bool flag = file.DownLoadFinshed("www.baidu.com");
			if(flag)
			{
				std::cout << "OK" << std::endl;
			}
			else
			{
				std::cout << "NOK" << std::endl;
			}
		}
		bool OnDownLoadFileFinshed(const char* msg) override
		{
			std::cout << "DownLoad Finshed With " << msg << std::endl;
			return true;
		}
		//此类中所有在堆区创建的对象都要使用智能指针
		std::shared_ptr<int> v;
};

int main()
{
	//type 1
	//std::cout << call_fn(add, 1, 2) << std::endl;
	//type 2
	DownLoad* load = new DownLoad();
	load->DownLoadExc();
	delete load;
	return 0;
}