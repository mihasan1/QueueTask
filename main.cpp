#include <iostream>
#include <queue>

/*
Task 1 - A program that adds to the queue X the size of N, the elements of the queue Y the size of K after the middle element
Task 2 - A program that removes the K-number of elements after the middle element of queue X of size N
*/

using namespace std;

int main()
{
system("chcp 1251");
short int choice=1;
while(choice!=0)
    {
    cout << "\n1 - Task 1 | 2 - Task 2 | 0 - Exit \n";
    cin >> choice;
switch(choice)
    {
    case 1:
        {
        int a,n,k;
        queue <int> x;
        queue <int> y;
        queue <int> z;
        cout << "Enter the length of X queue: ";
        cin >> n;
        int l=n/2;
        cout << "Enter the elements of X queue\n";
            for(int i=1; i<=n; i++)
            {
                cout << "["<<i<<"]:";
                cin >> a;
                x.push(a);
            }
        cout << "Enter the length of Y queue: ";
        cin >> k;
        cout << "Enter the elements of Y queue\n";
            for(int i=1; i<=k; i++)
            {
                cout << "["<<i<<"]:";
                cin >> a;
                y.push(a);
            }

            for(int i=1; i<=l; i++)
            {
                z.push(x.front());
                if(!x.empty())
                    x.pop();
            }

            for(int i=l+1; i<=l+k; i++)
            {
                z.push(y.front());
                if(!y.empty())
                    y.pop();
            }

            for(int i=l+k+1; i<=n+k; i++)
            {
                z.push(x.front());
                if(!x.empty())
                    x.pop();
            }

            cout << "Result\n";
            for(int i=1; i<=n+k; i++)
            {
                cout << z.front() << " ";
                if(!z.empty())
                    z.pop();
            }
        }break;
    case 2:
        {
        int a,n,k;
        queue <int> x;
        queue <int> y;
            cout << "Enter the length of X queue: ";
            cin >> n;
            int l=n/2;
            cout << "Enter the elements of X queue\n";
            for(int i=1; i<=n; i++)
            {
                cout << "["<<i<<"]:";
                cin >> a;
                x.push(a);
            }
            cout << "Enter the count of elements after L to be deleted: ";
            cin >> k;
            if(!(0<=l+k && l+k <=n)){cout << "Error!  The data entered does not satisfy the condition 0<=L+k<=N"; break;}
            for(int i=1; i<=l; i++)
            {
                y.push(x.front());
                if(!x.empty())
                    x.pop();
            }

            for(int i=l+1; i<=l+k; i++)
            {
                if(!x.empty())
                    x.pop();
            }

            for(int i=l+k+1; i<=n; i++)
            {
                y.push(x.front());
                if(!x.empty())
                    x.pop();
            }

            cout << "Result\n";
            for(int i=1; i<=n-k; i++)
            {
                cout << y.front() << " ";
                if(!y.empty())
                    y.pop();
            }
        }break;
    case 0:
        {
         cout << "Exit!"; return 0;
        }
    default:
        cout << "Error! Enter "1" or "2" or "0"\n";
        break;
    }
}
    return 0;
}
