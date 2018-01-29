#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(30);
	

	KS = 1755.0;
	KD = 35.0;
	
	licznik = 0;
	punkty.push_back(Punkt(ofGetWindowWidth() / 2,ofGetWindowHeight()/2));
	punkty.push_back(Punkt(punkty[0].pozycja.x + 50.0, punkty[0].pozycja.y));
	punkty.push_back(Punkt(punkty[0].pozycja.x - 50.0, punkty[0].pozycja.y));
	
	liny.push_back(Lina(punkty[0], punkty[1]));
	liny.push_back(Lina(punkty[0], punkty[2]));
	
	punkty[0].ruchomy = false;
	skok=false;
	
}

//--------------------------------------------------------------
void ofApp::update(){



	for (auto &p : punkty)
	{
		p.update();
		p.falling(skok);
	}
	
	if (wcisniecie == false || skok == false) {
		// zerujemy sily
		for (auto & p : punkty)
		{
			p.akumsily.x = 0;
			p.akumsily.y = 0;
		}

		for (auto i = 0; i < liny.size(); i++)
		{
			// odleglosci miedzy punktami
			Punkt *p1 = &punkty[0];
			Punkt *p2 = &punkty[i + 1];


			ofVec3f pos1 = p1->pozycja;
			ofVec3f pos2 = p2->pozycja;

			float dist = pos1.distance(pos2);


			//std::cout << dist << std::endl;


			if (dist != 0)
			{
				// predkosci i pozycje 
				p1->predkosc = p1->pozycja - p1->pozycjaStara;
				p2->predkosc = p2->pozycja - p2->pozycjaStara;

				ofVec2f vn = p1->predkosc - p2->predkosc;	// roznica predkosci
				ofVec2f dpos = pos1 - pos2;						// roznica pozycji

																// sily
				ofVec2f f = (dist - liny[i].dlugosc) * KS + (vn * dpos) * KD / dist;
				ofVec2f F = f * (dpos / dist);
				p1->akumsily -= F;
				p2->akumsily += F;

			}
		}

	}
		// aktualizacja pozycji
		if (licznik < 2)
			for (auto &p : punkty)
			{
				p.euler();
				licznik++;
			}
		else
			for (auto &p : punkty)
			{
				p.verlet();
			}

		liny[0].update(punkty[0], punkty[1]);
		liny[1].update(punkty[0], punkty[2]);


		/*std::cout << liny[0].dlugosc << std::endl;
		std::cout << liny[1].dlugosc << std::endl;
	*/
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofPushMatrix();

	for (auto &l : liny)
	{
		l.draw();
	}
	
	for (auto &p : punkty) {
		p.draw();
	}
	ofSetColor(0, 255, 0);
	ofFill();
	ofDrawRectangle(0, (ofGetWindowHeight() / 2) - 100, 100, 150);
	ofDrawRectangle(ofGetWindowWidth()-100, (ofGetWindowHeight() / 2) -100, 100, 150);
	ofDrawRectangle(0, (ofGetWindowHeight()/2) + punkty[0].r , ofGetWindowWidth(),50 );
	ofNoFill();
	ofPopMatrix();
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	
	case OF_KEY_LEFT:
		// rozciaganie pkt3
		punkty[0].pozycja.x -= 5;
		punkty[1].pozycja.x -= 5;
		punkty[2].pozycja.x -= 5;
		//wcisniecie = true;
		break;
	case OF_KEY_RIGHT:
		// rozciaganie pkt2
		punkty[0].pozycja.x += 5;
		punkty[1].pozycja.x += 5;
		punkty[2].pozycja.x += 5;
		//wcisniecie = true;
		break;
	
	case OF_KEY_UP:
		//skok
		skok = true;
		for (auto &p : punkty)
		{
			p.jump();
		}
		
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
