#pragma once
#include <Windows.h>

interface CollisionInterface
{
public:
	  void OnCollisionEnter();
	  void CheckOtherCollision();
};