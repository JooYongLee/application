#ifndef _EXMPLAE_PLOG_H
#define _EXMPLAE_PLOG_H


//https://github.com/SergiusTheBest/plog
#include <plog/Log.h>
#include <plog/Formatters/FuncMessageFormatter.h>
#include <plog/Appenders/ConsoleAppender.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <numeric>
class Sun
{
public:
	Sun(int x = 0)
		:buff(nullptr),
		size(x)
	{
		if (x > 0)
		{
			buff = new double[x];
			std::iota(buff, buff + x, 0);
		}
		std::cout << "생성자\n";
	}
	~Sun()
	{
		this->release();
		std::cout << "파괴자\n";
	}
	void release()
	{
		if (buff)
		{
			delete[]buff;
			buff = nullptr;
			size = 0;
		}
	}
	std::string name;
	double *buff;
	int size;
	friend plog::Record& operator<<(plog::Record &out, Sun &rhs)
	{
		if (rhs.buff)
		{
			for (int k = 0; k < rhs.size; k++)
			{
				out << rhs.buff[k];
				if (k != rhs.size - 1)
				{
					out << ",";
				}
				else
				{
					out << "\n";
				}
			}
		}

		return out;
	}
};

Sun GetSun()
{
	Sun a(10);
	a.name = "sdfsdfsdf";
	return a;
}

void example_plog()
{
	//static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;

	static plog::RollingFileAppender<plog::TxtFormatter> fileAppender("MultiAppender.txt", 1000000, 3); // Create the 1st appender.
	static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender; // Create the 2nd appender.


	static plog::ColorConsoleAppender<plog::TxtFormatter> colorConsoloAppender;
	plog::init(plog::fatal, &fileAppender);
	//.addAppender(&consoleAppender);
	//colorConsoloAppender.
	//get_ticktock()->Start();

	plog::get()->setMaxSeverity(plog::debug);
	//plog::get()->addAppender(&consoleAppender);
	plog::get()->addAppender(&colorConsoloAppender);
	// Step3: write log messages using a special macro. 
	// There are several log macros, use the macro you liked the most.

	LOGD << "Hello log!"; // short macro
	LOG_DEBUG << "Hello log!"; // long macro
	LOG(plog::fatal) << "Hello log!"; // function-style macro
	Sun a = GetSun();
	LOG(plog::fatal) << a << a;
	LOG_INFO << "info입니다만??";
	LOG(plog::error) << "erro입니다";
	LOG(plog::info) << "info입니다";
	LOG(plog::warning) << "warning입니다";

	// Log severity levels are printed in different colors.
	PLOG_VERBOSE << "This is a VERBOSE message";
	PLOG_DEBUG << "This is a DEBUG message";
	PLOG_INFO << "This is an INFO message";
	PLOG_WARNING << "This is a WARNING message";
	PLOG_ERROR << "This is an ERROR message";
	PLOG_FATAL << "This is a FATAL message";
}

#endif // _EXMPLAE_PLOG_H