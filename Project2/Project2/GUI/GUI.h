#ifndef __GUI_H_
#define __GUI_H_
//manage all gui things
#include "../Settings.h"
#include "../Sprite.h"
#include "../SpriteSheet.h"
#include "GUIObject.h"
#include "GUIWindow.h"
#include "../Player.h"
#include "TextRenderer.h"
#include "GUIButton.h"
#include "GUITextField.h"
#include <iostream>
#include <sstream>
#include <locale>

class GUI{
private:
	//Engine *engine;
	GUIWindow * gmenu;
	SpriteSheet *gmenu_sprite;
	GUIObject *hud;
		SpriteSheet *hud_sprite;

		GUIObject *hpHud;
		GUIObject *hpBar;

		GUIObject*  target_hphud;
		GUIObject * target_hpbar;
		TextRenderer *textRend;

		GUITextField *textfield;

		bool typing=false;
		bool capsLock=false;
		bool shiftDown=false;
public:
	 static void gameMenuExit_onClick (GUIButton *owner) {
		std::cout<<owner->getText()<<"  - Button clicked\n";
		running=false;
	}
	GUI(){
		gmenu_sprite = new SpriteSheet("GUIWindow");
			gmenu = new GUIWindow(gmenu_sprite,350,200);
			gmenu->setVisible(false);


			//void (*testCall)(GUIButton *)=testClickCallback;
			gmenu->addComponent(new GUIButton(new SpriteSheet("test_button"),"Exit",gameMenuExit_onClick,gmenu->getX()+15,gmenu->getY()+15,0,0,128,32));
			hud_sprite = new SpriteSheet("GUIHud");
			hud= new GUIObject(hud_sprite, 0, 0,0,0,32,32);

      hpHud = new GUIObject(hud_sprite, 36, 0, 0, 32, 160, 32);
			hpBar= new GUIObject(hud_sprite, 40,20, 0, 64, 32, 32);

			target_hphud = new GUIObject(hud_sprite, 300, 0, 0, 32, 160, 32);
			target_hpbar = new GUIObject(hud_sprite, 304, 0, 0, 64, 32, 32);

			textfield = new GUITextField(new SpriteSheet("textFieldBg"));
	}


	void Update(){


	}

	void Draw(Entity *player){
		gmenu->Draw();
		hud->Draw();
		hpHud->Draw();
		textfield->Draw();
		float maxbarlen = 153;
		float hp = (float)player->getHP() / (float)player->getMaxHP();


		hpBar->getSprite()->Draw(40, 0, hp*maxbarlen,32,0, 64, 32, 32);

		if (player->getTarget() != nullptr){

			target_hphud->Draw();
			maxbarlen = 153;

			hp = (float)player->getTarget()->getHP() / (float)player->getTarget()->getMaxHP();
			target_hpbar->getSprite()->Draw(304, 0, hp*maxbarlen,32,0,64,32, 32);


		}


	//	hpBar->Draw();
	}

	bool checkMouseClick(double mousex, double mousey){
   if(gmenu->checkMouseClick(mousex,  mousey)){
		 return true;
	 }
	 return false;
	}
	void setGameMenuVisible(bool vis){
		gmenu->setVisible(vis);

	}
bool getGameMenuVisible(){
	return gmenu->isVisible();
	}
bool isTyping(){
	return typing;
}
void setTyping(bool _typing){
	typing=_typing;
}
void keyPressed(int key){
//	textfield->setText((std::string)textfield->getText()+key);
//std::cout<<key<<std::endl;
std::string text = textfield->getText();
if(key == 259){
	text = text.substr(0,text.length()-1);
}else if(key == 280){
//	upperCase=!upperCase;
return;
}else {
std::stringstream ss;
char k = key;
ss<<k;
std::string _key = ss.str();
if(!shiftDown && !capsLock ){
std::locale loc;
_key = std::tolower(_key[0],loc);
}

text = text + _key;
}
textfield->setText(text);
}

void setCapsLock(bool _capsLock){
capsLock = _capsLock;
}
bool isCapsLock(){
	return capsLock;
}

void setShiftDown(bool _shiftDown){
	shiftDown= _shiftDown;
}
bool isShiftDown(){
	return shiftDown;
}
};

#endif
