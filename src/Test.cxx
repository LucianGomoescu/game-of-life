#include "Test.h"

#include "GameOfLife.h"

#include <utility>
#include <vector>

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
        if (alive.first == rowNum && alive.second == colNum) {
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
