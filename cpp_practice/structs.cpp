#include <iostream>
#include "structs.h"

Player::Player(int id, const std::string& username, int points) 
	: id(id), username(username), points(points) 
{
}

Player::Player(int id, std::string&& username, int points)
	: id(id), username(username), points(points) 
{
}