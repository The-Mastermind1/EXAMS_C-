//MATRIX X VECTOR CODE
//PAIDIA PSHLA TO KEFALI KEEP GOING 
//
//treje ton kodika auto gia na deite kai eseis ti bgazei
//
#include<iostream>
#include<vector>
#include<cassert>
#include<cstdlib>
#include<cassert>
//print the matrix to see the results 
inline void printmatrix(const std::vector<double>& b) {//just prints the matrix 

    std::cout << "b:\n";
    for (std::size_t i = 0; i < b.size(); i++) {
        std::cout << b[i] << '\n';//dont use endl or std::endl xoris using namespace std; to '\n' better 
    }

    return;
}
//multiplication matrix * vector 
inline void matrixXvector(const std::vector<std::vector<double>>& a
    , const std::vector<double>& x) {//ax= b b the result 
    assert(a.size() > 0 && a[0].size() > 0);//for  debug teoroume nte kai kala oti auto 
    //den ta ginei pote false alliws kaname patata 
    assert(a[0].size() == x.size());
    std::vector<double>b{};
    b.reserve(a.size());//oxi a[0].size() problhma leme apla oti to plhtos stoixeion tou b ta einai oso to plhtos ton grammon tou a  
    double sum{};
    for (std::size_t i = 0; i < a.size(); i++) {
        sum = 0;
        for (std::size_t j = 0; j < a[i].size(); j++) {
            sum += a[i][j]*x[j];
        }
      //bgalama apotelesma ths proths grammhs tou a epi to dianysma 
        b.emplace_back(sum);//kai apla to dinoume san stoixeio ston pinaka san na legame b[i]=sum;
    }
    printmatrix(b);//print matrix b opos kai sto lykeio dio for loops ena i,j kai to print statement anamesa edo einai cout h std::cout xoris using namespace std;

}



int main() {
    //for matrix nxn 
    std::cout << "give a  size\n";//plhtos grammwn gia pinaka A
    std::size_t size{};
    double element{};
    std::cin >> size;
    //make sure to not overlow the std::size_t type negative number overflow size variable
    assert(size > 0);
    std::vector<std::vector<double>>a{};
    assert(size < a.max_size());//leme oti to size pou epitrepetai na dosei o xrhsths einai mexri ena shmeio size <a.max_size() giati den exo apeirh mnhmh ///
    a.resize(size);//arxikopoiei grammes tou A etsi oste gia kate mia na xwsoyme element 
    std::vector<double>x{}; // to x vector apo to A*x=b
    std::cout << "elements for A\n";
    for (std::size_t i = 0; i < a.size(); i++) {
        a[i].reserve(a.size());//leme apla oti kate grammh tou ta exei tosa elements a.size =size pou dosame sthn arxh sthn grammh 44 
        for (std::size_t j = 0; j < a.size(); j++) {
            std::cin >> element;
            a[i].emplace_back(element);//put the elements in a sthn grammh I tou A dino elements 
            //use emplace_back not push_back

        }
    }
    //san na eixa pinaka double A[n][n] (n,n) dosmena apo xrhsth .Na eixa dio for loop kai 
    // na eixa for (std::size_t i=0;i<m ;i++){
    //          for(std::size_t j=0;j<n;j++){
    //              std::cin >>a[i][j]; h cin >>a[i][j];
    //          }
    //        }


    std::cout << "elements for x\n";
    x.reserve(size);//tell them about reserve space the less realloc the better 
    //try putting those lines out //give the elements for x in : A*x=b 
    for (std::size_t i = 0; i < a.size(); i++) {
        std::cin >> element;
        x.emplace_back(element);//put the elements in the b //apla xono elements sto x einai san na eixa x[i]=element; gia double x[n];
        //use emplace back for not push_back
    }
    matrixXvector(a, x);//matrix x vector to see the result 

}
