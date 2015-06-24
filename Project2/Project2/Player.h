#ifndef __PLAYER_H_
#define __PLAYER_H_
#include "Entity.h"
#include<ctime>
#include<iostream>
class Player: public Entity{

private:
	long lastupdate=0, curtime=0;

public:
	Player(SpriteSheet * sp):Entity(sp){
		 lastupdate=clock(); curtime=clock();
	}

	Player(SpriteSheet * sp, float pos_x, float pos_y):Entity(sp,pos_x,pos_y){
 lastupdate=clock(); curtime=clock();
	}

	Player(SpriteSheet * sp, float pos_x, float pos_y, float image_x, float image_y, float image_width, float image_height) :Entity(sp, pos_x, pos_y,image_x,image_y,image_width,image_height){

		 lastupdate=clock(); curtime=clock();
	}



	void Update(){
		if (Entity::isMoving()){
			int dir = Entity::getDirection();
			if (dir == 0){
				Entity::setY(Entity::getY() - 3.f);
				Entity::setImgY(192);
			}

			if (dir == 1){
				Entity::setX(Entity::getX() + 3.f);
				Entity::setImgY(128);
			}
			if (dir == 2){
				Entity::setY(Entity::getY() + 3.f);
				Entity::setImgY(0);

			}
			if (dir == 3){
				Entity::setX(Entity::getX() - 3.f);
				Entity::setImgY(64);

			}
			
			curtime=clock();
			//curtime*=1000;
			long dt =curtime-lastupdate;
		//std::cout << dt << std::endl;
			if ( dt> 20000){
					
				Entity::setImgX(Entity::getImgX()+32);
				if (Entity::getImgX() >=128){
					Entity::setImgX(0);
				}
				lastupdate=curtime;
			}

		}else{
		Entity::setImgX(0);

		}
	}



};
#endif
