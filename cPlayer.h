class cPlayer{

public:
	cPlayer();

	cPlayer(std::string);

	void drawPlayer(sf::RenderWindow&);

	void playerDirection(char, float);

	void movePlayer();

	bool hidePlayer(int posX, int posY);

	bool throwStone();

	sf::Sprite& getAimSprite();

	bool canBeChased();


private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	int i = 0;
	float interval = 20;
	bool hide;
};

