#include<iostream>
#include<string>

using namespace std;
#pragma once
class Player
{
private:
	static int s_id;
	void generationId() {
		s_id++;
	}
	string name;
public:
	Player();


};

