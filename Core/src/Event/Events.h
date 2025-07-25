#pragma once
#include "../ENGINE_API.h"

enum class ENGINE_API KEY {
	ESC,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M
};

constexpr KEY KEY_ESC = KEY::ESC;
constexpr KEY KEY_W = KEY::W;
constexpr KEY KEY_A = KEY::A;
constexpr KEY KEY_S = KEY::S;
constexpr KEY KEY_D = KEY::D;

enum class ENGINE_API EventName {
	KEYPRESS,
	CREATE_GAME_OBJECT
};

enum class ENGINE_API EventType {
	INPUT,
	EDITOR
};



