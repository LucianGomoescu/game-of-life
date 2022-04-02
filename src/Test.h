#include <string>

enum class TestStatus{Passed, Failed};

using namespace std;

class ITest {
public:
  virtual TestStatus Run() = 0;
  virtual string GetName() = 0;
};

class TestValidInitialisation : public ITest {
public:
  string GetName() override { return "valid initialisation"; }
  TestStatus Run() override;
};
