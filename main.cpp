#include<iostream>
using namespace std;
//Readin stl files
void read_stl(string fname, vector <tri>& v) {

    //!!
    //don't forget ios::binary
    //!!
    ifstream myFile(
        fname.c_str(), ios::in | ios::binary);

    char header_info[80] = "";
    char nTri[4];
    unsigned long nTriLong;

    //read 80 byte header
    if (myFile) {
        myFile.read(header_info, 80);
        cout << "header: " << header_info << endl;
    }
    else {
        cout << "error" << endl;
    }
int main()
	{
    std::string file_path=""

	}