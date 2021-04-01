#ifndef __CPHB_TEST_UTILS_H__
#define __CPHB_TEST_UTILS_H__
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <iterator>

void show_vector(const std::string &label, const std::vector<int> &iv);

void generate_iv_ov(std::vector<int> &iv, std::vector<int> &ov);

#endif // __CPHB_TEST_UTILS_H__
