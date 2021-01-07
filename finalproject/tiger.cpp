#include "tiger.h"
#include <stdlib.h>
#include <ctime>

//constructor passing arguments to base class 
Tiger::Tiger(int x, int y, int s, string m) : Enemy(x, y, s, m) {};

void Tiger::move_position() 
{
	cout << "Tiger move to: ";

	if (get_status() > 0) // make sure tiger is not dead
	{
		if ((get_movement() == "left" && get_x_position() - 6) < 0) //condition to make sure tiger not outside coordinates
			set_movement("right");

		if ((get_movement() == "right" && get_x_position() + 6) > 800)
			set_movement("left");

		if (get_movement() == "left")
			set_x_position(get_x_position() - 6); //set new coordinates

		if (get_movement() == "right")
			set_x_position(get_x_position() + 6);

		cout << "(" << get_x_position() << "," << get_y_position() << ") ";

	}
	else
		cout << "Tiger is dead...";

}



void Tiger::fire_weapon()
{
	const int num_attacks = 4;
	string attack_array[num_attacks] = { "Bite Leg... ", "Slash Chest... ", "Bite Neck... ", "Bite Arm... " };

	srand((unsigned)time(0)); //random number generator to determine attack type
	int type_of_attack = rand() % 4;

	cout << "Tiger attack: ";

	if (get_status() > 0) //make sure tiger is alive to attack
		cout << attack_array[type_of_attack];

	else
		cout << "No weapon fired, tiger is dead.";
}

void Tiger::update_status()
{
	cout << "Tiger update status: ";

	if (get_status() > 0) {
		set_status(get_status() - 1);
		cout << "Tiger has been hit. (Roar...) " << "status points " << get_status();
	}

	else
		cout << "Tiger is dead...";

}