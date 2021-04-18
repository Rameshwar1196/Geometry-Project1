#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include "point3d.h"
using namespace std;

// constructor will help us create an instance of v3 
point3d convert_to_point(char* facet)
{

    char f1[4] = { facet[0],
        facet[1],facet[2],facet[3] };

    char f2[4] = { facet[4],
        facet[5],facet[6],facet[7] };

    char f3[4] = { facet[8],
        facet[9],facet[10],facet[11] };

    float xx = *((float*)f1);
    float yy = *((float*)f2);
    float zz = *((float*)f3);

    return  point3d(double(xx), double(yy), double(zz));
}


//Readin stl files
void read_stl(string fname, vector <triangle>& v)
{
    ifstream myFile(fname.c_str(), ios::in | ios::binary);
    char header_info[80] = "";
    char nTri[4];
    unsigned long nTriLong = 0;

    //read 80 byte header
    if (myFile) {
        myFile.read(header_info, 80);
        cout << "header: " << header_info << endl;

        myFile.read(nTri, 4);
        nTriLong = *((unsigned long*)nTri);
        cout << "n Tri: " << nTriLong << endl;
    }
    else {
        cout << "error" << endl;
    }

    //now read in all the triangles
    for (size_t i = 0; i < nTriLong; i++) {

        char facet[50];

        if (myFile) {//read one 50-byte triangle
            myFile.read(facet, 50);//populate each point of the triangle using v3::v3(char* bin); facet + 12 skips the triangle's unit normal
            point3d p1 = convert_to_point(facet + 12);
            point3d p2 = convert_to_point(facet + 24);
            point3d p3 = convert_to_point(facet + 36);

            //add a new triangle to the array
            v.push_back(triangle(p1, p2, p3));

        }
    }
}

int main()
{
    std::string file_path = "D:/Haridas/UoP/AABBTree/Geometry-Project1/models/Cube_binary.stl";
    
    std::vector<triangle> triangles;

    read_stl(file_path, triangles);

}