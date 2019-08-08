class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int i, j, sum;
		int row = board.size();
		//ÐÐ
		for (i = 0; i<row; i++)
		{
			sum = 0;
			for (j = 0; j<row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
			{
				return true;
			}
		}

		//ÁÐ
		for (i = 0; i<row; i++)
		{
			sum = 0;
			for (j = 0; j<row; j++)
			{
				sum += board[j][i];
			}
			if (sum == row)
			{
				return true;
			}
		}

		sum = 0;
		for (i = 0; i<row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
		{
			return true;
		}

		sum = 0;
		for (i = 0; i<row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
		{
			return true;
		}
		return false;
	}
};