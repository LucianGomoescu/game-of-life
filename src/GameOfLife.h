#include <utility>
#include <vector>


using namespace std;

class GameOfLife {
public:
  GameOfLife(int numCols, int numRows,
             vector<pair<int, int>> const & initialAliveCells);

  void PrintGeneration();
  vector<vector<bool>> const & GetGeneration() const { return m_grid; }

private:
  void SetAliveCells(vector<pair<int, int>> const & alives);
  void KillAll();

  int m_generation;
  vector<vector<bool>> m_grid;
};
