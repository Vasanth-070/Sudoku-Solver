#include<Bits/stdc++.h>
using namespace std;
 void printGrid(vector<vector<char>>grid) ;
bool findunassigned(vector<vector<char>>&board,int &row, int &col)
    {
      int n{static_cast<int>(board.size())};
       for(row=0;row<n;row++)
       {
           for(col=0;col<n;col++)
           {
               if(board[row][col]=='.')
                   return true;
           }
       }
       return false;
    }
    bool usedinrow(vector<vector<char>>&board,int row,int num)
    {int n{static_cast<int>(board.size())};
     char numm{static_cast<char>(num+48)};
        for(int col=0;col<n;col++)
        {
            if(board[row][col]==numm)
                return true;
        }
     return false;
            
    }
    bool usedincol(vector<vector<char>>&board,int col,int num)
    {
        int n{static_cast<int>(board.size())};
        char numm{static_cast<char>(num+48)};
        for(int row=0;row<n;row++)
                if(board[row][col]==numm)
                    return true;
        return false;
    }
    bool usedinbox(vector<vector<char>>&board,int box1strow,int box1stcol,int num)
    {
        char numm{static_cast<char>(num+48)};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[box1strow+i][box1stcol+j]==numm)
                    return true;
            }
        }
        return false;
    }
    bool issafe(vector<vector<char>>&board,int row,int col,int num)
    {
        return (!usedinrow(board,row,num))&&!usedincol(board,col,num)&&!usedinbox(board,row-row%3,col-col%3,num)&&board[row][col]=='.';
    }
    bool solveSudoku(vector<vector<char>>& board) {
        int row{0},col{0};
        static int count{1};
        if(count==1)
        {
            printGrid(board);
            cout<<"***************************************************"<<endl;
            count++;
        }
        if(!findunassigned(board,row,col))
            return true;
        
        for(int num=1;num<=9;num++)
        {
            if(issafe(board,row,col,num))
            {char t{static_cast<char>(num+48)};
                board[row][col]=t;
                
             if(solveSudoku(board))
            return true;
             else
            {    board[row][col]='.';}
            }
        }
        return false;
        }
        void printGrid(vector<vector<char>>grid) 
{ 
    int N{static_cast<int>(grid.size())};
    for (int row = 0; row < N; row++) { 
        for (int col = 0; col < N; col++) 
          {
              cout << grid[row][col] << " ";
             if(col%3==2)
             cout<<"|"; 
        }
        if(row%3==2)
            cout<<endl<<"_____________________"<<endl;
            else 
                cout<<endl;
    } 
} 
int main()
{
    vector<char>r1{'.','.','9',  '.','4','.',   '.','.','.'};
       vector<char>r2{'.','.','.',   '.','.','5',   '3','1','.'};
       vector<char>r3{'.','6','1',   '.','.','8',   '.','5','.'};
       vector<char>r4{'.','.','5',   '4','.','.',   '2','.','3'};
       vector<char>r5{'.','1','.',   '.','.','7',   '.','.','8'};
       vector<char>r6{'.','8','.',   '.','.','.',   '7','6','.'};
       vector<char>r7{'3','.','6',   '.','1','9',   '4','.','.'};
       vector<char>r8{'7','.','.',   '.','.','.',   '.','.','.'};
       vector<char>r9{'.','.','4',   '.','5','.',   '6','2','7'};
       vector<vector<char>>q{r1,r2,r3,r4,r5,r6,r7,r8,r9};
    cout<<"Default Input:"<<endl;
    printGrid(q);
    char choice;
    cout<<"Want to use default input or wanna try custom input?"<<endl;
    cout<<endl;
    cout<<"d--Default Input"<<endl;
    cout<<"c--Custom Input"<<endl;
    cout<<"Please select your choice from above:) :";
    cin>>choice;
    if(choice=='d'||choice=='D')
    {
       
       if(solveSudoku(q))
          {  cout<<"Completely solved sudoku:\n";
    printGrid(q);}
       else
           cout<<"Invalid Sudoku input..!"<<endl;
    }
    else if(choice=='c'||choice=='C')
    {
        vector<vector<char>>p;
    cout<<"Enter Custom Input below:"<<endl;
   for(int i=0;i<9;i++)
   {
       vector<char>temp;
       for(int j=0;j<9;j++)
       {
           char input;
           cout<<"Enter element ["<<i+1<<","<<j+1<<"]:";cin>>input;
           temp.push_back(input);
       }
       p.push_back(temp);
   }
   if(solveSudoku(p))
   {
       cout<<"Completely solved sudoku:\n";
       printGrid(p);
   }
       else
           cout<<"Invalid Sudoku input..!"<<endl;
    }
    else
     {   cout<<"Invalid choice input!!!"<<endl;}
    
	return 0;
}
