// Timber.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	View view(sf::FloatRect(0, 0, 1280, 720));
	window.setView(view);

	// Background
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spirteBackground;
	spirteBackground.setTexture(textureBackground);
	spirteBackground.setPosition(0, 0);

	// Tree
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spirteTree;
	spirteTree.setTexture(textureTree);
	spirteTree.setPosition(810, 0);

	// Bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	bool beeActive = false;
	float beeSpeed = 0.0f;

	// Cloud
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	Sprite spirteCloud1;
	Sprite spirteCloud2;
	Sprite spirteCloud3;
	spirteCloud1.setTexture(textureCloud);
	spirteCloud2.setTexture(textureCloud);
	spirteCloud3.setTexture(textureCloud);
	spirteCloud1.setPosition(0, 0);
	spirteCloud2.setPosition(0, 250);
	spirteCloud3.setPosition(0, 500);
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	Clock clock;

	while (window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		Time dt = clock.restart();

		if (!beeActive) {
			srand((int)time(0) * 10);
			beeSpeed = (rand() % 200) + 200;

			srand((int)time(0) * 10);
			float height = (rand() % 500) + 500;
			spriteBee.setPosition(2000, height);
			beeActive = true;
		}
		else {
			spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

			if (spriteBee.getPosition().x < -100) {
				beeActive = false;
			}
		}

		window.clear();
		window.draw(spirteBackground);
		window.draw(spirteCloud1);
		window.draw(spirteCloud2);
		window.draw(spirteCloud3);
		window.draw(spirteTree);
		window.draw(spriteBee);
		window.display();
	}
	return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
