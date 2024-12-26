#include "GamePlay.h"

int main() {
	
	GameObjects::Context context;
	GameObjects::Statistic statistic;

	GamePlay gameplay(context, statistic);
	gameplay.Run();
	
	return 0;
}