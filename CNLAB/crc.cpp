#include <iostream>
#include <vector>
using namespace std;

vector<int> gen, rem;
int genl, frl;

// Function to calculate remainder
void calc_remainder(vector<int> &fr)
{
    for (int k = 0; k < frl; k++)
    {
        if (fr[k] == 1)
        {
            for (int i = 0; i < genl; i++)
            {
                rem[i] = fr[k + i] ^ gen[i];
            }
            for (int i = 0; i < genl; i++)
            {
                fr[k + i] = rem[i];
            }
        }
    }
}

int main()
{
    frl = 8;  // Frame length
    genl = 4; // Generator length

    vector<int> fr(frl), dupfr(frl + genl - 1), recfr(frl + genl - 1);

    // Input frame
    cout << "Enter frame: ";
    for (int i = 0; i < frl; i++)
    {
        cin >> fr[i];
        dupfr[i] = fr[i];
    }

    // Input generator
    gen.resize(genl);
    rem.resize(genl);
    cout << "Enter generator: ";
    for (int i = 0; i < genl; i++)
    {
        cin >> gen[i];
    }

    // Padding with zeros
    for (int i = frl; i < frl + genl - 1; i++)
    {
        dupfr[i] = 0;
    }

    // Calculate remainder for transmitted frame
    calc_remainder(dupfr);

    // Append remainder to received frame
    for (int i = 0; i < frl; i++)
    {
        recfr[i] = fr[i];
    }
    for (int i = 0; i < genl - 1; i++)
    {
        recfr[frl + i] = rem[i + 1];
    }

    // Calculate remainder for received frame
    calc_remainder(recfr);

    // Check if the received frame is correct
    bool valid = true;
    for (int i = 0; i < genl; i++)
    {
        if (rem[i] != 0)
        {
            valid = false;
            break;
        }
    }

    if (valid)
    {
        cout << "Frame received correctly" << endl;
    }
    else
    {
        cout << "The received frame is wrong" << endl;
    }

    return 0;
}
