#include <stdexcept>

template <bool first_player>
void init_game_state_templ(int (&game_state)[8][8])
{
    //Exception if game_state is not size 8x8
    if (sizeof(game_state) != sizeof(int[8][8])) {
        throw std::invalid_argument("game_state array is not 8x8");
    }


    if (first_player)
    {

        // second player
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 1)
                    game_state[i][j] = 2;

                if ((i + j) % 2 == 0)
                    game_state[i][j] = 0;
            }
        }

        // row 3 and 4
        for (int i = 3; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
                game_state[i][j] = 0;
        }

        // first player
        for (int i = 5; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 1)
                    game_state[i][j] = 1;

                if ((i + j) % 2 == 0)
                    game_state[i][j] = 0;
            }
        }
    }
    else
    {
        // first player
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 0)
                    game_state[i][j] = 1;

                if ((i + j) % 2 == 1)
                    game_state[i][j] = 0;
            }
        }

        // row 3 and 4
        for (int i = 3; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
                game_state[i][j] = 0;
        }

        // second player
        for (int i = 5; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 0)
                    game_state[i][j] = 2;

                if ((i + j) % 2 == 1)
                    game_state[i][j] = 0;
            }
        }
    }
}