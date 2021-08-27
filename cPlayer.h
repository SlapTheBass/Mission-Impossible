class cPlayer{

public:
	cPlayer();

	cPlayer(std::string);

	void drawPlayer(sf::RenderWindow&);

	void playerDirection(char, float);

	void setSpeed();

	sf::Sprite isHidden();

	void Slow();

	void movePlayer();

	bool throwStone();

	sf::Sprite& getAimSprite();

	bool canBeChased();


private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	int i = 0;
	float interval = 20;
	float max_speed = 12.2;
	float speed;
	bool hide;
};

