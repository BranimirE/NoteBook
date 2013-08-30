class fraction {public:
   L n, d;
   fraction(L n,L d) {
      this->n=n;
      this->d=d;
      simplify();
   }
   void simplify(){
      L g=__gcd(abs(n),abs(d));
      n/=g;
      d/=g;
      if(n==0) d=1;
      if(n<1 && d<1) {
         n = abs(n);
         d = abs(d);
      } else if (n<1 || d<1) {
         n=abs(n);
         d=abs(d);
         n =-n;
      }
   }
   fraction inverse(){
      return fraction(d,n);
   }
   fraction() {
      n=0;
      d=1;
   }
   fraction operator/(const fraction& f) {
      fraction ret(n*f.d,d*f.n);
      return ret;
   }
   fraction operator*(const fraction& f) {
      fraction ret(n*f.n,d*f.d);
      return ret;
   }
   fraction operator+(const fraction& f) {
      fraction ret((n*f.d)+(f.n*d),d*f.d);
      return ret;
   }
   fraction operator*(L x) {
      fraction ret(x*n,d);
      return ret;
   }
   fraction operator-() {
      fraction ret(-n,d);
      return ret;
   }
   fraction operator-(const fraction& f) {
      fraction ret((n*f.d)-(f.n*d),d*f.d);
      return ret;
   }
   bool operator>(const fraction& f) {
      return abs(n*f.d)>abs(f.n*d);
   }

   fraction read(){
      char c;
      scanf("%lld",&n);
      d = 1;
      scanf("%c",&c);
      if(c=='/')
         scanf("%lld",&d);
   }
   void print(){
      if(d==1) {
         printf("%lld\n",n);
      } else {
         printf("%lld/%lld\n",n,d);
      }
   }
};

bool hasSol;
int rankA,rankAC;

const int MX = 59;
vector<fraction> mat[MX];
fraction x[MX];
int N,Y,X,nunk;

void gauss() {
   for(int p=1;p<=nunk;p++) {
      int maxR=p;
      for(int y=p+1;y<=Y;y++)
         if(mat[y][p] > mat[maxR][p])
            maxR=y;
      swap(mat[p],mat[maxR]);

      if(mat[p][p].n == 0)
         continue;

      fraction t = mat[p][p].inverse();
      for(int i=1;i <= X;i++)
         mat[p][i] = mat[p][i] * t;
      for(int y=p+1;y<=Y;y++){
         t = -mat[y][p];
         for(int j=1;j <= X;j++) {
            mat[y][j] = mat[y][j] + (t*mat[p][j]);
         }
      }
   }
}

void rank() {
   rankA=rankAC=Y;
   bool allZeroes;
   for(int y=1;y<=Y;y++) {
      allZeroes=true;
      for(int j=1;allZeroes and j <= nunk;j++)
         if(mat[y][j].n != 0)
            allZeroes=false;

      if(allZeroes) {
         rankA--;
         if(mat[y][nunk+1].n == 0)
            rankAC--;
      }
   }
}

void resuelva(){
   L num,den;
   char c;

   scanf("%d %d",&nunk,&Y);
   X = nunk + 1;
   for(int y=1;y <= Y;y++)
      for(int x=1;x <= X;x++)
         mat[y][x].read();

   hasSol=true;
   gauss();
   rank();

   if(rankAC != rankA){
      printf("No Solution.\n");
   } else {
      if(rankAC<nunk)
         printf("Infinitely many solutions containing %d arbitrary constants.\n",nunk-rankAC);
      else{
         for(int p=nunk;p>=1;--p) {
            fraction s(0,1);
            for(int k=p+1;k<=nunk;++k)
               s = s + (x[k]*mat[p][k]);
            x[p] = (mat[p][X]-s) / mat[p][p];
         }
         for(int y=1;y<=nunk;y++)
            printf("x[%d] = ",y),x[y].print();
      }
   }
}
int main() {
   int nc;
   bool first=true;

   for(int i=0;i<MX;i++)
      mat[i].resize(MX);

   while(scanf("%d",&N) and N>0) {
      if(first == false) printf("\n");first = false;
      printf("Solution for Matrix System # %d\n",N);
      resuelva();
   }
}
