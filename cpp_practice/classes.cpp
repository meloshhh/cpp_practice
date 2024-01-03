#include <iostream>
#include "classes.h"

LifecycleDebug::LifecycleDebug() {
	x = 5;
	std::cout << "lifecycle debug created" << std::endl;
}

LifecycleDebug::LifecycleDebug(LifecycleDebug& other) {
	x = other.x;
	std::cout << "lifecycle debug copied" << std::endl;
}

LifecycleDebug::~LifecycleDebug() {
	std::cout << "lifecycle debug deleted" << std::endl;
}




User::User() : username(nullptr), age(-1) {
}

User::User(std::string _username, int _age) : username(_username), age(_age) {
}




UserStruct::UserStruct(int id, std::string& username, int age) : id(id), username(username), age(age) {
}

UserStruct::UserStruct(int id, std::string&& username, int age) : id(id), username(username), age(age) {
}
