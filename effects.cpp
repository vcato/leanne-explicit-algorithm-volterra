#include <iostream>
void noeffect(double x)
{
   std::cout<<"In noeffect() x="<<x<<"\n";
   x += 1.0;
   std::cout<<"In noeffect() x="<<x<<"\n";
}
void someeffect(double& x)
{
   std::cout<<"In someeffect() x="<<x<<"\n";
   x += 1.0;
   std::cout<<"In someeffect() x="<<x<<"\n";
}

// Code makes a copy of the variable x and and sends the copy to the function
int main()
{
   double x = 2.0;
   noeffect(x);
   std::cout<<"In main() x="<<x<<"\n";

   someeffect(x);
   std::cout<<"In main() x="<<x<<"\n";
}

/*
In noeffect() x=2
In noeffect() x=3
In main() x=2
In someeffect() x=2
In someeffect() x=3
In main() x=3
*/