#include "drone.h"

//constructor passing arguments to base class constructor
Drone::Drone(int x, int y, int s, string m, int b) : Enemy(x, y, s, m) 
{
	num_of_bombs = b;
};

void Drone::move_position()
{
	cout << "Drone move to: ";

	if (get_status() > 0)
	{
		int speed = (rand() % 30) + 1; // random speed between 15 and 30

		if ((get_movement() == "left" && get_x_position() - speed) < 0) //make sure drone within coordinates
			set_movement("right");

		if ((get_movement() == "right" && get_x_position() + speed) > 800)
			set_movement("left");

		if (get_movement() == "left")
			set_x_position(get_x_position() - speed); //set new coordinates

		if (get_movement() == "right")
			set_x_position(get_x_position() + speed);

		cout << "(" << get_x_position() << "," << get_y_position() << ") ";

	}
	else
		cout << "Drone is dead \n";

}

void Drone::fire_weapon()
{
	cout << "Drone fire weapon: ";

	if (get_status() == 0)
		cout << "No weapon fired, drone is dead";

	else if (num_of_bombs == 0)
		cout << "No weapon fired, not enough ammo";

	else if (get_status() && num_of_bombs > 0) 
	{
		num_of_bombs -= 1;
		cout << "bomb " << "(" << num_of_bombs << " left)"; //display number of bombs left after firing
	}

	
}

void Drone::update_status()
{
	cout << "Drone update status: ";

	if (get_status() > 0) {
		set_status(get_status() - 1);
		cout << "Drone has been hit. (Pow...) " << "status points " << get_status();
	}

	else
		cout << "Drone is dead...";

}