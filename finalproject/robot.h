#ifndef ROBOT_H
#define ROBOT_H
#include "enemy.h"

class Robot : public Enemy {
private:
	int num_of_lasers; //robot has extra member variable to hold number of lasers in its weapon

public:
	Robot(int x, int y, int s, string m, int l);
	void move_position();
	void fire_weapon();
	void update_status();

};

#endif
