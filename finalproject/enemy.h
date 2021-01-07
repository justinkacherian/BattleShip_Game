#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
using namespace std;

class Enemy {

private:
	int x_position, y_position, width, height, status;
	string movement; //hold the starting movement of the enemy; left or right
protected:
	void set_x_position(int x);
	void set_y_position(int y); //setters
	void set_width(int w);
	void set_height(int h);
	void set_status(int s);
	void set_movement(string m);
	int get_x_position();
	int get_y_position();
	int get_width(); //getters
	int get_height();
	int get_status();
	string get_movement();
public:
	Enemy(int x, int y, int s, string m); 	//constructor that takes parameters for member variables
	virtual void move_position() = 0;
	virtual void fire_weapon() = 0; //pure virtual functios -- abstract class
	virtual void update_status() = 0;

};


#endif