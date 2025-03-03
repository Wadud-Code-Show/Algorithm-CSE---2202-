#include <iostream>
using namespace std;
void hanoi(int n, char from, char to, char via) {
   if(n == 1){
      cout<<"Move disk 1 from "<<from<<" to "<<to<<endl;
   }
   else{
      hanoi(n-1, from, via, to);
      cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
      hanoi(n-1, via, to, from);
   }
}
int main() {
   int n ;
   cin>>n;
   char from = 'A';
   char to = 'B';
   char via = 'C';
   //calling hanoi() method
   hanoi(n, from , to, via);
}