#include<iostream>
class World {
	public:
		World(int id) : _identifier(id) {
			std::cout << "Hello from " << _identifier << ".\n" ;
		}
		~World() {
			std::cout << "Goodbye!" << _identifier << ".\n";
		}
	private:
		const int _identifier;
}; 
World TheWorld(1);

int main()
{
	World smallWorld(2);
//	std::cout << "Hello from main!\n" << std::endl;
	for(int i=3;i<6;++i)
		World aWorld(i);
	World oneMoreWorld(6);
	return 0;
}
