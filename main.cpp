#include <iostream>
#include <iomanip>
#include <mysql++.h>

using namespace std;
using namespace mysqlpp;

int main()
{
    Connection con(false);

    if ( con.connect("ogame_dev","localhost","root","uu7-W23#") )
    {
        Query query = con.query("SELECT * FROM user");
        if ( StoreQueryResult res = query.store() )
        {
            cout << "Table user:" << endl;
            cout << "-------------------------------------------" << endl;
            for ( size_t i = 0; i < res.num_rows(); i++ )
            {
                cout << "| ";
                for ( size_t y = 0; y < res.num_fields(); y++)
                {
                    cout << res[i][y] << " | ";
                }
                cout << endl;
            }
            cout << "-------------------------------------------" << endl;
        }
        else
        {
            cerr << "Error query users table: " << query.error() << endl;
            return -1;
        }
        return 0;
    }
    else
    {
        cerr << "Error DB connection: " << con.error() << endl;
        return -1;
    }
}
