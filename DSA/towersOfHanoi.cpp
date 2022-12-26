#include <iostream>
using namespace std;

void towerOfHanoi(int disks, char source, char aux, char destination)
{
    if(disks<1)
        return;
    towerOfHanoi(disks-1,source, destination, aux);
    cout<<"Move Disk "<<disks<<" from "<<source<<" to "<<destination<<endl;
    towerOfHanoi(disks-1,aux,source,destination);
}

int main()
{
    int number;
    cout<<"Enter the Number of Disks: ";
    cin>>number;
    cout<<endl;
    towerOfHanoi(number,'A','B','C');
    return 0;
}
