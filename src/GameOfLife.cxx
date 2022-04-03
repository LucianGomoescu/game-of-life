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

void GameOfLife::GoToGeneration(int genNum) {
  int numGenerationsToPass = static_cast<int>(genNum - m_generation);
  for (int n = 0; n < numGenerationsToPass; ++n) {
    GoToNextGeneration();
  }
}

void GameOfLife::SetAliveCells(vector<pair<int, int>> const & alives) {
  KillAll();
  for(auto const & alive : alives) {
    m_grid[alive.second][alive.first] = true;
  }
}

  void GameOfLife::KillAll() {
    for(auto &row : m_grid) {
      for(auto &&cell : row) {
        cell = false;
      }
    }
  }

  void GameOfLife::GoToNextGeneration() {
    auto now = m_grid;
    int nrows = m_grid.size();
    int ncols = m_grid.begin()->size();

    auto newGeneration = m_grid;

    vector<int> offsets = {-1, 0, 1};
    int i = 0;
    for(auto &row : m_grid) {
      int j = 0;
      for(auto &&cell : row) {
        int count = 0;
        // count alive neighbours
        for (auto x : offsets) {
          for (auto y : offsets) {
            auto ii = i + x;
            auto jj = j + y;
            if (0 <= ii && 0 <= jj && ii < ncols && jj < nrows) {
              count += static_cast<int>(m_grid[ii][jj]);
            }
          }
        }
        count -= static_cast<int>(cell);
        // decide cell's state in the new generation
        if (cell == true && (count == 2 || count == 3)) { // survives
          newGeneration[i][j] = true;
        } else if (cell == false && count == 3){ // becomes alive
          newGeneration[i][j] = true;
        } else { // dies
          newGeneration[i][j] = false;
        }
        j++; // index of next cell
      }
      i++; // // index of next row of cells
    }

    m_grid = newGeneration; // update generation
  }
