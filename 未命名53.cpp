#include<iostream>
class Matter {
	public:
		Matter(int id) : _identifier(id) {
			std::cout << " Matter for " << _identifier << " created\n";
		}
		~Matter() {
			std::cout << " Matter for " << _identifier << " annihilated\n";
		}
	public:
		const int _identifier;
};

class World {
	public:
		World(int id) : 
		_identifier(id), 
		_matter(_identifier)	//初始化嵌入体 
		{
			std::cout << " Hello from world" << _identifier << ".\n"; 
		}
		~World() {
			std::cout << "Goodbye from world" << _identifier << ".\n";
		}
	private:
		const int _identifier;
		const Matter _matter;
};

World TheUniverse(1);

int main()
{
	World smallWorld(2);
	return 0;
}
