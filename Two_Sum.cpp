
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
Primary Key:

Le clé primaire, permet d’identifier chaque enregistrement dans une table de base de données. Chaque enregistrement de cette
clé primaire doit être UNIQUE et ne doit pas contenir de valeur NULL.
La clé primaire est un index, chacune des tables ne peut contenir qu’une seule clé primaire, composée d’une ou plusieurs colonnes.
L’usage le plus fréquent consiste à créer une colonne numérique qui s’incrémente automatiquement à chaque enregistrement grâce à AUTO_INCREMENT.
    
    
creation d une base de donnée:  create database Client:
    
create database client;

create table soc (
  ID int primary key identity,
  métier varchar(100) Not Null,
  pseudo varchar(50) Not null,
  expertise int,
  esprit varchar(50),
  caractère varchar(50)
);

insert into soc values ('developpeur C/C++','SNE',10, 'excellent', 'smile')
insert into soc values ('developpeur c#','HYG', 8, 'good', 'nervous')
insert into soc values ('developpeur Java','kji', 5, 'very good', 'smile')
insert into soc values ('developpeur NodeJS','JKI', 6, 'excellent', 'smile')
insert into soc values ('developpeur Javascript','rfg',4, 'good', 'smile')

create table entrep (
  ID int primary key identity,
  Nom varchar(20) Not Null,
  Prenom varchar(20) Not null,
  Age int,
  Adresse varchar(20),
  Tel varchar(20)
);

insert into entrep values ('Sahbi','Nebti', 50, 'France', '*******')
insert into entrep values ('Sahbi1','Nebti1', 40, 'France1', '1*******')
insert into entrep values ('Sahbi2','Nebti2', 30, 'France2', '2*******')
insert into entrep values ('Sahbi3','Nebti3', 20, 'France3', '3*******')
insert into entrep values ('Sahbi4','Nebti4', 10, 'France4', '4*******')

insert into entrep values ('sahbi','Nebti', 50, 'France','*******') --- insertion d'un nouveau ligne pour le test (qui sera supprimé aprés)
select distinct Nom,Prenom,Age,Adresse,Tel from entrep;  --- pour éviter les champs doublons
delete from entrep where id=6; --- supprimer toute une ligne de du tableau entrep 
select métier from soc where id=1; --- selectionner la colonne demandée du nom_tableau ou le id vaut 1.
    
 select * from soc where expertise <11 and caractère='smile'; ---------- and et or with where 
 select métier from soc where id =1 or id =2 or id=5;          ---------- and et or with where 
 select métier from soc where id in(1,2,5);                    ---------- Opérateur in 


select * from soc;
select * from entrep;

