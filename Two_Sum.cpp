
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
    
    
creation d'une base de donnée:  create database Client:
    
create database client;

create table soc(
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
 select métier from soc where id between 1 and 3;              ---------- Opérateur between 
 
 select métier from soc where métier like '%+'or métier like '%#' or pseudo like 'r%';  -------SQL LIKE
  1- %a --> toute chaine de caractére qui se termine par la lettre a 
  2- a% --> toute chaine de caractére qui commence par la lettre a
  3- %a% --> toute chaine de caractére qui contient la lettre a
  4- a_c --> le sysmbole underscore remplace seulement un seul caractère contrairement au % qui remplace un succession de caractére 
  
     
select * from soc where expertise is null;           -------------> Opérateur IS NULL / IS NOT NULL 
select métier, Max(id) from soc group by métier;     -------------> Opérateur GROUP BY

select métier, AVG(s.expertise *2 ) from soc as s group by métier;  ---> clause: group by 

select Nom, sum(Age*3 + 2)                               select colonne1, fonction(opération à effectuer sur une colonne2)
from entrep group by Nom with rollup                     from table group by colonne1 with rollup
having Max(Age*3 + 2) >7;                                having fonction(opération à effectuer sur une colonne2)

select* from entrep order by Nom ASC;  ----------------> opérateur order by (Asc ou DESC) 

select Nom n1, Prenom p1 from entrep;  ----------------> Cration d'un Alias pour faciliter la compréhension et l'utilistion des # champs.
    
select * from table_1
union all                           -------------------> Union de deux tableau 
select * from table_2;

select * from table_1
intersect                          --------------------> Intersection de deux tableau  
select * from table_2;

select * from table_1
Except                           ---------------------> selectionner tous les colonnes de table_1 à l'exception de table_2
select * from table_2;

update entrep
set Nom = 'Mourad',             ---------------------> update: mise à jour d'un tableau 
	Tel = '######'
where id = 1;

|----------|
| Jointure |
|----------|
    
Inner Join:

select métier, expertise, Nom, Adresse       ---> inner join appelé également EQouiJoin: Cette commande retourne les enregistrements 
from entrep (table_nom)                                     lorsqu’il y a au moins une ligne dans chaque colonne qui correspond à la condition.       
inner join soc(table_nom) on entrep.id = soc.id;


cross join:

select métier,Nom,expertise,Adresse
from soc                                   ------> cross join : retourne le produit cartésien de tableau sql
cross join entrep;


left join:

SELECT *                                          ----> left join(outer left join): une jointure à gauche Cela permet de lister tous les résultats de la table 
FROM utilisateur(table_nom)                            de gauche (left = gauche) même s’il n’y a pas de correspondance dans la deuxième tables.
LEFT JOIN commande(table_nom) ON utilisateur.id = commande.utilisateur_id


Right join:

 SELECT id, prenom, nom, utilisateur_id, date_achat, num_facture
 FROM utilisateur(table_name)
 RIGHT JOIN commande(table_name) ON utilisateur.id = commande.utilisateur_id

---> Right join ou Right outer join: est un type de jointure entre 2 tables qui permet de retourner tous les enregistrements de la table de droite
(right = droite) même s’il n’y a pas de correspondance avec la table de gauche. S’il y a un enregistrement de la table
de droite qui ne trouve pas de correspondance dans la table de gauche, alors les colonnes de la table de gauche auront NULL pour valeur.

	
full join: (full outer join): permet de faire une jointure entre 2 tables. L’utilisation de cette commande permet de combiner les
                     résultats des 2 tables, les associer entre eux grâce à une condition et remplir avec des valeurs NULL si la condition n’est pas respectée. 
	
select * from entrep                  -------> full join
full join soc on entrep.id = soc.id;

self join:
	 un SELF JOIN correspond à une jointure d’une table avec elle-même. Ce type de requête n’est pas si commun mais très pratique dans le
	 cas où une table lie des informations avec des enregistrements de la même table.
    
    
    



select * from soc;
select * from entrep;

