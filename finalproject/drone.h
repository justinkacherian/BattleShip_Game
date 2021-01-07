#ifndef DRONE_H
#define DRONE
#include "enemy.h"

class Drone : public Enemy {

private:
	int num_of_bombs; //drone has extra member variable to hold ammo/bomb count

public:
	Drone(int x, int y, int s, string m, int b); //construcor takes in additional parameter for bomb count
	void move_position();
	void fire_weapon();
	void update_status();

};

#endif