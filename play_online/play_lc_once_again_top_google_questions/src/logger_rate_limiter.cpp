#include <logger_rate_limiter.hpp>

namespace lc
{
bool logger_rate_limiter::shouldPrintMessage(int ts, std::string msg)
{
	int allowed_ts = allowed_time(msg);
	if (ts < allowed_ts)
		return false;
	update_allowed_time(msg, ts);
	return true;
}
}

