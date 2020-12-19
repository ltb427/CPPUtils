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
class IObject
{
	public:
		virtual bool isTure()
		{
			std::cout << __func__ << std::endl;
			return true;
		}
};
//Slink方式(c++中使用方法较多)
class IDownLoadFile : public IObject
{
	public:
		virtual bool OnDownLoadFileFinshed(const char* msg)
		{
			return false;
		}
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
		DownLoadFile(IDownLoadFile* ptr)
			: m_ptr(ptr)
		{
			std::cout << __func__ << std::endl;
		}
		~DownLoadFile()
		{
			std::cout << __func__ << std::endl;
		}
		bool DownLoadFinshed(const char* msg)
		{
			if(m_ptr != nullptr)
			{
				if(m_ptr->isTure())
				{
					return m_ptr->OnDownLoadFileFinshed(msg);
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	private:
		IDownLoadFile* m_ptr;
};

class DownLoad : public IDownLoadFile
{
	public:
		DownLoad()
			: v(new int(3))
		{
			std::cout << __func__ << std::endl;
			file = new DownLoadFile(this);
		}
		~DownLoad()
		{
			delete v;
			delete file;
			std::cout << __func__ << std::endl;
		}
		void DownLoadExc()
		{
			bool flag = file->DownLoadFinshed("www.baidu.com");
			if(flag)
			{
				std::cout << "OK" << std::endl;
			}
			else
			{
				std::cout << "NOK" << std::endl;
			}
		}
		void DownLoadExc1()
		{
			bool flag = file->DownLoadFinshed("www.baidu.com");
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
		bool isTure() override
		{
			std::cout << __func__ << std::endl;
			std::cout << "DownLoad OK" << std::endl;
			return true;
		}
		//此类中所有在堆区创建的对象都要使用智能指针
		int* v;
		DownLoadFile* file;
};

int main()
{
	//type 1
	//std::cout << call_fn(add, 1, 2) << std::endl;
	//type 2
	DownLoad* load = new DownLoad();
	load->DownLoadExc();
	load->DownLoadExc1();
	delete load;
	return 0;
}