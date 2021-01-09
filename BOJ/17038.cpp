 #include<iostream>
 #include<string>
 using namespace std;
 
 int n, m;
 int same[100010];
 int dif[100010];
 
 int find(int a, int *parents)
 {
     if (parents[a] == a) return a;
     else return parents[a] = find(parents[a], parents);
 }
 
 void union_(int a, int b, int *parents)
 {
     a = find(a, parents);
     b = find(b, parents);
 
     parents[b] = a;
 }
 
 int main()
 {
     int i;
     string a;
     int b, c;
     int cnt = 0;
 
     for (i = 0; i < 100010; i++)
     {
         same[i] = i;
         dif[i] = i;
     }
 
     cin >> n >> m;
     for (i = 0; i < m; i++)
     {
         cin >> a >> b >> c;
         if (a[0] == 'S')
         {
             if (find(b, dif) == find(c, dif))
             {
                 cout << 0;
                 return 0;
             }
             else if (find(b, same) == find(c, same)) cnt++;
             else union_(b, c, same);
         }
         else
         {
             if (find(b, same) == find(c, same))
             {
                cout << 0;
                 return 0;
             }
             else if (find(b, dif) == find(c, dif)) cnt++;
             else union_(b, c, dif);
         }
     }
 
     cout << 1;
     for (i = 0; i < n - (m - cnt); i++)
     {
         cout << 0;
     }
 }