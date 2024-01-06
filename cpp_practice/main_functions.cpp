#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include "classes.h"

void object_ref_test(LifecycleDebug val, const LifecycleDebug& ref, LifecycleDebug const* p) {
	// Copying is done for first parameter
}

void print_mem_usage() {
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T mem_usage = pmc.WorkingSetSize;
	std::cout << "Mem usage: " << mem_usage << std::endl;
}

void array_ref_test(char val[], char* ref) {
	print_mem_usage();
	val[0] = 'a';
	ref = (char*)"array_ref_test"; // Doesn't work
	// All params are the same address as the outer var and changes are visible outside
}