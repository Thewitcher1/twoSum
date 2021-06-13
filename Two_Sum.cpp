
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include <numeric>
using namespace std;

void print(vector<int>&& vec)
{
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

vector<int> twoSum(vector<int> nums, int target) {
    vector<int> index(2);
    int n = nums.size();
    for(int i = 0; i < n ; i++) {
        index[0] = i+1;
        for(int j = i+1 ; j < n ; j++) {
            if(nums[i] + nums[j] == target){
                index[1] = j+1;
                return index;
            }
        }
    }
    return index;
}

int main(){

    vector<int>vec(9);
    iota(vec.begin(), vec.end(),0);

    for(auto elm:vec){ cout << elm;}
    cout<< endl;
    print(twoSum(vec,9));

    // another example
    print(twoSum(vec,5));
    return 0;
}

---------------------------------SQL Command -------------------------------------------------------
    
    creation d'une base de donnée:  create database Client:
    
create database client;  -- creation d'une base de donnée

create table entrep (     ----- déclaration de tableau 
  ID int primary key identity,  
  Nom varchar(20) Not Null,
  Prenom varchar(20) Not null,
  Age int,
  Adresse varchar(20),
  Tel varchar(20)
);
                                                  ---- remplissage de tableau client
insert into entrep values ('Sahbi','Nebti', 50, 'France', '*******')
insert into entrep values ('Sahbi1','Nebti1', 40, 'France1', '1*******')
insert into entrep values ('Sahbi2','Nebti2', 30, 'France2', '2*******')
insert into entrep values ('Sahbi3','Nebti3', 20, 'France3', '3*******')
insert into entrep values ('Sahbi4','Nebti4', 10, 'France4', '4*******')

delete from entrep where id =1;    -----supprimer toute une ligne de tableau client 
