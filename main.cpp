#include "GamePlay.h"

int main() {
	
	GameObjects::Context context;
	GameObjects::Statistic statistic;
	GameObjects::Context& pointer_to_context = context;
	GameObjects::Statistic& pointer_to_statistic = statistic;

	GamePlay gameplay(pointer_to_context, pointer_to_statistic);
	gameplay.Run();
	
	return 0;
}