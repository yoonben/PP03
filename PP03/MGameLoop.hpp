#pragma once

namespace Musoeun
{	
	MCommand* key[5];

	void Inutialize()
	{	
		key[0] = new LeftCommand();
		key[1] = new RightCommand();
		key[2] = new DownCommand();
		key[3] = new JumpCommand();
		key[4] = new RunCommand();
		//std::cout << "초기화 중...\n";
	}
	void Input()
	{	
		int input;
		std::cin >> input;
		
		key[input]->Execute();
		//int a;
		//std::cout << "입력 중...\n";
		//std::cin >> a;
	}
	void Update()
	{
		//std::cout << "Update 중...\n";
	}
	void Render()
	{
		//std::cout << "Rendering 중...\n";
	}

	void Release()
	{
		//std::cout << "삭제중 중...\n";

		for (size_t i = 0; i < 5; i++)
		{
			delete(key[i]);
		}

	}

	class MGameLoop
	{
	public:
		bool isGameRunning = false;

		MGameLoop(){}
		~MGameLoop(){}

		void Run()
		{
			isGameRunning = true;

			Inutialize();

			while (isGameRunning)
			{
				Input();
				Update();
				Render();
			}

			Release();
		}
	};
}
