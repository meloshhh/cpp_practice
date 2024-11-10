#include <iostream>
#include <vector> 
#include <map>
#include <memory>
#include "classes.h"
#include "structs.h"
#include "main_functions.h"
#include "globals.h"

using std::string, std::wstring, std::vector, std::map, std::make_unique, std::unique_ptr;

int main() {
	// Data types
	{
		int v_int = 0;
		long int v_long_int = 123456;
		float v_float = 1.0f;
		double v_double = 1.0;

		char v_char = 'a';
		wchar_t v_wchar = L'a';
		char16_t v_char16 = u'a';
		char32_t v_char32 = u'a';

		bool v_bool = true;
	}



	// Static arrays
	char static_arr[255] = "Milos";
	static_arr[3] = 'p';
	// static_array = "Paunovic"; You cannot do this
	print_var(static_arr);
	static_array_param_test(static_arr, static_arr);



	// String literals
	const char* string_literal = "Milos";
	// string_literal[3] = 'p'; You cannot do this
	string_literal = "Paunovic"; // But you can do this
	print_var(string_literal);



	// Rvalue
	{
		Player player(23, string("dawn"), 1000000);
	}



	// Pointers
	int int_val = 10;
	int* pointer_to_int = nullptr;
	pointer_to_int = &int_val;
	*pointer_to_int = 15;
	print_var(*pointer_to_int);



	// Strings
	string v_string("Milos");
	wstring v_wstring(L"Milos");
	print_var(v_string.length());



	// Classes and objects
	{
		LifecycleDebug ld;
		object_param_test(ld, ld, &ld);
	}
	


	// Structs
	string username("Melosh");
	Player player = Player(5, username, 700);
	Player player2(55, "Allora", 1000);



	// Standard library
	
	// std::vector
	size_t val = 0;
	vector<int> vector_example;
	val = vector_example.capacity(); // Basically reserved memory
	val = vector_example.size(); // Number of actual elements
	vector_example.resize(5, 3); // Affects size() and capacity(), second param is value to fill with
	vector_example.reserve(10); // Affects only capacity()
	//v_vec[8] = 8; // Exception, capacity is 10, but there is no element at index 8. Yes, even with primitives
	//v_vec.insert(v_vec.begin() + 8, 8); // Exception, insertions must happen at the end. At this time, size is 5
	vector_example.insert(vector_example.end(), 666); // Inserts at the end
	vector_example.insert(vector_example.begin() + 3, 12); // Insert at index [3]
	print_vec(vector_example);
	vector_example.push_back(7); // Inserts at the end
	vector_example.pop_back(); // Delete last element
	vector_example.erase(vector_example.begin() + 3); // Delete index [3]
	vector_example.clear(); // Delete all elements

	// std::map
	map<int, User> map_example{
		{65, User("melosh", 28)},
		{67, User("jesus", 2000)}
	};
	val = map_example.max_size();
	val = map_example.size();
	map_example.insert(std::make_pair(1, User("rerna", 3))); 
	map_example.insert_or_assign(3, User("sporet", 69));
	map_example.emplace(5, User("usisivac", 13));
	map_example[7] = User("bojler", 123);
	print_map(map_example);
	map_example.erase(5);
	map_example.clear();

	// unique_ptr
	unique_ptr<User> unique_ptr_example = make_unique<User>("melosh", 28);



	// Global state
	// globals.h included with extern vars
	// vars implemented in globals.cpp
	open_project_id = 6;
	state.open_contact_id = 75;

	return 0;
}