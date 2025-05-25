//GAUSS ELIMINATION CODE

#include<iostream>//for input output 
#include<vector>//for std::vector
#include<cstdlib>//for std::exit std::system std::size_t 
#include<cmath>//std::abs
#include<cassert>//for assert for debuggin purposes 
//vector =matrix nte kai kala 
inline void printmatrix(const std::vector<std::vector<double>>& a, const std::vector<double>& b) {
    std::cout << "A:\n";
    //prints the contents of matrix A 
    for (std::size_t i = 0; i < a.size(); i++) {//for loop
        for (std::size_t j = 0; j < a[i].size(); j++) {//for loop
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }
    //prints the contents of matrix B
    std::cout << "b:\n";
    for (std::size_t i = 0; i < b.size(); i++) {//for loop 
        std::cout << b[i] << '\n';
    }

    return;
}
//prints the solution //pretty much just print the vector x
inline void printsolution(const std::vector<double>& x) {//just prints an 1d vector 
    std::cout << "x:" << '\n';
    for (std::size_t i = 0; i < x.size(); i++) {//for loop ,use '\n' not std::endl 
        std::cout << x[i] << '\n';
    }
    return;
}
//this makes the multiplication beetween matrix a and B to verify that 
//the solution is correct 
inline void verification(const std::vector<std::vector<double>>& a, const std::vector<double>& x) {//gia na doume an einai swsth h lush tou A*x=b gia to x poy brhkame 
    std::cout << "verification:\n";
    for (std::size_t  i = 0; i < a.size(); i++) {//for loop
        double s = 0;
        for (std::size_t j = 0; j < a.size(); j++) {//for loop
            s += a[i][j] * x[j];
        }
        std::cout << s << '\n';
    }
    return;
}


inline bool isEqual(double a, double b, double epsilon = 1.0E-8) /*noexcept*/ {//logo tou problhmatos akribeis poy eixoyme me tous dekadikous 
    //has a default arg
    return std::abs(b - a) < epsilon;
}



int main() {//this code performs gauss elimination 

    std::cout << "give a  size\n";
    std::size_t size{};
    double element{};//plhtos grammwn tou A 
    std::cin >> size;
    //make sure to not overlow the std::size_t type negative number overflow size variable
    assert(size > 0);
    std::vector<std::vector<double>>a{};
    assert(size < a.max_size());//na mhn jepername sygkekrimeno megetos oxi apeiros xoros 
    a.resize(size);//initializes vector with zeroes
    std::vector<double>b{};
    std::cout << "elements for A\n";
    for (std::size_t i = 0; i < a.size(); i++) {
        a[i].reserve(a.size());
        for (std::size_t j = 0; j < a.size(); j++) {
            std::cin >> element;
            a[i].emplace_back(element);//put the elements in a dinei elements gia kate grammh A diabaste ta sxoleia sto source2.cpp gia to pos ola auta einai isodynama me ena aplo 2d array 
            //use emplace_back not push_back

        }
    }

    std::vector<std::vector<double>>u{ a };//the same as telling u=a; einai object=object 
    std::cout << "elements for b\n";
    b.reserve(size);//tell them about reserve space the less realloc the better 
    //try putting those lines out 
    for (std::size_t i = 0; i < a.size(); i++) {
        std::cin >> element;
        b.emplace_back(element);//put the elements in the b arxikopoihsh b dianysmatos toy Ax=b
        //use emplace back for not push_back
    }

    for (std::size_t k = 0; k < a.size(); k++) {
        if (a[k][k] == 0) {//den prepei h diagonios na exei mhdenika alliws problhma gia ton algoritmo mas 
          //ginetai if(isEqual(a[k][k],0.0))
            std::cout << "error\n";
            std::exit(EXIT_FAILURE);
        }
        for (std::size_t i = k + 1; i < a.size(); i++) {//gramo prajhs opos eixame deijh ston pinaka 


            double kati = a[i][k] / a[k][k];//kati= very original name 

            for (std::size_t j = k; j < a.size(); j++) {

                a[i][j] = a[i][j] - kati * a[k][j];//or a[i][j]-=katia[k][j]

            }
            b[i] = b[i] - kati*b[k];
        }

    }
    printmatrix(a, b);//to simply see what happened after forward substitution
  // kaname ton pinaka ano trigoniko kai peirajame kai to b mazi san na einai o epayjhmenos [A b] 
if (a[a.size() - 1][a.size() - 1] == 0.0) {//check if it not an error
        //the == is bad for floating point nums use equals func instead 
        std::cout << "error\n";
        std::exit(EXIT_FAILURE);
    }//ENA TELEYTAIO CHECK STHN DIAGWNIO OPOS EIXAME PEI 
    std::vector<double>x(size);//ARXIKOPOIHSH X 

    //backwards substitution:
    for (std::size_t k = a.size() - 1; k > 0; k--) { //if k>=0 then this will overlow the number

        x[k] = b[k];
        for (std::size_t j = k + 1; j < a.size(); j++) {
            x[k] = (x[k] - a[k][j] * x[j]);
        }

        x[k] = x[k] / a[k][k];


    }//LYNOUME TORA TO SYSTHMA OPOS EIXAME DEIJEI PINAKA 
    std::size_t k = 0;

    x[k] = b[k];
    for (std::size_t j = k + 1; j < a.size(); j++) {
            x[k] = (x[k] - a[k][j] * x[j]);
    }

    x[k] = x[k] / a[k][k];//problem if we devide by zero 

    //BRHKA ME X 


    printsolution(x);//the solution to see what we found PRINT THN LYSH 

    verification(u, x);//the verification of the solution to simply see if the solution 
    //was correct and the code didnt do potatoes 
    //NA DOUME AN LYSH SOSTH KAI KANO A*x GIA NA DO AN A*x=b OPOS EIXAME STHN ARXH GIA TO b POY MAS DOTHKE 


}
