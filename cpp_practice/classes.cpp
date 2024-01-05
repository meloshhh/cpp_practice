#include <iostream>
#include "classes.h"

LifecycleDebug::LifecycleDebug() : x(5) {
	std::cout << "lifecycleDebug created: " << this << std::endl;
}

LifecycleDebug::LifecycleDebug(const LifecycleDebug& other) : x(other.x) {
	std::cout << "lifecycleDebug copied: " << this << std::endl;
}

LifecycleDebug::~LifecycleDebug() {
	std::cout << "lifecycleDebug deleted: " << this << std::endl;
}

User::User()
	: username(), age(-1) {
}

User::User(std::string username, int age)
	: username(username), age(age) {
}
