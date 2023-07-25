#include "Chess.h"
#include "Board.h"

// Constructor
Chess::Chess(const string& start)
	: m_boardString(start), m_codeResponse(-1)
{
	setFrames();
	setPieces();
}

// Clear the screen (ASCII code for "cls")
void Chess::clear() const
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

// create the GUI - ASCII art
void Chess::setFrames()
{
	// set all to ' ' (space bar ascii value 32) instead of 0  
	{
		for (size_t row = 0; row < _SIZE; ++row)
			for (size_t col = 0; col < _SIZE; ++col)
				m_board[row][col] = 32;
	}
	// set out frame
	{
		m_board[0][0] = 201;  m_board[0][20] = 187;
		m_board[20][0] = 200; m_board[20][20] = 188;

		for (size_t i = 1; i < 20; ++i)
		{
			m_board[0][i] = 205;
			m_board[20][i] = 205;
			m_board[i][0] = 186;
			m_board[i][20] = 186;
		}
	}

	// set in side frame 
	{
		m_board[2][2] = 218;  m_board[2][18] = 191;
		m_board[18][2] = 192; m_board[18][18] = 217;

		for (size_t i = 4; i < 17; i += 2)
		{
			m_board[2][i] = 194;
			m_board[18][i] = 193;
			m_board[i][2] = 195;
			m_board[i][18] = 180;
		}

		for (size_t i = 2; i < 19; i += 2)
			for (size_t j = 3; j < 19; j += 2)
				m_board[i][j] = 196;

		for (size_t i = 3; i < 18; i += 2)
			for (size_t j = 2; j < 19; j += 2)
				m_board[i][j] = 179;

		for (size_t i = 4; i < 17; i += 2)
			for (size_t j = 4; j < 17; j += 2)
				m_board[i][j] = 197;

		for (size_t i = 4; i < 17; i += 2)
			m_board[2][i] = 194;
		for (size_t i = 4; i < 17; i += 2)
			m_board[18][i] = 193;
		for (size_t i = 4; i < 17; i += 2)
			m_board[i][2] = 195;
		for (size_t i = 4; i < 17; i += 2)
			m_board[i][18] = 180;
	}

	// set nums and letters 
	{
		// nums 
		for (size_t i = 3, t = 0; i < 19; i += 2, ++t)
			m_board[1][i] = m_board[19][i] = ('1' + t);
		// letters 
		for (size_t i = 3, t = 0; i < 19; i += 2, ++t)
			m_board[i][1] = m_board[i][19] = ('A' + t);
	}
}

// Put the pieces from the boardString 
void Chess::setPieces()
{
	for (size_t row = 0, t = 0; row < 8; ++row)
		for (size_t col = 0; col < 8; ++col, ++t)
			m_board[(3 + (row * 2))][(3 + (col * 2))] = ((m_boardString[t] == '#') ? 32 : m_boardString[t]);
}

// Print only the board to the screen
void Chess::show() const
{
	for (size_t row = 0; row < _SIZE; ++row)
	{
		for (size_t col = 0; col < _SIZE; ++col)
			cout << m_board[row][col];
		cout << endl;
	}
}

// Clear the screen and print the board and the relevant msg
void Chess::displayBoard() const
{
	clear();
	show();
	cout << m_msg << m_errorMsg;

}

// Print the player who is currently making a move before getting input
void Chess::showAskInput() const
{
	if (m_turn)
		cout << "Player 1 (White - Capital letters) >> ";
	else
		cout << "Player 2 (Black - Small letters)   >> ";
}

// Check if the source and destination are the same
bool Chess::isSame() const
{
	return ((m_input[0] == m_input[2]) && (m_input[1] == m_input[3]));
}

// Check if the input is locations on the board
bool Chess::isValid() const
{
	return ((('A' <= m_input[0]) && (m_input[0] <= 'H')) || (('a' <= m_input[0]) && (m_input[0] <= 'h')) &&
		(('1' <= m_input[1]) && (m_input[1] <= '8')) &&
		(('A' <= m_input[2]) && (m_input[2] <= 'H')) || (('a' <= m_input[2]) && (m_input[2] <= 'h')) &&
		(('1' <= m_input[3]) && (m_input[3] <= '8')));
}

// Check if the input is "exit" or "quit"  
bool Chess::isExit() const
{
	return ((m_input == "exit") || (m_input == "quit") || (m_input == "EXIT") || (m_input == "QUIT"));
}

// Execute the movement on the board 
void Chess::execute()
{
	int src_row = (m_input[0] - 'a');
	int src_col = (m_input[1] - '1');
	char pieceInSource = m_boardString[(src_row * 8) + src_col];
	m_boardString[(src_row * 8) + src_col] = '#';

	int dest_row = (m_input[2] - 'a');
	int dest_col = (m_input[3] - '1');
	m_boardString[(dest_row * 8) + dest_col] = pieceInSource;

	setPieces();
}

// Check the response code and switch the turn if needed 
void Chess::doTurn()
{
	m_errorMsg = "\n";
	switch (m_codeResponse)
	{
	case 11:
	{
		m_msg = "There is no piece at the source.\n";
		break;
	}
	case 12:
	{
		m_msg = "The piece in the source belongs to your opponent.\n";
		break;
	}
	case 13:
	{
		m_msg = "There is one of your pieces at the destination.\n";
		break;
	}
	case 21:
	{
		m_msg = "Illegal movement of that piece.\n";
		break;
	}
	case 31:
	{
		m_msg = "This movement will cause you checkmate.\n";
		break;
	}
	case 41:
	{
		execute();
		m_turn = !m_turn;
		m_msg = "The last movement was legal and caused a check.\n";
		break;
	}
	case 42:
	{
		execute();
		m_turn = !m_turn;
		m_msg = "The last movement was legal.\n";
		break;
	}
	}
}

// Get the source and destination 
string Chess::getInput()
{
	static bool isFirst = true;

	if (isFirst)
		isFirst = false;
	else
		doTurn();

	displayBoard();
	showAskInput();

	cin >> m_input;
	if (isExit())
		return "exit";
	while (!isValid() || isSame())
	{
		if (!isValid())
			m_errorMsg = "Invalid input!\n";
		else
			m_errorMsg = "The source and the destination are the same!\n";
		displayBoard();
		showAskInput();
		cin >> m_input;
		if (isExit())
			return "exit";
	}

	if (m_input != "exit")
	{
		if (('A' <= m_input[0]) && (m_input[0] <= 'H'))
			m_input[0] = (m_input[0] - 'A' + 'a');
		if (('A' <= m_input[2]) && (m_input[2] <= 'H'))
			m_input[2] = (m_input[2] - 'A' + 'a');
	}

	return m_input;
}

void Chess::setCodeResponse(int codeResponse)
{
	if (((11 <= codeResponse) && (codeResponse <= 13)) ||
		((21 == codeResponse) || (codeResponse == 31)) ||
		((41 == codeResponse) || (codeResponse == 42)))
		m_codeResponse = codeResponse;
}
