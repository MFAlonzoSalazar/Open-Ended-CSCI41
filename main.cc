#include <time.h>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#inlcude "goFish.h"
#include "card.h"
#include "deck.h"
#inlcude "player.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand(static_cast<unsigned>(time(NULL)));
	goFish f;
	f.play();
	return 0;
}
