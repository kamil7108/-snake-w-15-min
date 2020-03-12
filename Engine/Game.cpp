/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek({ 2,2 }),
	delta_loc({ 0,1 })
{
	for (int i = 0; i < 5; i++) {
		
		std::uniform_int_distribution<int> xDistr(0, brd.GetGridWeight()-1);
		std::uniform_int_distribution<int> yDistr(0, brd.GetGridHeight()-1);
	
		Location loc = { xDistr(rng) , yDistr(rng) };
		points[i].setNewLocation(loc);
		
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP) && delta_loc.x !=0&&delta_loc.y!=1) { delta_loc = { 0,-1 }; }
	if (wnd.kbd.KeyIsPressed(VK_DOWN) && delta_loc.x != 0 && delta_loc.y != -1) { delta_loc = { 0,1 }; }
	if (wnd.kbd.KeyIsPressed(VK_LEFT) && delta_loc.x != 1 && delta_loc.y != 0) { delta_loc = { -1,0 }; }
	if (wnd.kbd.KeyIsPressed(VK_RIGHT) && delta_loc.x != -1 && delta_loc.y != 0) { delta_loc = { 1,0 }; }
	if (snek.EatYourself()||snek.HitTheBand(delta_loc,brd)) {
		delta_loc = { 0,0 };
		brd.DrawGameOver();
		finishgame = true;
		
	}
	if (finishgame == false) {
		snek.MoveBy(delta_loc);

		for (int i = 0; i < 5; i++) {
			if (snek.ScoringPoint(points[i])) {
				snek.Grow();
				std::uniform_int_distribution<int> xDistr(0, brd.GetGridWeight() - 1);
				std::uniform_int_distribution<int> yDistr(0, brd.GetGridHeight() - 1);
				Location loc = { xDistr(rng) , yDistr(rng) };
				points[i].setNewLocation(loc);
			}
		}
		Sleep(30);
	}
	
}

void Game::ComposeFrame()
{
	for (int i = 0; i < 5; i++)points[i].DrawPoint(brd);
	snek.DrawSnake(brd);

}
