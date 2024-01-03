#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <vector> 
#include <map>
#include "classes.h"

#define print_var(v) std::cout << #v << ": " << v << std::endl;

#define print_vec(v) std::cout << #v << ": " << std::endl;\
for (auto i : v) {\
	std::cout << i << std::endl;\
}\
std::cout << std::endl;

#define print_map(v) std::cout << #v << ": " << std::endl;\
for (auto i : v) {\
	std::cout << i.first << ", " << i.second << std::endl;\
}\
std::cout << std::endl;


void object_ref_test(LifecycleDebug val, LifecycleDebug& ref, LifecycleDebug* p) {
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
	ref[1] = 'a';
	// All params are the same address as the outer var and changes are visible outside
} 


int main() {
	int v_int = 0;
	float v_float = 1.0f;
	double v_double = 1.0;

	char v_char = 'a';
	wchar_t v_wchar = L'a';
	char16_t v_char16 = u'a';
	char32_t v_char32 = u'a';

	bool v_bool = true;

	int* v_pint = nullptr;
	v_pint = &v_int;
	*v_pint = 15;
	print_var(*v_pint);

	char v_arrchar[255] = "Milos\0";
	print_var(v_arrchar);
	// String operations on char array

	char* v_pchar = (char*)"Milos";
	print_var(v_pchar);

	std::string v_string = "Milos";
	std::wstring v_wstring = L"Milos";
	print_var(v_string.length());

	LifecycleDebug ld;
	object_ref_test(ld, ld, &ld);

	print_mem_usage();
	array_ref_test(v_arrchar, v_arrchar);
	//array_ref_test(v_pchar, v_pchar); // Write access exception
	print_mem_usage();

	// Test what happens with User->username memory
	// It doesn't leak memory
	{
		User v_user("melosh", 28);
	}
	print_mem_usage();

	std::vector<int> v_vec;
	v_vec.capacity(); // Basically reserved memory 
	v_vec.size(); // Number of actual elements
	v_vec.resize(5, 3); // Affects size() and capacity(), second param is value to fill with
	v_vec.reserve(10); // Affects only capacity()
	//v_vec[8] = 8; // Exception, even though capacity is large enough
	//v_vec.insert(v_vec.begin() + 8, 8); // Exception, insertions must happen at the end
	v_vec.insert(v_vec.end(), 666); // Inserts at the end
	v_vec.insert(v_vec.begin() + 3, 12); // Insert at index [3]
	print_vec(v_vec);
	v_vec.push_back(7); // Inserts at the end
	v_vec.pop_back(); // Removes last element
	v_vec.erase(v_vec.begin() + 3); // Removes index [3]
	v_vec.clear(); // Delete all elements

	std::map<int, User> v_map{
		{65, User("melosh", 28)}, // std::pair not needed
		{67, User("tuki_moj", 69)}
	};
	v_map.max_size();
	v_map.size();
	// std::pair needed. User can be constructed inline
	v_map.insert(std::make_pair(3, User("nevjena", 3)));
	v_map.insert_or_assign(6, User("sporet", 69));
	print_map(v_map);
	v_map.erase(67);
	v_map.clear();

	// Structs
	std::vector<UserStruct> users;
	std::string username1("Melosh");
	users.push_back(UserStruct(5, username1, 28));
	users.push_back(UserStruct(23, std::string("valkyra"), 3));
	print_vec(users);


	// Passing functions
	// Passing class functions? instance or static?

	return 0; 
}