#pragma once
#include <Windows.h>
#include <array>
#include <memory>
//#include <vector>

#include "_deps/pdcurses-src/curses.h"
//#include "_deps/pdcurses-src/curses.h"

const int Field_width = 70;
const int Field_height = 25;


namespace GameObjects {
	
	//inline HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); //inline переменная может быть определена в нескольких файлах (main и Ground)
						   //изменения inline переменной в одном месте распространятся по всему коду
	//inline void GoToPos(int x, int y) {
		//COORD coord = { x, y };
		//SetConsoleCursorPosition(stdscr, coord);
	//}

	class GameObject {
	public:
		virtual void Draw() = 0;
		virtual void ReactToBullet() = 0;
		virtual void Dead() = 0;
		virtual void Move(char direction) = 0;
		virtual void Shoot() = 0;
		virtual void gachi() = 0;
		virtual ~GameObject() = default;
		virtual void act(char key) = 0;
		virtual bool IsAlive() = 0;
		virtual void SetAmountOfSteps() = 0;
 	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
	};

	class Shelter : public GameObject {
	public:
		Shelter(int x, int y, int hp, bool hitbox, char amount_of_steps);
		void Draw() override;
		void ReactToBullet() override;
		void Dead() override;
		void Move(char direction) override;
		void Shoot() override;
		void gachi() override;
		~Shelter() = default;
		void act(char key) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
	};
	
	class Man : public GameObject {
	public:
		Man(int x, int y, int hp, bool hitbox, char amount_of_steps);
		void Draw() override;
		void ReactToBullet() override;
		void Dead() override;
		void Move(char direction) override;
		void Shoot() override;
		void gachi() override;
		~Man() = default;
		void act(char key) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
	};
	/*
	class Enemy : public GameObject {
	public:
		void Draw() override;
		void ReactToBullet() override;
		void Dead() override;
		void Move() override;
		void Shoot() override;
	private:
		int x;
		int y;
	};*/

	class Ground : public GameObject {
	public:
		Ground(int x, int y, int hp, bool hitbox, char amount_of_steps);
		void Draw() override;
		void ReactToBullet() override;
		void Dead() override;
		void Move(char direction) override;
		void Shoot() override;
		void gachi() override;
		~Ground() = default;
		void act(char key) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
	};

	class Bullet : public GameObject {
	public:
		Bullet(int x, int y, int hp, bool hitbox, char amount_of_steps);
		void Draw() override;
		void ReactToBullet() override;
		void Dead() override;
		void Move(char direction) override;
		void Shoot() override;
		void gachi() override;
		~Bullet() = default;
		void act(char key) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
	};

}


inline std::array<std::unique_ptr<GameObjects::GameObject>, Field_height* Field_width> Cells;

inline void CreateField() {
	for (int y = 0; y < Field_height; y++) {
		for (int x = 0; x < Field_width; x++) {
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
		}
	}
}

inline void PutShelters() {
	for (int y = 2; y <= 4; y++) {
		for (int x = 6; x <= 17; x++) {
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0);
		}
	}
	
	for (int y = 3; y <= 5; y++) {
		for (int x = 29; x <= 40; x++) {
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0);
		}
	}

	for (int y = 2; y <= 4; y++) {
		for (int x = 54; x <= 65; x++) {
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0);
		}
	}

	for (int y = 20; y <= 22; y++) {
		for (int x = 8; x <= 19; x++) {
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0);
		}
	}


	for (int y = 21; y <= 23; y++) {
		for (int x = 27; x <= 38; x++) {
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0);
		}
	}

	for (int y = 20; y <= 22; y++) {
		for (int x = 56; x <= 67; x++) {
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0);
		}
	}


}

inline void CreateMan() {
	Cells[23 * Field_width + 5] = std::make_unique<GameObjects::Man>(5, 23, 3, 1, 0);;
}