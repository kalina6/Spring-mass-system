#pragma once
#include "ofMain.h"
#include "Punkt.h"

class Lina
{
public:
	Punkt jeden;
	Punkt dwa;
	float dlugosc;


	Lina();
	Lina(Punkt a, Punkt b);
	~Lina();

	void draw();
	void update(Punkt a, Punkt b);
	

};





