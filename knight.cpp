#include "knight.h"
#define MAX 100
#define MAX2 10
int knight[5];
int event[MAX];
int count{ 0 };
string line3;
string fileline3[MAX];
int checkTiny;
int MaxHP;
int levelBeforFrog;
int checkFrog;
int checkAsclepius;
int checkArthur;
int checkLancelot;
int checkMerlin;
bool is_fibonacci(int N)
{
    int f0(1);
    int f1(1);
    int fN(0);

    if (N < 1)
        return false;

    if (N == 1)
        return true;

    while (fN <= N)
    {
        fN = f0 + f1;
        f0 = f1;
        f1 = fN;
        if (fN == N)
            return true;
    }
    return false;
}
bool LaSoNguyenTo(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void docfile(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown)
{
    fstream input;
    input.open(file_input, ios::in);

    if (input.is_open())
    {
        input >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
        int x;
        while (input >> x) {
            event[count] = x;
            count++;
        }
    }
    input.close();

    input.open(file_input, ios::in);

    if (input.is_open())
    {
        string line1, line2;
        getline(input, line1);
        getline(input, line2);
        getline(input, line3);
    }
    input.close();

    stringstream ss(line3);
    int countline3{ 0 };
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        fileline3[countline3] = substr;
        countline3++;
    }
    // Mang fileline3;
}

void Codeevent(int eve, int index, int& rescue, int& level, int& HP, int& phoenixdown, int& remedy, int& maidenkiss)
// index= i+1;
// eve = event[i];
{
    if (eve == 0)
    {
        rescue = 1;
    }
    if (eve >= 1 && eve <= 5)
    {
        int b = index % 10;
        int levelO = index > 6 ? (b > 5 ? b : 5) : b;
        if ((level > levelO)||(checkArthur==1)||(checkLancelot==1))
        {
            if (level < 10)
            {
                level += 1;
            }
        }
        else if (level == levelO)
        {
            rescue = -1;
        }
        else
        {
            float  BaseDam;
            switch (eve)
            {
            case 1: BaseDam = 1;
                break;
            case 2:BaseDam = 1.5;
                break;
            case 3:BaseDam = 4.5;
                break;
            case 4:BaseDam = 7.5;
                break;
            case 5:BaseDam = 9.5;
            }
            HP = HP - BaseDam * levelO * 10;
            if (HP <= 0)
            {
                if (phoenixdown > 0)
                {
                    phoenixdown = phoenixdown - 1;
                    HP = MaxHP;
                    checkTiny = 0;
                    checkFrog = 0;
                }
                else {
                    rescue = 0;
                }
            }
        }
    }
    if (eve == 6)
    {
        int b = index % 10;
        int levelO = index > 6 ? (b > 5 ? b : 5) : b;
        if ((level > levelO) || (checkArthur == 1)||(checkLancelot==1))
        {
            if (level < 9)
            {
                level += 2;
            }
            else
            {
                level = 10;
            }
        }
        else if ((level == levelO) || (checkTiny == 1) || (checkFrog == 1))
        {
            rescue = -1;
        }
        else
        {
            if (remedy >= 1)
            {
                remedy = remedy - 1;   
                checkTiny = 0;
            }
            else
            {
                checkTiny = 1;

                if (HP >= 5)
                {
                    HP = HP / 5;
                }
                else
                {
                    HP = 1;
                }
            }
        }
    }
    if (eve == 7)
    {
        int b = index % 10;
        int levelO = index > 6 ? (b > 5 ? b : 5) : b;
        if ((level > levelO) || (checkArthur == 1)||(checkLancelot == 1))
        {
            if (level < 9)
            {
                level += 2;
            }
            else
            {
                level = 10;
            }
        }
        else if ((level == levelO) || (checkTiny == 1) || (checkFrog == 1))
        {
            rescue = -1;
        }
        else
        {
            if (maidenkiss >= 1)
            {
                maidenkiss = maidenkiss - 1;
                
            }
            else
            {
                levelBeforFrog = level;
                level = 1;
                checkFrog = 1;
            }
        }

    }
    if (eve == 11)
    {
        int n1, s1;
        s1 = 0;
        n1 = ((level + phoenixdown) % 5 + 1) * 3;
        for (int i = 99; i >= (99+2-2*n1); i=i-2)
        {
            s1 = s1 + i;
        }
        HP = HP + (s1 % 100);
        
        for (int i = (HP+1); i >= 2; i++)
        {
            if (LaSoNguyenTo(i) == true)
            {
                HP = i;
                break;
            }
        }
        if (HP > MaxHP)
        {
            HP = MaxHP;
        }

    }
    if (eve == 12)
    {
        if (HP > 1)
        {
            for (int i = (HP-1); i > 1; i--)
            {
                if (is_fibonacci(i) == true)
                {
                    HP = i;
                    break;
                }
            }
        }
        else 
        {
            HP = 1;
        }
    }
    if ((eve / 100) >= 1)
    {
        int digit13[MAX];
        int x = eve;
        int count13{ 0 };
        while (x > 0)
        {
            digit13[count13] = x % 10;
            x = x / 10;
            count13++;
        }
        for (int i = 0; i < (count13 / 2); i++)
        {
            int temp = digit13[i];
            digit13[i] = digit13[count13 - i - 1];
            digit13[count13 - i - 1] = temp;
        }
        // Tao mang digit13;
  
        int n2;
        string linen2;
        fstream mush;
        mush.open(fileline3[0], ios::in);
        if (mush.is_open())
        {
            string linenfake;
            mush >> n2;
            getline(mush, linenfake);
            getline(mush, linen2);
        }
        mush.close();

        stringstream ss(linen2);

        char ch;
        int tmp;
        int arlinen2[MAX];
        int countn2{ 0 };
        while (ss >> tmp) {
            arlinen2[countn2] = tmp;
            ss >> ch;
            countn2++;
        }
  
        for (int i = 2; i < count13; i++)
        {
            if (digit13[i] == 1)
            {
                int max = arlinen2[0];
                int min = arlinen2[0];
                int maxi{ 0 };
                int mini{ 0 };
                for (int i = 0; i < countn2; i++)
                {
                    if (arlinen2[i] >= max)
                    {
                        max = arlinen2[i];
                        maxi = i;
                    }
                    if (arlinen2[i] <= min)
                    {
                        min = arlinen2[i];
                        mini = i;
                    }
                }
                if (min == max)
                {
                    maxi = mini = 0;
                }
                HP = HP - (maxi + mini);
                if (HP > MaxHP)
                {
                    HP = MaxHP;
                }
                if ((HP <= 0) && (phoenixdown > 0))
                {

                    HP = MaxHP;
                    phoenixdown = phoenixdown - 1;
                    checkTiny = 0;
                    checkFrog = 0;

                }
                if ((HP <= 0) && (phoenixdown < 1))
                {
                    rescue = 0;
                    break;
                }
            }
            if (digit13[i] == 2)
            {
                int checkleft = 1;
                int checkright = 1;
                int mtx = arlinen2[0];
                int mti{ 0 };
                for (int i = 0; i < countn2; i++)
                {
                    if (arlinen2[i] >= mtx)
                    {
                        mtx = arlinen2[i];
                        mti = i;
                    }
                }
                for (int i = 0; i < mti; i++)
                {
                    if (arlinen2[i] >= arlinen2[i + 1])
                    {
                        checkleft = -1;
                    }
                }
                for (int i = mti; i < (countn2 - 1); i++)
                {
                    if (arlinen2[i] <= arlinen2[i + 1])
                    {
                        checkright = -1;
                    }

                }
                if ((checkleft == 1) && (checkright == 1))
                {
                    HP = HP - (mtx + mti);
                }
                else
                {
                    mtx = -2;
                    mti = -3;
                    HP = HP - (mtx + mti);
                }
                if (HP > MaxHP)
                {
                    HP = MaxHP;
                }
                if ((HP <= 0) && (phoenixdown > 0))
                {

                    HP = MaxHP;
                    phoenixdown = phoenixdown - 1;
                    checkTiny = 0;
                    checkFrog = 0;

                }
                if ((HP <= 0) && (phoenixdown < 1))
                {
                    rescue = 0;
                    break;
                }
            }
            if (digit13[i] == 3)
            {
                int mush3[countn2];
                for (int i = 0; i < countn2; i++)
                {
                    if (arlinen2[i] < 0)
                    {
                        mush3[i] = -arlinen2[i];
                    }
                    else
                    {
                        mush3[i] = arlinen2[i];
                    }

                    mush3[i] = (17 * mush3[i] + 9) % 257;
                }
                int max = mush3[0];
                int min = mush3[0];
                int maxi2{ 0 };
                int mini2{ 0 };
                for (int i = 0; i < countn2; i++)
                {
                    if (mush3[i] > max)
                    {
                        max = mush3[i];
                        maxi2 = i;
                    }
                    if (mush3[i] < min)
                    {
                        min = mush3[i];
                        mini2 = i;
                    }
                }

                HP = HP - (maxi2 + mini2);
                if (HP > MaxHP)
                {
                    HP = MaxHP;
                }
                if ((HP <= 0) && (phoenixdown > 0))
                {

                    HP = MaxHP;
                    phoenixdown = phoenixdown - 1;
                    checkTiny = 0;
                    checkFrog = 0;

                }
                if ((HP <= 0) && (phoenixdown < 1))
                {
                    rescue = 0;
                    break;
                }
            }
            if (digit13[i] == 4)
            {
                int mush3[countn2];
                for (int i = 0; i < countn2; i++)
                {
                    if (arlinen2[i] < 0)
                    {
                        mush3[i] = -arlinen2[i];
                    }
                    else
                    {
                        mush3[i] = arlinen2[i];
                    }

                    mush3[i] = (17 * mush3[i] + 9) % 257;
                }

                int max2_3x = mush3[0];
                int max2_3i{ 0 };
                int checkmax23i = 0;

                if (countn2 < 3)
                {
                    if (countn2 == 1)
                    {
                        max2_3x = -5;
                        max2_3i = -7;
                    }
                    if (countn2 == 2)
                    {
                        if (mush3[0] == mush3[1])
                        {
                            max2_3x = -5;
                            max2_3i = -7;
                        }
                        else {
                            if (mush3[0] > mush3[1])
                            {
                                max2_3x = mush3[1];
                                max2_3i = 1;
                            }
                            else
                            {
                                max2_3x = mush3[0];
                                max2_3i = 0;
                            }
                        }

                    }

                }
                else {
                    for (int i = 0; i < 3; i++)
                    {
                        if (mush3[i] != mush3[0])
                        {
                            checkmax23i = 1;
                            break;
                        }
                    }
                    if (checkmax23i == 0)
                    {
                        max2_3x = -5;
                        max2_3i = -7;

                    }
                    else
                    {
                        int maxxx = mush3[0];
                        int minxxx = mush3[0];
                        for (int i = 0; i < 3; i++)
                        {
                            if (mush3[i] > maxxx) maxxx = mush3[i];
                            if (mush3[i] < minxxx)
                            {
                                minxxx = mush3[i];
                                max2_3i = i;
                            }
                        }

                        for (int i = 0; i < 3; i++)
                        {
                            if ((mush3[i] > minxxx) && (mush3[i] < maxxx))
                            {
                                max2_3x = mush3[i];
                                minxxx = mush3[i];
                                max2_3i = i;
                            }
                            else
                            {
                                max2_3x = minxxx;
                            }
                        }
                    }              
                }


                HP = HP - (max2_3x + max2_3i);
                if (HP > MaxHP)
                {
                    HP = MaxHP;
                }
                if ((HP <= 0) && (phoenixdown > 0))
                {

                    HP = MaxHP;
                    phoenixdown = phoenixdown - 1;
                    checkTiny = 0;
                    checkFrog = 0;

                }
                if ((HP <= 0) && (phoenixdown < 1))
                {
                    rescue = 0;
                    break;
                }

            }
            
        }
    }
   
    if (eve == 15)
    {
        if (remedy < 99)
        {
            remedy = remedy + 1;
        }
        if (checkTiny == 1)
        {
            if (remedy >= 1)
            {
                checkTiny = 0;
                remedy = remedy - 1;
                HP = HP * 5;
                if (HP > MaxHP)
                {
                    HP = MaxHP;
                }
            }
        }
       
    }
    if (eve == 16)
    {
        if (maidenkiss < 99)
        {
            maidenkiss = maidenkiss + 1;
        }
        if (checkFrog == 1)
        {
            if (maidenkiss >= 1)
            {
                checkFrog = 0;
                maidenkiss = maidenkiss - 1;
                level = levelBeforFrog;
            }
        }
    }
    if (eve == 17)
    {
        if (phoenixdown < 99)
            phoenixdown = phoenixdown + 1;
    }
    if (eve == 19)
    {
        if (checkAsclepius == 0)
        {
            int r1{ 0 };
            int c1{ 0 };
            int arrAsclepius[MAX2][MAX2];
            fstream Asclep;
            Asclep.open(fileline3[1], ios::in);
            if (Asclep.is_open())
            {
                Asclep >> r1 >> c1;
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        Asclep >> arrAsclepius[i][j];
                    }
                }

            }
            Asclep.close();
            for (int i = 0; i < r1; i++)
            {
                int countAsc = 0;
                for (int j = 0; j < c1; j++)
                {            
                    if (arrAsclepius[i][j] == 16)
                    {
                        remedy = remedy + 1;
                        countAsc++;
                    }
                    if (arrAsclepius[i][j] == 17)
                    {
                        maidenkiss = maidenkiss + 1;
                        countAsc++;
                    }
                    if (arrAsclepius[i][j] == 18)
                    {
                        phoenixdown = phoenixdown + 1;
                        countAsc++;
                    }
                    if (countAsc == 3)
                    {
                        goto label;       
                    }

                }
            label:;
            }
            if (remedy > 99)
            {
                remedy = 99;
            }
            if (maidenkiss > 99)
            {
                maidenkiss = 99;
            }
            if (phoenixdown > 99)
            {
                phoenixdown = 99;
            }
        
            checkAsclepius = 1;
            if (checkTiny == 1) 
            {
                if (remedy >= 1)
                {
                    checkTiny = 0;
                    remedy = remedy - 1;
                    HP = HP * 5;
                    if (HP > MaxHP)
                    {
                        HP = MaxHP;
                    }
                }
            }
            if (checkFrog == 1)
            {
                if (maidenkiss >= 1)
                {
                    checkFrog = 0;
                    maidenkiss = maidenkiss - 1;
                    level = levelBeforFrog;
                }
            }

        }
    }
    if (eve == 99)
    {
        if ((checkArthur == 1) || ((checkLancelot == 1) && (level >= 8)) || (level == 10))
        {
            level = 10;
        }
        else
        {
            rescue = 0;
        }
    }
    if (eve == 18)
    {
        if (checkMerlin == 0)
        {
            checkMerlin = 1;
            int n9{ 0 };
            string linen9[MAX];
            fstream Merlinn;
            Merlinn.open(fileline3[2], ios::in);
            if (Merlinn.is_open())
            {
                string linenfakee;
                Merlinn >> n9;
                getline(Merlinn, linenfakee);
                int countmerlin{ 0 };
                while (countmerlin < n9)
                {
                    getline(Merlinn, linen9[countmerlin]);
                    countmerlin++;
                }
            }
            Merlinn.close();

            string Mer = "Merlin";
            string mer = "merlin";
            for (int i = 0; i < n9; i++)
            {
                if ((linen9[i].find(Mer) != string::npos) || (linen9[i].find(mer) != string::npos))
                {
                    HP = HP + 3;
                    goto endd;

                }
                if (((linen9[i].find('M') != string::npos) || (linen9[i].find('m') != string::npos))
                    && ((linen9[i].find('E') != string::npos) || (linen9[i].find('e') != string::npos))
                    && ((linen9[i].find('R') != string::npos) || (linen9[i].find('r') != string::npos))
                    && ((linen9[i].find('L') != string::npos) || (linen9[i].find('l') != string::npos))
                    && ((linen9[i].find('I') != string::npos) || (linen9[i].find('i') != string::npos))
                    && ((linen9[i].find('N') != string::npos) || (linen9[i].find('n') != string::npos)))
                {
                    HP = HP + 2;
                }
            endd:;
            }
            if (HP > MaxHP)
            {
                HP = MaxHP;
            }

        }
    }

}

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
void adventureToKoopa(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    rescue = -1;
    checkTiny = 0;
    levelBeforFrog = 0;
    checkFrog = 0;
    checkAsclepius = 0;
    checkArthur = 0;
    checkLancelot = 0;
    checkMerlin = 0;
    docfile(file_input, HP, level, remedy, maidenkiss, phoenixdown);
    MaxHP = HP;
    if (MaxHP == 999)
    {
        checkArthur = 1;
    }
    if (LaSoNguyenTo(MaxHP) == true)
    {
        checkLancelot = 1;
    }
    for (int i = 0; i < count; i++)

    {
        Codeevent(event[i], i + 1, rescue, level, HP, phoenixdown, remedy, maidenkiss);

        if ((rescue == -1) && (i == (count - 1)))
        {
            rescue = 1;
        }
        if (rescue == 0)
        {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }
        if ((event[i - 3] == 7) && (checkFrog == 1))
        {
            level = levelBeforFrog;
            checkFrog = 0;
        }
        if ((event[i - 3] == 6) && (checkTiny == 1))
        {
            HP = HP * 5;
            if (HP > MaxHP)
            {
                HP = MaxHP;
            }
            checkTiny = 0;
        }
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

        if ((rescue == 0) || (rescue == 1))
            break;
    }
}
          

    
