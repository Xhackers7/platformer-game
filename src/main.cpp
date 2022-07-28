#include "Engine/Game.hpp"
#include "Engine/Log.hpp"

int main()
{
   Engine::Log::setLevel(Engine::Log::logInfo);
   Engine::Game game(60);

   game.run();
}