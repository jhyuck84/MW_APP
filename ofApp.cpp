#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);

	image_setup();
	button_setup();

	init_font.load("game_over.ttf", 100);

	STATE = initState;

	cout << "box game setup" << endl;
	box2d.init();
	box2d.setGravity(0, 30);
	box2d.createGround();
	box2d.createBounds();
	box2d.setFPS(60);
	box2d.registerGrabbing();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (STATE == gameState) {
		gameState_update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (STATE == initState) {
		initState_draw();
	}
	else if (STATE == introState) {
		introState_draw();
	}
	else if (STATE == gameState) {
		gameState_draw();
	}
	else if (STATE == finishState) {
		finishState_draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	if (STATE == initState) {
		initState_mouseReleased();
	}
	else if (STATE == introState) {
		introState_mouseReleased();
	}
	else if (STATE == gameState) {
		gameState_mouseReleased();
	}
	else if (STATE == finishState) {
		finishState_mouseReleased();
	}
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

void ofApp::image_setup() {
	initState_box_start_btn_img.load("button_img1.png");
	introState_game_start_btn_img.load("button_img2.jpg");
	home_btn_img.load("home.png");
	retry_btn_img.load("retry.png");
	next_btn_img.load("next.png");
}

void ofApp::button_setup() {
	initState_box_start_btn.setup(200, 500, 100, 100, initState_box_start_btn_img);
	initState_card_start_btn.setup(500, 500, 100, 100, initState_box_start_btn_img);
	introState_game_start_btn.setup(200, 500, 100, 100, introState_game_start_btn_img);
	home_btn.setup(80, 80, 100, 100, home_btn_img);
	retry_btn.setup(ofGetWidth() - 80, 80, 100, 100, retry_btn_img);
	next_btn.setup(ofGetWidth() - 80, 80, 100, 100, next_btn_img);
}

void ofApp::gameState_update() {
	if (SelectedGame == box_game) {
		box_game_update();
	}
	else if (SelectedGame == card_game) {

	}
}

void ofApp::initState_draw() {
	


	ofFill();
	if (SelectedGame == 1) {
		ofSetColor(255);
	}
	else {
		ofSetColor(0);
	}
	ofDrawRectangle(0, 0, ofGetWidth()/2, ofGetHeight());
	
	if (SelectedGame == 1) {
		ofSetColor(0);
	}
	else {
		ofSetColor(255);
	}
	init_font.drawString("BOX_GAME", ofGetWidth() * 0.25 - init_font.stringWidth("BOX_GAME") / 2, ofGetHeight()*0.25);
	if (SelectedGame == 2) {
		ofSetColor(255);
	}
	else {
		ofSetColor(0);
	}
	ofDrawRectangle(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());
	if (SelectedGame == 2) {
		ofSetColor(0);
	}
	else {
		ofSetColor(255);
	}
	init_font.drawString("CARD_GAME", ofGetWidth() * 0.75 - init_font.stringWidth("CARD_GAME") / 2, ofGetHeight()*0.25);
	ofSetColor(255);
	ofDrawLine(ofGetWidth() / 2, ofGetHeight(), ofGetWidth() / 2, 0);


	ofPath rect1;
	rect1.setFilled(false);
	rect1.setStrokeColor(0);
	rect1.setStrokeWidth(2);
	rect1.rectangle(ofGetWidth() * 0.25 - 150, ofGetHeight() * 0.6, 300, 100);
	rect1.draw();
	ofSetColor(0);
	init_font.drawString("SELECT", ofGetWidth() * 0.25 - init_font.stringWidth("SELECT") / 2, 
		ofGetHeight() * 0.6 + 50 + init_font.stringHeight("SELECT") / 2);

	ofPath rect2;
	rect2.setFilled(false);
	rect2.setStrokeColor(0);
	rect2.setStrokeWidth(2);
	rect2.rectangle(ofGetWidth() * 0.75 - 150, ofGetHeight() * 0.6, 300, 100);
	rect2.draw();
	ofSetColor(0);
	init_font.drawString("SELECT", ofGetWidth() * 0.75 - init_font.stringWidth("SELECT") / 2,
		ofGetHeight() * 0.6 + 50 + init_font.stringHeight("SELECT") / 2);
	
	//ofDrawBitmapString("This is mode 1", ofGetWidth() / 2, ofGetHeight() / 2);
	
	//initState_box_start_btn.draw();
	//initState_card_start_btn.draw();
}

void ofApp::introState_draw() {

	ofFill();
	ofBackground(50);

	if (SelectedGame == box_game) {
		ofFill();
		ofColor(255);
		init_font.drawString("BOX_GAME_V1\nYOU SCORE POINTS BY SLIDING BOXES\n5 POINTS TO WIN",350, 300);

		ofPath rect1;
		rect1.setFilled(false);
		rect1.setStrokeColor(255);
		rect1.setStrokeWidth(2);
		rect1.rectangle(ofGetWidth() * 0.5 - 150, ofGetHeight() * 0.6, 300, 100);
		rect1.draw();
		init_font.drawString("START", ofGetWidth() * 0.5 - init_font.stringWidth("START") / 2,
			ofGetHeight() * 0.6 + 50 + init_font.stringHeight("START") / 2);
	}

	if (SelectedGame == card_game) {
		ofFill();
		ofColor(255);
		init_font.drawString("CARD_GAME_V1\nYOU SCORE POINTS BY MATCHING CARDS\nCHOOSE OPTION", 350, 300);



		ofPath rect_level1;
		rect_level1.setFilled(false);
		rect_level1.setStrokeColor(255);
		rect_level1.setStrokeWidth(2);
		rect_level1.rectangle(ofGetWidth() * 0.5 - 150, ofGetHeight() * 0.5, 100, 100);
		rect_level1.draw();
		if (game_level == 1) {
			ofSetColor(255);
		}
		else {
			ofSetColor(20);
		}
		init_font.drawString("4", ofGetWidth() * 0.5 - 100 - init_font.stringWidth("4") / 2,
			ofGetHeight() * 0.5 + 50 + init_font.stringHeight("4") / 2);

		ofPath rect_level2;
		rect_level2.setFilled(false);
		rect_level2.setStrokeColor(255);
		rect_level2.setStrokeWidth(2);
		rect_level2.rectangle(ofGetWidth() * 0.5 - 50, ofGetHeight() * 0.5, 100, 100);
		rect_level2.draw();
		if (game_level == 2) {
			ofSetColor(255);
		}
		else {
			ofSetColor(20);
		}
		init_font.drawString("6", ofGetWidth() * 0.5 - init_font.stringWidth("6") / 2,
			ofGetHeight() * 0.5 + 50 + init_font.stringHeight("6") / 2);

		ofPath rect_level3;
		rect_level3.setFilled(false);
		rect_level3.setStrokeColor(255);
		rect_level3.setStrokeWidth(2);
		rect_level3.rectangle(ofGetWidth() * 0.5 + 50, ofGetHeight() * 0.5, 100, 100);
		rect_level3.draw();
		if (game_level == 3) {
			ofSetColor(255);
		}
		else {
			ofSetColor(20);
		}
		init_font.drawString("9", ofGetWidth() * 0.5 + 100 - init_font.stringWidth("9") / 2,
			ofGetHeight() * 0.5 + 50 + init_font.stringHeight("9") / 2);
		//init_font.drawString("START", ofGetWidth() * 0.5 - init_font.stringWidth("START") / 2,
		//	ofGetHeight() * 0.6 + 50 + init_font.stringHeight("START") / 2);

		ofPath rect1;
		rect1.setFilled(false);
		rect1.setStrokeColor(255);
		rect1.setStrokeWidth(2);
		rect1.rectangle(ofGetWidth() * 0.5 - 150, ofGetHeight() * 0.6, 300, 100);
		rect1.draw();
		ofSetColor(255);
		init_font.drawString("START", ofGetWidth() * 0.5 - init_font.stringWidth("START") / 2,
			ofGetHeight() * 0.6 + 50 + init_font.stringHeight("START") / 2);
	}

	ofFill();
	ofSetColor(0);
	//ofDrawBitmapString("This is mode 2", ofGetWidth() / 2, ofGetHeight() / 2);
	//introState_game_start_btn.draw();
	home_btn.draw();

	
}

void ofApp::gameState_draw() {

	if (SelectedGame == box_game) {
		box_game_draw();
		ofFill();
		ofSetColor(0);
		ofDrawBitmapString("box game", ofGetWidth() / 2, ofGetHeight() / 2 - 50);
	}

	if (SelectedGame == card_game) {
		card_game_draw();
		ofFill();
		ofSetColor(0);
		ofDrawBitmapString("card game", ofGetWidth() / 2, ofGetHeight() / 2 - 50);
	}

	ofFill();
	ofSetColor(0);
	ofDrawBitmapString("This is mode 3", ofGetWidth() / 2, ofGetHeight() / 2);
	home_btn.draw();
	next_btn.draw();
}

void ofApp::finishState_draw() {

	if (SelectedGame == box_game) {
		ofFill();
		ofSetColor(255);
		if (WIN) {
			init_font.drawString("CONGRATULATIONS, YOU WIN", 350, 300);
		}
		else {
			init_font.drawString("TRY AGAIN!   :(", 350, 300);
		}
	}

	if (SelectedGame == card_game) {
		ofFill();
		ofSetColor(255);
		init_font.drawString("CONGRATULATIONS, YOU FINISH", 350, 300);
	}

	home_btn.draw();
	retry_btn.draw();
}

void ofApp::initState_mouseReleased() {


	if (ofGetMouseX() < ofGetWidth() / 2) {
		SelectedGame = box_game;
	}
	else {
		SelectedGame = card_game;
	}
	if (SelectedGame != 0) {
		if (ofGetMouseX() > ofGetWidth() * 0.75 - 150 && ofGetMouseX() < ofGetWidth() * 0.75 + 150 &&
			ofGetMouseY() > ofGetHeight() * 0.6 && ofGetMouseY() < ofGetHeight() * 0.6 + 100) {
			STATE = introState;
		}

		if (ofGetMouseX() > ofGetWidth() * 0.25 - 150 && ofGetMouseX() < ofGetWidth() * 0.25 + 150 &&
			ofGetMouseY() > ofGetHeight() * 0.6 && ofGetMouseY() < ofGetHeight() * 0.6 + 100) {
			STATE = introState;
		}
	}
}

void ofApp::introState_mouseReleased() {
	//if (introState_game_start_btn.isClick(ofGetMouseX(), ofGetMouseY())) {
	if (ofGetMouseX() > ofGetWidth() * 0.5 - 150 && ofGetMouseX() < ofGetWidth() * 0.5 + 150 &&
		ofGetMouseY() > ofGetHeight() * 0.6 && ofGetMouseY() < ofGetHeight() * 0.6 + 100) {
		if (SelectedGame == box_game) {
			box_game_setup();
		}
		else if (SelectedGame == card_game) {
			card_game_setup();
		}
		STATE = gameState;
	}
	if (ofGetMouseX() > ofGetWidth() * 0.5 - 150 && ofGetMouseX() < ofGetWidth() * 0.5 - 50 &&
		ofGetMouseY() > ofGetHeight() * 0.5 && ofGetMouseY() < ofGetHeight() * 0.5 + 100) {
		game_level = 1;
	}

	if (ofGetMouseX() > ofGetWidth() * 0.5 - 50 && ofGetMouseX() < ofGetWidth() * 0.5 + 50 &&
		ofGetMouseY() > ofGetHeight() * 0.5 && ofGetMouseY() < ofGetHeight() * 0.5 + 100) {
		game_level = 2;
	}

	if (ofGetMouseX() > ofGetWidth() * 0.5 + 50 && ofGetMouseX() < ofGetWidth() * 0.5 + 150 &&
		ofGetMouseY() > ofGetHeight() * 0.5 && ofGetMouseY() < ofGetHeight() * 0.5 + 100) {
		game_level = 3;
	}

	if (home_btn.isClick(ofGetMouseX(), ofGetMouseY())) {

		STATE = initState;
	}
}

void ofApp::gameState_mouseReleased() {
	if (home_btn.isClick(ofGetMouseX(), ofGetMouseY())) {
		if (SelectedGame == box_game) {
			box_game_end();
		}
		else if (SelectedGame == card_game) {
			card_game_end();
		}
		STATE = initState;
		
	}
	else if (next_btn.isClick(ofGetMouseX(), ofGetMouseY())) {
		if (SelectedGame == box_game) {
			box_game_end();
		}
		else if (SelectedGame == card_game) {
			card_game_end();
		}
		STATE = finishState;
	}
	else {

		if (SelectedGame == box_game) {
			box_game_mouse_released();
		}
		else if (SelectedGame == card_game) {
			card_game_mouse_released(ofGetMouseX(), ofGetMouseY());
		}
		
	}


}

void ofApp::finishState_mouseReleased() {
	if (home_btn.isClick(ofGetMouseX(), ofGetMouseY())) {
		STATE = initState;
	}
	if (retry_btn.isClick(ofGetMouseX(), ofGetMouseY())) {
		if (SelectedGame == box_game) {
			box_game_setup();
		}
		else if (SelectedGame == card_game) {
			card_game_setup();
		}
		STATE = gameState;
	}
}

//Box Game
void ofApp::box_game_setup() {


	box_number = 1;
	isAction = false;

	float w = 100;
	float h = 100;
	auto box = make_shared<ofxBox2dRect>();
	box->setPhysics(3.0, 0.2, 1.0);
	box->setup(box2d.getWorld(), 1920 / 2, 1080 - 100, w, h);
	boxes.push_back(box);
}

void ofApp::box_game_update() {
	box2d.update();

	ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);

	if (isAction) {
		if (boxes.size() > box_number) {
			auto &box = boxes.back();
			ofVec2f last_box_cur_pos = box->getPosition();

			int index = 0;
			for (auto &tbox : boxes) {
				if (tbox->getPosition().y > ofGetHeight() - 100 * index) {
					cout << "game over" << endl;
					isAction = false;
					box_game_end();
					STATE = finishState;
					WIN = false;
				}
				index++;
			}

			if (last_box_cur_pos.y < ofGetHeight() - 100 * box_number && last_box_cur_pos.y > ofGetHeight() - 100 * (box_number + 1)) {
				if (ofDist(last_box_pre_pos.x, last_box_pre_pos.y, last_box_cur_pos.x, last_box_cur_pos.y) < 0.1) {
					box_number++;
					isAction = false;
					if (box_number == 5) {
						box_game_end();
						STATE = finishState;
						WIN = true;
					}
				}
			}
			last_box_pre_pos = last_box_cur_pos;

		}
	}



	if (boxes.size() == box_number) {
		float w = 100;
		float h = 100;
		auto box = make_shared<ofxBox2dRect>();
		box->setPhysics(3.0, 0.2, 1.0);
		if (isLeft) {
			box->setup(box2d.getWorld(), ofGetWidth() / 4, 100, w, h);
		}
		else {
			box->setup(box2d.getWorld(), ofGetWidth() / 4 * 3, 100, w, h);
		}
		boxes.push_back(box);
		isLeft = !isLeft;
	}
}

void ofApp::box_game_end() {
	boxes.clear();
	/*box_number = 1;
	isAction = false;

	float w = 100;
	float h = 100;
	auto box = make_shared<ofxBox2dRect>();
	box->setPhysics(3.0, 0.2, 1.0);
	box->setup(box2d.getWorld(), fullScreenW / 2, fullScreenH - 100, w, h);
	boxes.push_back(box);*/
}

void ofApp::box_game_draw() {
	int order = 0;
	for (auto &box : boxes) {
		ofFill();
		if (order % 2 == 0) {
			ofSetHexColor(0xe63b8b);
		}
		else {
			ofSetHexColor(0x50a4ff);
		}
		box->draw();
		order++;
	}
}

void ofApp::box_game_mouse_dragged() {

}

void ofApp::box_game_mouse_released() {
	isAction = true;
}

//Card Game
void ofApp::card_game_setup() {
	rightSelectedCard = -1;
	leftSelectedCard = -1;

	numWin = 0;
	gamePlayTime = 0;
	count = 0;
	if (game_level == 1) {
		cardNum = 4;
	}
	int cardWidth = 100;
	int cardHeight = 150;
	int cardGap = 25;
	for (int i = 0; i < cardNum; i++) {
		int row = i % 2;
		int col = i / 2;
		leftCard[i].setup((ofGetWidth()*0.25 - cardWidth - cardGap) + (cardWidth + cardGap)*row,
			(ofGetHeight()*0.5 - cardHeight - cardGap) + (cardHeight + cardGap)*col, cardWidth, cardHeight, i + 1);

		rightCard[i].setup((ofGetWidth()*0.75 - cardWidth - cardGap) + (cardWidth + cardGap)*row,
			(ofGetHeight()*0.5 - cardHeight - cardGap) + (cardHeight + cardGap)*col, cardWidth, cardHeight, i + 1);
	}

	for (int i = 0; i < 10; i++) {
		int rNum1 = int(ofRandom(cardNum));
		int rNum2 = int(ofRandom(cardNum));

		int tempNum = leftCard[rNum1].cardNumber;
		leftCard[rNum1].setNum(leftCard[rNum2].cardNumber);
		leftCard[rNum2].setNum(tempNum);


		rNum1 = int(ofRandom(cardNum));
		rNum2 = int(ofRandom(cardNum));

		tempNum = rightCard[rNum1].cardNumber;
		rightCard[rNum1].setNum(rightCard[rNum2].cardNumber);
		rightCard[rNum2].setNum(tempNum);

	}
}

void ofApp::card_game_draw() {
	//string txt = ofToString(int(ofGetElapsedTimef()));
	//gameEndFont.drawString(txt, ofGetWidth() / 2, 250);

	for (int i = 0; i < cardNum; i++) {
		leftCard[i].draw();
		rightCard[i].draw();
	}
	
	if (leftSelectedCard != -1 && rightSelectedCard != -1) {
		if (leftCard[leftSelectedCard].cardNumber == rightCard[rightSelectedCard].cardNumber) {
			//win
			leftSelectedCard = -1;
			rightSelectedCard = -1;
			numWin++;
			if (numWin == cardNum) {
				gamePlayTime = ofGetElapsedTimef();
				box_game_end();
				STATE = finishState;
			}
		}

		else {
			count++;
			if (count > 50) {

				leftCard[leftSelectedCard].cardClose();
				rightCard[rightSelectedCard].cardClose();
				leftSelectedCard = -1;
				rightSelectedCard = -1;
				count = 0;
			}
		}
	}
}
void ofApp::card_game_end() {

}

void ofApp::card_game_mouse_released(int x, int y) {
	cout << x << " " << y << endl;
	
	if (leftSelectedCard == -1) {
		for (int i = 0; i < cardNum; i++) {
			if (leftCard[i].isSelected(x, y)) {
				leftSelectedCard = i;
				return;
			}
		}
	}

	if (rightSelectedCard == -1) {
		for (int i = 0; i < cardNum; i++) {
			if (rightCard[i].isSelected(x, y)) {
				rightSelectedCard = i;
				return;
			}
		}
	}
	
}


