class Solution {
public:
    int ans=0;
    bool d(int row,int col,vector<string> &v,int n){
        
        int x=col;
        int y=row;
         while (x >= 0) {
        if (v[y][x] == 'Q')
          return false;
        x--;
      }
        x=col;
        while(x>=0 && y>=0){
            if(v[y][x]=='Q') return false;
            x--;
            y--;
}
        x=col;
        y=row;
        while(x>=0 && y<n && y>=0){
            if(v[y][x]=='Q') return false;
            y++;
            x--;
}
        return true;
}
    void f(int col,vector<string> &v,int n){
        if(col==n) {
            ans++;
            return;
}
        for(int i=0;i<n;i++){
            if(d(i,col,v,n)==true){
                v[i][col]='Q';
                f(col+1,v,n);
                v[i][col]='.';
            }
}
}  
    int totalNQueens(int n) {
        vector<string> v(n);
         string s(n,'.');
            for(int i=0;i<n;i++) v[i]=s;
        f(0,v,n);
        return ans;
    }
};