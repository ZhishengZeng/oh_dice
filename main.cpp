#include "Player.h"
#include <vector>
using namespace ohd;
int main()
{
    std::cout << "oh~ Dice!" << std::endl;

    // 游玩场次
    int n = 200000;

    int bureau_num = 0;

    // 胜场记录
    std::vector<int> win_bureau_count;
    win_bureau_count.resize(NUM_OF_PLAYER * PER_PLAYER_DICES + 1);
    while (n--)
    {
        bureau_num++;
        // 玩家就坐
        std::vector<Player> player_list;
        player_list.reserve(NUM_OF_PLAYER);
        for (size_t player_id = 0; player_id < NUM_OF_PLAYER; player_id++)
        {
            player_list.emplace_back((player_id + 1));
        }

        // 摇骰子并确认点数(并行)
#pragma omp parallel for
        for (size_t i = 0; i < NUM_OF_PLAYER; i++)
        {
            player_list[i].rollDices();
            player_list[i].checkSourceResults();
            player_list[i].checkVariantResults();
        }

        // 统计本局点数
        std::vector<int> bureau_points;
        bureau_points.resize(6);
        for (size_t i = 0; i < NUM_OF_PLAYER; i++)
        {
#if LOG
            player_list[i].printResult();
#endif
            std::vector<int> &num_of_variant = player_list[i].get_num_of_variant();
            for (size_t i = 1; i < 6; i++)
            {
                bureau_points[i] += num_of_variant[i];
            }
        }

        //统计胜场
        for (size_t i = 1; i <= (size_t)bureau_points[2]; i++)
        {
            win_bureau_count[i]++;
        }
#if LOG
        std::cout << "本局点数统计结果 : ";
        for (size_t i = 1; i < 6; i++)
        {
            std::cout << bureau_points[i] << "个" << (i + 1) << " ";
        }
        std::cout << std::endl;

        std::cout << "胜场统计(总场次 " << bureau_num << ") : " << std::endl;
        for (size_t i = 1; i <= (NUM_OF_PLAYER * PER_PLAYER_DICES + 1); i++)
        {
            std::cout << i << "个? 胜场几率 " << (win_bureau_count[i] / 1.0 / bureau_num * 100) << "%" << std::endl;
        }
#endif
    }

    std::cout << "胜场统计(总场次:" << bureau_num << " 玩家个数:" << NUM_OF_PLAYER << ") : " << std::endl;
    for (size_t i = 1; i <= (NUM_OF_PLAYER * PER_PLAYER_DICES + 1); i++)
    {
        std::cout << i << "个? 胜场几率 " << (win_bureau_count[i] / 1.0 / bureau_num * 100) << "%" << std::endl;
    }
    return 0;
}