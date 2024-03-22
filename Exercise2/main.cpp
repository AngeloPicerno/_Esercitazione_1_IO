#include <iostream>
#include <fstream>
#include <iomanip>


double mapfunction(double x)
{
    return (3*x-7)/4;

}


int main()

{
    std::string filename="data.csv";
    std::ifstream ifstr(filename);

    if(ifstr.fail())
    {
        std::cerr<<"File does not exist"<<std::endl;
        return 1;
    }
    double val=0;
    double mapped=0;
    double total=0;
    double mean=0;
    int count=0;
    std::ofstream outfile("result.csv");
    outfile<<"#" <<" "<<"N"<<"  "<<"Mean"<<std::endl;
    while(ifstr >> val)
    {
        mapped =mapfunction(val);
        total=mapped+total;
        count++;
        mean = total/count;
        outfile<<count<<" "<<std::setprecision(16)<<std::scientific<< mean<<std::endl;



    }


    ifstr.close();
    return 0;


}
