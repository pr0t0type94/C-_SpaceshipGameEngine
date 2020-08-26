#pragma once
#include <vector>
class GameObject
{
	struct Transform 
	{ 
		int x;
		int y;	
	};
public: 
	Transform transform;

	GameObject() {}
	GameObject(int _x,int _y) 
	{
		transform.x = _x;
		transform.y = _y;
	}

	~GameObject()
	{

	}


};

