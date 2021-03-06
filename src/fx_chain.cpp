/*This file is part of RSIM.

    RSIM is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RSIM is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with RSIM.  If not, see <http://www.gnu.org/licenses/>.

*/
// Montecarlo fractal kinetics simulator //
#include <istream>
#include <sstream>
#include <vector>
#include <iostream>
#include "parse.h"
#include "atom.h"
#include <string>
#include "chain.h"
#include "residue.h"
#include "polymere.h"

Chain::Chain(Polymere * pol,char chain){
using namespace std;
for(int m=0; m < pol->mols.size(); m++){
residues.push_back(new Residue(pol,chain,m)); 

}
}

Chain::Chain(vector<string> * lines, vector<int> * res_start, vector<int> * res_end,int start, int end){
using namespace std;
//printf("Chain Pos: %d - %d\n",start,end);
//Get the chain name 
//Loop through the lines and resad  
for(int r=0; r<res_start->size(); r++){
//printf("Residue start: %d\n",res_start->at(r));
if(res_start->at(r) < end && res_start->at(r) >= start){
residues.push_back(new Residue(lines,res_start->at(r), res_end->at(r)));
}
}
 

}


void Chain::print(){

for(int r=0; r<residues.size(); r++){
residues[r]->print();
}

}

