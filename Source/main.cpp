#include<window/Window.h>

int main() {

	Window* basicWindow = new Window({ 1280,720 }, "Basic Window");

	basicWindow->Initialize();
	
	while (basicWindow->isVisible()) {
		basicWindow->Run();
	}
	
	delete basicWindow;

	return 0;

}