#include <iostream>
using namespace std;

class firstfit
{
public:
    int mm[100], num_sub[100], mmsize, num, i, j, flag = 0;
    float internal = 0, external = 0;
    firstfit()
    {
        cout << "Enter main memory segements" << endl;
        cin >> mmsize;
        cout << "Enter sub processes" << endl;
        cin >> num;
        cout << "Enter main memory size" << endl;
        for (i = 0; i < mmsize; i++)
        {
            cin >> mm[i];
        }
        cout << "Enter the sub processes size" << endl;
        for (i = 0; i < num; i++)
        {
            cin >> num_sub[i];
        }
        fragments_i();
    }

    void fragments_i()
    {
        for (i = 0; i < num; i++)
        {
            flag = 0;
            for (j = 0; j < mmsize; j++)
            {
                if (num_sub[i] <= mm[j] && flag == 0) // Use <= instead of <
                {
                    internal = internal + mm[j] - num_sub[i];
                    mm[j] -= num_sub[i]; // Subtract sub process size from memory segment
                    num_sub[i] = 0;
                    flag = 1;
                    // Once allocated, move to the next sub process
                }
                cout << "Current i.f =" <<internal ;
            }
               cout << "Current i.f outside =" <<internal ;
        }

        for(i=0 ; i<num ; i++)
        {
            internal = internal + num_sub[i];
        }
        fragments_e();
    }

    void fragments_e()
    {
        int unusedSpace = 0;
        int allocatedSize = 0;

        for (int i = 0; i < mmsize; i++)
        {
            if (mm[i] == -1)
            {
                allocatedSize = 0;
                while (i < mmsize && mm[i] == -1)
                {
                    allocatedSize++;
                    i++;
                }

                if (i < mmsize && mm[i] != -1)
                {
                    unusedSpace += allocatedSize;
                }
            }
        }

        external = unusedSpace;
        
        cout << "Internal Fragmentation: " << internal << endl;
        cout << "External Fragmentation: " << external << endl;
    }
};

int main()
{
    firstfit a;

    return 0;
}