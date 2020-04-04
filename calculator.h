#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

namespace Calculator 
{
	//输出结果
	class Result;
	//表达式 接受字符串的构造 do_calculator 做成一个接口 然后指定计算的类型
	class Expression;
	//工具 公有方法
	class CalculatorUtils;
	//异常处理 基类
	class CalculatorExpressionObj;
	//计算的类型 可以为普通计算、矩阵计算、汇率、体积等
	class CalculatorObj;



}


#endif // !__CALCULATOR_H__

