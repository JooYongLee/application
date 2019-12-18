#ifndef TICKTOCK_H_
#define TICKTOCK_H_
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

// 로그 3rd library
#include <plog/Log.h>

typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;
#define TIME_STR		{"sec", "ms", "us","ns"}

class CMeasureTick
{
public:
	enum TIME_UNIT
	{
		SECONDS,
		MILLI,
		MICRO,
		NANO,
		TIME_UNIT_SIZE
	};

	CMeasureTick(bool print = true);

	~CMeasureTick() {}

	bool Start(std::string obj);

	long long End(std::string obj);

	void ChangeUnit(TIME_UNIT _unit);

private:
	long long _measure(TimePoint &start);


private:
	// s, ms, us, ns 단위 설정
	TIME_UNIT _timeUnit;
	// 인스턴스별로 start tiime 저장소
	std::map<std::string, TimePoint> tick_list;
	// console 출력 여부
	bool _bPrintEn;	
	// 시간 단위 string 저장소
	std::vector<std::string> _time_unit_str;
};

static CMeasureTick *_ticktock = nullptr;

CMeasureTick* get_ticktock();

bool release_tickock();

#endif // TICKTOCK_H_