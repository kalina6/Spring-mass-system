#include "Punkt.h"



Punkt::Punkt()
{
}

Punkt::Punkt(float a1, float b1) {

	yPoczatkowy = b1;
	yNaKwadracie = 270;
	pozycja = ofVec2f(a1, b1);
	pozycjaStara = pozycja;
	predkosc = ofVec2f(0, 0);
	akumsily = ofVec2f(0, 0);
	masa = 1.0;
	dt = 0.03;
	r = 10.0;
	ruchomy = true;
	ciagniety = false;
	jumping = false;
	spada = false;
	color1 = {245, 245, 220};
	color2 = { 184, 3, 255 };
	colorCiagniecia = { 0, 255, 0 };
}

Punkt::~Punkt()
{
}

void Punkt::draw()
{
	if (ruchomy == true) {
		colorBiezacy = color2;
	}
	else colorBiezacy = color1;
	
	if (ciagniety == true) colorBiezacy = colorCiagniecia;

	ofSetColor(colorBiezacy);
	ofFill();
	ofDrawCircle(pozycja, r);
	ofNoFill();
}

void Punkt::euler()
{
	if (jumping == true) {


		pozycja.y -= 100 * dt;

		if (pozycja.y <= yPoczatkowy - 150) {
			jumping = false;
			spada = true;
		}
	}
	if (ruchomy == true) {
		predkosc += akumsily * dt;
		pozycjaNowa = pozycja + predkosc * dt;
		pozycjaStara = pozycja;
		pozycja = pozycjaNowa;
	}

}

void Punkt::verlet()
{
	if (jumping == true) {
		

		pozycja.y -=100 * dt;
		
		if (pozycja.y <= yPoczatkowy - 150) {
			jumping = false;
			spada = true;
			
		}
	}
	if (ruchomy == true) {
		pozycjaNowa = 2 * pozycja - pozycjaStara + (dt*dt*akumsily / masa);
		pozycjaStara = pozycja;
		pozycja = pozycjaNowa;
	}
}

void Punkt::jump()
{
	if (pozycja.y == yPoczatkowy || pozycja.y == yNaKwadracie) {
		jumping = true;
		
	}
}

void Punkt::falling(bool& key)
{
	
	if (pozycja.y < yPoczatkowy && jumping == false ) {
		spada = true;
		pozycja.y += 10 * 9.81 * dt;

		if (pozycja.y >= yPoczatkowy) {
			pozycja.y = yPoczatkowy;
			key = false;
			spada = false;
		}
			
	}
	
}

void Punkt::update() {
	if (pozycja.y >= yPoczatkowy) {
		pozycja.y = yPoczatkowy;
		spada = false;
		
	}

	if (pozycja.x <= 100 + r && pozycja.y == yPoczatkowy && spada == false) {
		pozycja.x = 100 + r;
	}

	if (pozycja.x >= ofGetWindowWidth()-100 - r && pozycja.y == yPoczatkowy && spada == false)
	{
		pozycja.x = 914;
	}

	if (pozycja.x < 100 + r && pozycja.y >= yNaKwadracie && spada == true) {
		
		
		pozycja.y = yNaKwadracie;
		spada = false;
	}

	if (pozycja.x >= 914 && pozycja.y >= yNaKwadracie && spada == true)
	{
		pozycja.y = yNaKwadracie;
		spada = false;
	}

	if (pozycja.x < 100 + r && yPoczatkowy > pozycja.y > yNaKwadracie && spada == true) {
		

		pozycja.x = 100 + r;
	
	}

	if (pozycja.x >= 914 && yPoczatkowy > pozycja.y > yNaKwadracie && spada == true)
	{
		pozycja.x = 914;
		
	}

	if (pozycja.x <= 10) pozycja.x = 10;

	if (pozycja.x >= 1014) pozycja.x = 1014;

}
