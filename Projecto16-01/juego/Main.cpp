#include "VideoManager.h"
#include "ResourceManager.h"

using namespace std;

int main(int argc, char* args[]) {

	ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/Bliss.png", 1);

	int Two = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/nada.jpg", 1);

	ResourceManager::getInstance()->removeGraphic("TestResources/Bliss.png");

	int Tres = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/puke.jpeg", 1);

	ResourceManager::getInstance()->setAlphaGraphic(Tres, 128);

	ResourceManager::getInstance()->printLoadedGraphics();

	VideoManager::getInstance()->renderGraphic(Two, 0, 0, 1080, 720);

	VideoManager::getInstance()->updateScreen();

	VideoManager::getInstance()->waitTime(1000);

	VideoManager::getInstance()->renderGraphic(Tres, 0, 0, 1080, 720);

	VideoManager::getInstance()->updateScreen();

	VideoManager::getInstance()->waitTime(5000);

	return 0;
}