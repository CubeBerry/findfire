struct level_1_item
{
	int coin;
	int torch;
};

struct level_2_item
{
	int coin;
	int torch;
};

class Game
{
public:
	void Init(int coin, int torch);//map generation, player position initialize

	void Update();//map loading, movement, sight, torch/coin count, portal

	void Draw();//draw map

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

	//coin and torch and portal
	const char coin_shape = '$';
	const char torch_shape = 'T';
	const char portal_shape = 'O';

	//item count
	int coin_count = 0;
	int sight = 30;

	level_1_item l1{ 5,5 };
	level_2_item l2{ 8,8 };

	//character position
	const char character_pos = 'P';
	int character_x = 5;
	int character_y = 5;

	bool id;
};