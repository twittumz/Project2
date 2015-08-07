#ifndef __GUI_TEXTFIELD_H
#define __GUI_TEXTFIELD_H

#include "GUIObject.h"
#include "TextRenderer.h"

#include <string>
class GUITextField : public GUIObject {

  private:
bool editable;
TextRenderer *textRenderer = nullptr;
std::string text;

void updateText(){
  textRenderer = new TextRenderer(GUIObject::getX(),GUIObject::getY(),text);
  textRenderer->setFontSize("12");
  int x = GUIObject::getX()+(GUIObject::getImgW()/2)-(textRenderer->getWidth()/2);
    int y = GUIObject::getY()+(GUIObject::getImgH()/2)-(textRenderer->getHeight()/2);
  textRenderer->setX(x);
  textRenderer->setY(y-2);
}

  public:
  GUITextField(SpriteSheet *sp):GUIObject(sp){
    GUIObject::setX(100);
    GUIObject::setY(100);
    GUIObject::setImgH(30);
    GUIObject::setImgW(120);
    text = "";
    updateText();
  }
  GUITextField(SpriteSheet *sp, float posx, float posy):GUIObject(sp,posx,posy){}
GUITextField(SpriteSheet * sp, float pos_x, float pos_y, float image_x, float image_y, float image_width, float image_height):GUIObject(sp, pos_x, pos_y, image_x, image_y, image_width, image_height){

}
    void Update(){}
  void Draw(){
    GUIObject::Draw();
    if(textRenderer!=nullptr){
      textRenderer->Draw();
    }
  }

void setEditable(bool _editable){
  editable=_editable;
}
bool isEditable(){
  return editable;
}
void setText(std::string _text){
  text=_text;
  updateText();
}
std::string getText(){
  return text;
}
};

#endif
