#include <cache.hpp>
#include <iostream>
#include <memory>

namespace bira
{
struct cmeta
{
	void *data_ptr;
	time_t last_access;
	size_t rate_of_access;
};

struct cache_impl
{

};

std::shared_ptr<struct cache_impl> impl_;

cache::cache()
{
	if (impl_ == nullptr)
		impl_ = std::make_shared<struct cache_impl>();
}

int cache::get(void *p)
{
	return 0;
}

void cache::put(void *p)
{
	return;
}

}
