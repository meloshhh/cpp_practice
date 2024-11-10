#pragma once

#define print_var(v) std::cout << #v << ": " << v << std::endl

#define print_vec(v) std::cout << #v << ": " << std::endl;\
for (auto i : v) {\
	std::cout << i << std::endl;\
}\
std::cout << std::endl

#define print_map(v) std::cout << #v << ": " << std::endl;\
for (auto i : v) {\
	std::cout << i.first << ", " << i.second << std::endl;\
}\
std::cout << std::endl

void object_param_test(LifecycleDebug val, const LifecycleDebug & ref, const LifecycleDebug* p);

void print_mem_usage();

void static_array_param_test(char val[], char* ref);