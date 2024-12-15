#pragma once
#include <Windows.h>
#include <array>
#include <memory>
#include <vector>
#include <string>


#include "_deps/pdcurses-src/curses.h"

const int Field_width = 70;
const int Field_height = 25;


namespace GameObjects {
	class Context;
	class Statistic;

	class GameObject {
	public:
		virtual void Draw() = 0;
		virtual void ReactToBullet(Context &context, Statistic &statistic) = 0;
		virtual void Dead(Context &context, Statistic &statistic) = 0;
		virtual void Move(char direction, Context &context, Statistic &statistic) = 0;
		virtual void Shoot(Context &context, Statistic &statistic) = 0;
		virtual void gachi(Context &context, Statistic &statistic) = 0;
		virtual ~GameObject() = default;
		virtual void act(char key, Context &context, Statistic &statistic) = 0;
		virtual bool IsAlive() = 0;
		virtual void SetAmountOfSteps() = 0;
 	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
		bool is_a_good_guy;
	};

	class Shelter : public GameObject {
	public:
		Shelter(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy);
		void Draw() override;
		void ReactToBullet(Context &context, Statistic &statistic) override;
		void Dead(Context &context, Statistic &statistic) override;
		void Move(char direction, Context &context, Statistic &statistic) override;
		void Shoot(Context &context, Statistic &statistic) override;
		void gachi(Context &context, Statistic &statistic) override;
		~Shelter() = default;
		void act(char key, Context &context, Statistic &statistic) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
		bool is_a_good_guy;
	};
	
	class Man : public GameObject {
	public:
		Man(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy);
		void Draw() override;
		void ReactToBullet(Context &context, Statistic &statistic) override;
		void Dead(Context &context, Statistic &statistic) override;
		void Move(char direction, Context &context, Statistic &statistic) override;
		void Shoot(Context &context, Statistic &statistic) override;
		void gachi(Context &context, Statistic &statistic) override;
		~Man() = default;
		void act(char key, Context &context, Statistic &statistic) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
		bool is_a_good_guy;
	};
	
	class Enemy : public GameObject {
	public:
		Enemy(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy);
		void Draw() override;
		void ReactToBullet(Context &context, Statistic &statistic) override;
		void Dead(Context &context, Statistic &statistic) override;
		void Move(char key, Context &context, Statistic &statistic) override;
		void Shoot(Context &context, Statistic &statistic) override;
		void gachi(Context &context, Statistic &statistic) override;
		~Enemy() = default;
		void act(char key, Context &context, Statistic &statistic) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
		bool is_a_good_guy;
	};

	class Ground : public GameObject {
	public:
		Ground(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy);
		void Draw() override;
		void ReactToBullet(Context &context, Statistic &statistic) override;
		void Dead(Context &context, Statistic &statistic) override;
		void Move(char direction, Context &context, Statistic &statistic) override;
		void Shoot(Context &context, Statistic &statistic) override;
		void gachi(Context &context, Statistic &statistic) override;
		~Ground() = default;
		void act(char key, Context &context, Statistic &statistic) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
		bool is_a_good_guy;
	};

	class Bullet : public GameObject {
	public:
		Bullet(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy);
		void Draw() override;
		void ReactToBullet(Context &context, Statistic &statistic) override;
		void Dead(Context &context, Statistic &statistic) override;
		void Move(char direction, Context &context, Statistic &statistic) override;
		void Shoot(Context &context, Statistic &statistic) override;
		void gachi(Context &context, Statistic &statistic) override;
		~Bullet() = default;
		void act(char key, Context &context, Statistic &statistic) override;
		bool IsAlive() override;
		void SetAmountOfSteps() override;
	private:
		int x;
		int y;
		int hp;
		bool hitbox;
		char amount_of_steps;
		bool is_a_good_guy;
	};

	class Context {
	public:
		Context() = default;
		~Context() = default;
		std::array<std::unique_ptr<GameObjects::GameObject>, Field_height* Field_width>& GetCells() {
			return Cells;
		}
		std::unique_ptr<GameObjects::GameObject>& GetCell(int x, int y) {
			return Cells[y * Field_width + x];
		}

	private:
		std::array<std::unique_ptr<GameObjects::GameObject>, Field_height* Field_width> Cells;
	};

	class Statistic {
	public:

		Statistic() = default;

		~Statistic() = default;

		std::vector<int> Coordinats_of_man{ 0, 0 };

		bool Man_alive = true;

		int Amount_of_alive_enemy = 2;

		int Amount_of_bullets = 0;

		int Amount_of_injured_people = 0;

		int Choosed_one = 1;

		int Win = 1;

		void Display_Score() {
			wmove(stdscr, Field_height / 4, Field_width + 12);
			printw("SQUAD LIST:");
			wmove(stdscr, Field_height / 4 + 1, Field_width + 7);
			printw("ALLY REMAIN: ");
			if (Man_alive)
				printw("%d ", 1);
			else
				printw("%d ", 0);
			printw("ENEMY TEAM REMAIN : ");
			printw("%d", Amount_of_alive_enemy);
		}
	};
}