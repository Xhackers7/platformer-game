#include "core/Log.hpp"
#include "Game/Game.hpp"

int main()
{
   Log::setLevel(Log::logInfo);
   Game game(60);

   game.run();
}