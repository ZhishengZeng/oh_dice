#include "Player.h"
namespace ohd
{
    void Player::rollDices()
    {
        // 掷骰子
        for (size_t i = 0; i < PER_PLAYER_DICES; i++)
        {
            _dices[i] = (rd() % 6 + 1);
        }
    }

    void Player::checkSourceResults()
    {
        // 确认原始结果
        for (size_t i = 0; i < PER_PLAYER_DICES; i++)
        {
            _num_of_source[_dices[i] - 1]++;
        }
    }

    void Player::checkVariantResults()
    {
        // 确认变点结果
        // 点数为1的统计结果
        int num_of_one = _num_of_source[0];
        for (size_t i = 1; i < 6; i++)
        {
            // 点数一可以变为任何数
            _num_of_variant[i] = (_num_of_source[i] + num_of_one);
            // 判断是否围骰
            if (_num_of_variant[i] == 5)
            {
                _round_dice = 1;
                _num_of_variant[i] = 6;
            }
        }
    }

    void Player::printResult()
    {
        if (_round_dice == 1)
        {
            std::cout << "******" << _id << "号玩家 围骰!!******" << std::endl;
        }

        std::cout << _id << "号玩家 掷骰结果 : ";
        for (size_t i = 0; i < PER_PLAYER_DICES; i++)
        {
            std::cout << _dices[i] << " ";
        }
        std::cout << std::endl;

        std::cout << _id << "号玩家 原始统计结果 : ";
        for (size_t i = 0; i < 6; i++)
        {
            std::cout << _num_of_source[i] << "个" << (i + 1) << " ";
        }
        std::cout << std::endl;

        std::cout << _id << "号玩家 变点统计结果 : ";
        for (size_t i = 0; i < 6; i++)
        {
            std::cout << _num_of_variant[i] << "个" << (i + 1) << " ";
        }
        std::cout << std::endl;
    }
} // namespace ohd
