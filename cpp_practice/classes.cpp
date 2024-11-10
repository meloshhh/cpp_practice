#include <iostream>
#include "classes.h"
#include "main_functions.h"
#include "globals.h"

LifecycleDebug::LifecycleDebug() 
	: x(5) 
{
	std::cout << "LifecycleDebug created: " << this << std::endl;
}

LifecycleDebug::LifecycleDebug(const LifecycleDebug& other)
	: x(other.x) 
{
	std::cout << "LifecycleDebug copied: " << this << std::endl;
}

LifecycleDebug::~LifecycleDebug() {
	std::cout << "LifecycleDebug deleted: " << this << std::endl;
}

User::User()
	: username(), age(-1) 
{
}

User::User(std::string username, int age)
	: username(username), age(age)
{
}

std::ostream& operator<<(std::ostream& os, const User& user) {
	os << "{username: " << user.username << ", age: " << user.age << "}";
	return os;
}

State::State()
	: open_contact_id(0)
{
}
