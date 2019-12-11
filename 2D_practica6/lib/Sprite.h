#pragma once

#include "Background.h"
#include "CircleCollider.h"
#include "RectCollider.h"
#include "PixelsCollider.h"



enum CollisionType
{
	COLLISION_NONE,
	COLLISION_CIRCLE,
	COLLISION_RECT,
	COLLISION_PIXELS
};

class Sprite : public Drawable
{
public:
	// Tpo de la funci�n callback 
	typedef void (* CallbackFunc)(Sprite&, float);

	// Indicamos el n�mero de frames en horizontal y vertical
	// que tendr� la imagen del sprite 
	Sprite(const ltex_t* tex, int hframes = 1, int vframes = 1); 

	// Establecemos puntero a la funci�n callback 
	void setCallback(CallbackFunc func); 

	// Puntero gen�rico a datos (normalmente introducimos aqu� los datos 
	// del sprite que se van a utilizar en la funci�n callback) 
	void* getUserData(); 
	void setUserData(void* data); 

	int getHframes() const; 
	int getVframes() const;
	// Tama�o de un frame multiplicado por la escala 
	Vec2 getSize() const;
	// Veces por segundo que se cambia el frame de animaci�n 
	int getFps() const; 
	void setFps(int fps); 
	// Frame actual de animaci�n 
	float getCurrentFrame() const; 
	void setCurrentFrame(int frame); 

	virtual void update(float deltaTime);
	virtual void draw() const;

	void setCollisionType(CollisionType type);
	CollisionType getCollisionType() const;
	const Collider* getCollider() const;
	bool collides(Sprite& other);


private:
	int iCurrentFrame = 0;
	int iFps = 1;
	int iHorizontalFrames;
	int iVerticalFrames;
	float fcurrentAnimationTime = 0;
	CallbackFunc callbackFunc;
	CollisionType eType;
	Collider* pCollider;
};

