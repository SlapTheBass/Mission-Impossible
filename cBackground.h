
class cBackground{

public:

	cBackground();

	cBackground(std::string, std::string);

	void drawBackground(sf::RenderWindow&);

	sf::Sprite getBgrSprite();

private:

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
};

