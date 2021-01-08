#include <fstream>
#include <vector>

namespace ohd {
class Ploter
{
 private:
  /* data */
 public:
  Ploter()  = default;
  ~Ploter() = default;

  // function
  void plotWithPlt(std::vector<int>& win_bureau_count, int n, int player_num);
};

}  // namespace ohd