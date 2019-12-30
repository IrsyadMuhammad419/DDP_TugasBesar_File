/* -----------------------------------------------
Program 		:	Minimax.c
Deskripsi		: 	Modul untuk mencari kemungkinan pergerakan komputer yang memungkinkan dan baik untuk komputer menentukan pergerakan komputer dengan 
Author 			:	Github Matthew Steel
Versi/tanggal	: 	29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

int minimax(int board[10], int player) {
//author	: Github: Matthew Steel, 2009

// Modul untuk mencari kemungkinan pergerakan komputer yang memungkinkan dan baik untuk komputermenentukan pergerakan komputer dengan menelurusipergerakan komputer
//board[10]	: parameter input bertipe integer dengan passing parameter passing by value
//player	: parameter input bertipe integer dengan passing parameter passing by valuepassing 

    //How is the position like for player (their turn) on board?
    int winner = CekMenang(board);
    if(winner != 0) return winner*player;

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    for(i = 1; i < 10; ++i) {//For all moves,
        if(board[i] == 0) {//If legal,
            board[i] = player;//Try the move
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }//Pick the one that's worst for the opponent
            board[i] = 0;//Reset board after try
        }
    }
    if(move == -1) return 0;
    return score;
}
