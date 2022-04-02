#include "GameOfLife.h"

#include <iostream>

GameOfLife::GameOfLife(int numCols, int numRows,
           vector<pair<int, int>> const & initialAliveCells)
{
  m_generation = 1;
  m_grid = vector<vector<bool>>(numRows, vector<bool>(numCols, false));
  SetAliveCells(initialAliveCells);
}

void GameOfLife::PrintGeneration() {
  for(auto &row : m_grid) {
    for(auto &&cell : row) {
      cout<<(cell ? '*' : '.');
    }
    cout<<endl;
  }
}

void GameOfLife::SetAliveCells(vector<pair<int, int>> const & alives) {
  KillAll();
  for(auto const & alive : alives) {
    m_grid[alive.first][alive.second] = true;
  }
}

  void GameOfLife::KillAll() {
    for(auto &row : m_grid) {
      for(auto &&cell : row) {
        cell = false;
      }
    }
  }
