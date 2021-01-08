#include "GameConfig.h"
namespace ohd {
class Player
{
 private:
  int              _id         = 0;
  int              _round_dice = 0;
  std::vector<int> _dices;
  std::vector<int> _num_of_source;
  std::vector<int> _num_of_variant;

 public:
  Player(size_t id) : _id(id)
  {
    _dices.resize(PER_PLAYER_DICES);
    _num_of_source.resize(6);
    _num_of_variant.resize(6);
  }
  ~Player() = default;

  // getter
  std::vector<int>& get_num_of_variant() { return _num_of_variant; }
  // setter
  void set_idx(const int id) { _id = id; }
  // function
  void clearRecord();
  void rollDices();
  void checkSourceResults();
  void checkVariantResults();
  void printResult();
};
}  // namespace ohd
