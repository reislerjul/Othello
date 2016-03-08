#include "player.h"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /* 
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
     player_side = side;
	 if (player_side == WHITE)
	 {
		 opponent_side = BLACK;
		 
	 }
	 else 
	 {
		 opponent_side = WHITE; 
	 }

}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) 
{
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 
     int score = -10000;
     Move * best_move = NULL;
	 if (opponentsMove != NULL)
	 {
		 othello_board.doMove(opponentsMove, opponent_side);
	 }
	 if (othello_board.hasMoves(player_side))
	 {
		 for (int i = 0; i < 8; i++)
		 {
			 for (int j = 0; j < 8; j++)
			 {
				 Move * move = new Move (i, j);
				 if (othello_board.checkMove(move, player_side))
				 {
					 Board * test_board = othello_board.copy();
					 test_board -> doMove(move, player_side);
					 int temp_score = test_board -> count(player_side) - test_board -> count(opponent_side);
					 if ((i == 0 && j == 0) || (i == 7 && j == 0) || (i == 0 && j == 7) \
					 || (i == 7 && j == 7))
					 {
						 temp_score *= 3;
					 }
					 if ((i == 0 && j == 1) || (i == 1 && j == 0 )|| (i == 1 && j == 1) \
					 || (i == 6 && j == 0) || (i == 6 && j == 1 )|| (i == 7 && j == 1 )\
					 || (i == 0 && j == 6) || (i ==1 && j == 6 )|| (i == 1 && j == 7) \
					 || (i == 6 && j == 6) || (i == 6 && j == 7 )|| (i == 7 && j == 6))
					 {
						 temp_score *= -3;
					 }
					 if (temp_score > score)
					 {
						 score = temp_score;
						 if (best_move != NULL)
						 {
							 delete best_move;
						 }
						 best_move = move;
					 }
					 
					delete test_board;
					 
				 }
			 }
		}
		othello_board.doMove(best_move, player_side);
		return best_move;
		 
	 }
	 return NULL;
}





