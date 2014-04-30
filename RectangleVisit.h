const int N = 300;
class Demo
{
	int matrix[N][N];
	bool flag[N][N];
	Demo(int matrix[][])
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				this.matrix[i][j] = matrix[i][j];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; i < N; j++)
			{
				flag[i][j] = true;
			}
		}
	}
    
	void search()
	{
		int count = 0;
		int row = 0;
		int column = 0;
		bool ans = false;
		while (1)
		{
			if (Right(count, row, column)) break;
			if (Down(count, row, column)) break;
			if (Left(count, row, column)) break;
			if (Up(count, row, column)) break;
		}
	}

	bool Right(int &count, int &row, int &column) 
	{
			while ((flag[row][column+1]) && (column < N-1))
			{
				flag[row][column+1] = false;
				count++; 
				column++;		
				cout << matrix[row][column] << endl;
				if (count == n * n - 1) return true;
			}
			return false;
	} 
	bool Down(int &count, int &row, int &column)
	{
			while ((flag[row+1][column]) && (row < N-1))
			{
				flag[row+1][column] = false;
				count++;
				row++;
				cout << matrix[row][column] << endl;
				if (count == n * n - 1) return true;
			}
			return false;
	}
	bool Left(int &count, int &row, int &column) 
	{		
			while ((flag[row][column-1]) && (column >= 0))
			{
				flag[row][column-1] = false;
				count++;
				column--;
				cout << matrix[row][column] << endl;
				if (count == n * n - 1) return true;
			}
			return false;
	} 
	bool Up(int &count, int &row, int &column)
	{

			while ((flag[row-1][column]) && (row >= 0))
			{
				flag[row-1][column] = false;
				count++;
				row--;
				cout << matrix[row][column] << endl;
				if (count == n * n - 1) return true;
			}
			return false;
	}
}
