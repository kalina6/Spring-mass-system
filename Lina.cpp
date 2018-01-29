#include "Lina.h"



Lina::Lina()
{
}

Lina::Lina(Punkt a, Punkt b) {

	jeden = a;
	dwa = b;
	dlugosc = jeden.pozycja.distance(dwa.pozycja);

}

Lina::~Lina()
{
}

void Lina::draw()
{
	ofSetColor(245, 245, 220);
	ofFill();
	ofSetLineWidth(4);
	ofDrawLine(jeden.pozycja, dwa.pozycja);
	ofNoFill();


}

void Lina::update(Punkt a, Punkt b)
{
	jeden = a;
	dwa = b;
	
}