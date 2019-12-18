#include "stdafx.h"
#include "TickTock.h"

using namespace std;


CMeasureTick::CMeasureTick(bool print)
	:_bPrintEn(print),
	_timeUnit(MILLI),
	_time_unit_str TIME_STR
{}
		

bool CMeasureTick::Start(std::string obj)
{
	auto it = tick_list.find(obj);
	if (it == tick_list.end())
	{
		tick_list.insert(std::make_pair(obj,
			std::chrono::system_clock::now()
		));
		return true;
	}
	else 
	{
		// 기존에 존재하면...start timepoint를 현재 시간으로 갱신한다..
		tick_list[obj] = std::chrono::system_clock::now();
		return false;
	}
}

long long CMeasureTick::End(std::string obj)
{
	auto it = tick_list.find(obj);
	if (it != tick_list.end())
	{
		long long t = this->_measure(it->second);

		if (this->_bPrintEn)
		{
			LOG_DEBUG << it->first
				<< ":" << t
				<< _time_unit_str[_timeUnit] << "\n";
		}
		tick_list.erase(it);

		return t;
	}
	else
	{
		return -1;
	}
}

void CMeasureTick::ChangeUnit(TIME_UNIT _unit)
{
	int x = std::min(std::max(static_cast<int>(_unit), 0),
		static_cast<int>(TIME_UNIT_SIZE));
	_timeUnit = TIME_UNIT(x);
}

long long CMeasureTick::_measure(TimePoint &start)
{
	TimePoint end = chrono::system_clock::now();
	long long dt = 0;
	if (_timeUnit == SECONDS)
	{
		dt = chrono::duration_cast<chrono::seconds>(end - start).count();
	}
	else if (_timeUnit == MILLI)
	{
		dt = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	}
	else if (_timeUnit == MICRO)
	{
		dt = chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	else if (_timeUnit == NANO)
	{
		dt = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	return dt;
};

//*_ticktock = nullptr;

CMeasureTick* get_ticktock()
{
	if (_ticktock != nullptr)
	{
		return _ticktock;
	}
	
	_ticktock = new CMeasureTick();
	return _ticktock;
}
bool release_tickock()
{
	if (_ticktock)
	{
		delete _ticktock;
	}
}