#ifndef TIGER_H
#define TIGER_H
#include "enemy.h"

class Tiger : public Enemy {
public:
	Tiger(int x, int y, int s, string m); //constructor taking parameters
	void move_position();
	void fire_weapon();
	void update_status();

};

#endif