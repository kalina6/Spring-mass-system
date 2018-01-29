#pragma once
#include "ofMain.h"

class Punkt
{
public:
	ofVec2f pozycja;
	ofVec2f pozycjaStara;
	ofVec2f pozycjaNowa;
	ofVec2f predkosc;
	ofVec2f akumsily;
	float masa, dt, r, yPoczatkowy, yNaKwadracie;
	bool ruchomy, ciagniety, jumping, spada;
	ofColor colorBiezacy;
	ofColor color1;
	ofColor color2;
	ofColor colorCiagniecia;

    Punkt();
	Punkt(float a1, float b1);
	~Punkt();

	void draw();
	void euler();
	void verlet();
	void jump();
	void falling(bool& key);
	void update();


};

