#include "Test.h"

#include "GameOfLife.h"

#include <utility>
#include <vector>
#include <iostream>

TestStatus TestValidInitialisation::Run() {
  int nc = 10;
  int nr = 10;
  vector<pair<int, int>> alives = {{1, 1}, {1, 2}};
  GameOfLife game(nc, nr, alives);

  auto const &generation = game.GetGeneration();
  int rowNum = 0;
  for(auto &row : generation) {
    int colNum = 0;
    for(auto &&cell : row) {
      bool correctValue = false;
      for (auto const &alive : alives) {
        if (alive.first == colNum && alive.second == rowNum) {
          correctValue = true;
          break;
        }
      }
      if (cell != correctValue) { return TestStatus::Failed; }
      colNum++;
    }
    rowNum++;
  }
  return TestStatus::Passed;
}

TestStatus TestGenerationAdvancement::Run() {
  int numGenerationToPrint = 2;
  int nc = 10;
  int nr = 10;
  vector<pair<int, int>> alives = {{1, 1}, {1, 2}, {2, 1}, {2, 2},
                                   {0, 6}, {1, 6}, {2, 6}};
  GameOfLife game(nc, nr, alives);

  vector<vector<bool>> correct(nc, vector<bool>(nr, false));
  correct[1][1] = true;
  correct[1][2] = true;
  correct[2][1] = true;
  correct[2][2] = true;
  correct[5][1] = true;
  correct[6][1] = true;
  correct[7][1] = true;

  game.GoToGeneration(numGenerationToPrint);
  auto const &targetGeneration = game.GetGeneration();
  int i = 0;
  for (auto const &row: targetGeneration) {
    int j = 0;
    for (auto const &cell: row) {
      if (cell != correct[i][j]) { return TestStatus::Failed; }
      j++;
    }
    i++;
  }
  return TestStatus::Passed;
}
