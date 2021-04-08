class Game
{
public:
	void Init();//map generation, player position initialize

	void Update();//map loading, movement, sight, torch/coin count, portal

	void Draw();

	//Close();
	bool isDone() const
	{
		return id;
	}
private:
	char World[23][23];

	enum level_check
	{
		level_1,
		level_2,
	};
	int current_level = level_1;

	//coin and torch
	int coin = 5;
	const char coin_shape = '$';
	int torch = 5;
	const char torch_shape = 'T';

	//character position
	const char character_pos = 'P';
	int character_x = 5;
	int character_y = 5;

	bool id;
};