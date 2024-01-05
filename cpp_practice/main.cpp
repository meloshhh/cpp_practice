#include <iostream>
#include <vector> 
#include <map>
#include <memory>
#include "classes.h"
#include "structs.h"
#include "main_functions.h"

int main() {
	// Data types
	int v_int = 0;
	long int v_long_int = 123456;
	float v_float = 1.0f;
	double v_double = 1.0;

	char v_char = 'a';
	wchar_t v_wchar = L'a';
	char16_t v_char16 = u'a';
	char32_t v_char32 = u'a';

	bool v_bool = true;

	// Static arrays
	char static_array[255] = "Milos";
	static_array[3] = 'p';
	// static_array = "Paunovic"; You cannot do this
	print_var(static_array);
	print_mem_usage();
	array_ref_test(static_array, static_array);
	print_mem_usage(); // Memory usage is higher after above function for some reason
	print_var(static_array);

	// String literals
	char* string_literal = (char*)"Milos";
	// string_literal[3] = 'p'; You cannot do this
	string_literal = (char*)"Paunovic"; // But you can do this
	print_var(string_literal);



	// Rvalue
	Player player2(23, std::string("valkyra"), 1000000); // &&



	// Pointers
	int* pointer_to_int = nullptr;
	pointer_to_int = &v_int;
	*pointer_to_int = 15;
	print_var(*pointer_to_int);



	// Strings
	std::string v_string("Milos");
	std::wstring v_wstring(L"Milos");
	print_var(v_string.length());


	// Classes
	{
		LifecycleDebug ld;
		object_ref_test(ld, ld, &ld);
	}
	



	// Structs
	std::string username("Melosh");
	Player player(5, username, 700); // &



	// Standard library
	
	// std::vector
	std::vector<int> vector_example;
	vector_example.capacity(); // Basically reserved memory
	vector_example.size(); // Number of actual elements
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

	// std::vector ownership
	LifecycleDebug ld;
	LifecycleDebug* ld2 = new LifecycleDebug();
	std::vector<LifecycleDebug>* lifecycle_debugs = new std::vector<LifecycleDebug>();
	lifecycle_debugs->reserve(5);
	lifecycle_debugs->push_back(LifecycleDebug());
	lifecycle_debugs->push_back(ld);
	lifecycle_debugs->push_back(*ld2);
	// Every time you add an element to a vector, it creates a copy, therefore if you want the vector
	// to have the only copy of the data, you can immediately dispose of the original object
	delete lifecycle_debugs;
	delete ld2; // Must delete the original

	// std::map
	std::map<int, User> map_example{
		{65, User("melosh", 28)}, // std::pair not needed
		{67, User("lorem ipsum", 2000)}
	};
	map_example.max_size();
	map_example.size();
	map_example.insert(std::make_pair(3, User("nevjena", 3))); // std::pair needed. User can be constructed inline
	map_example.insert_or_assign(6, User("sporet", 69)); // pair not needed
	print_map(map_example);
	map_example.erase(67);
	map_example.clear();

	// std::unique_ptr
	std::unique_ptr<User> unique_ptr_example = std::make_unique<User>("melosh", 28);


	return 0;
}