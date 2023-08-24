//
// Created by B on 8/12/2023.
//

#include "resources.h"

void resources::set_patterns(){
    patterns["smile"]=smiley;
    patterns["heart"]=hearts;
    patterns["nf"]=noface;
    patterns["bmo"]=bmo;

}
string resources::random(){

        string u = "smiles";
        int n = ((rand() % patterns.size()));
        if(n==0){
            u ="smile";
        }
        else if (n==1){
            u="heart";
        }
        else if (n==2){
            u="nf";
        }
        else if (n==3){
            u="bmo";
        }

        return u;
}
