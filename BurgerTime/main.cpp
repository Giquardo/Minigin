#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "BurgerTime.h"
 
int main(int, char* []) {
	dae::BurgerTime  game;
	game.Run();
	return 0;
}