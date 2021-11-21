#include <string>
#include <vector>
#include<iostream>



int main(int argc, char** argv){


    int i=1;
    int compteur=0;
    std::vector<std::string> str;

    for (; i<argc; i++  ){
        std::string s=argv[i];
        str.push_back(s);   /* str est un vecteur contenant des char* */
        
    }
    
    std::vector<int> V;

    for (; i<argc; i++  ){
        

    
    if (str[i]=="+"){
    int s1;
    int s2;
    s1=std::stoi(str[i-1]);
    s2=std::stoi(str[i-2]);
    if (compteur==0){
        V.push_back(s1+s2);
    }
    V.push_back(s1+V[compteur-1]);
    compteur++;
    }
    }
    std::cout<< V[compteur-1] << std::endl;
    return(0);
    }