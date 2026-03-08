#include<bits/stdc++.h>
using namespace std;
void vector1(){
    //normal vector
    cout<<"vector1"<<endl;
    vector<int> v1;
    v1.push_back(1);
    v1.emplace_back(8);
    for(int x:v1){
        cout << x <<" ";
        cout<<endl;
    }
}
void vector2(){
    // vector with pair
    cout<<"vector2"<<endl;
    vector<pair<int,int>> v2;
    v2.push_back({1,6});
    v2.emplace_back(2,5);
    for(const auto& y :v2){
        cout<< y.first<<" "<<y.second<<" ";
        cout<<endl;
    }
}
void vector3(){
    // accessing the elements using iterator
    vector<int> v3(5,100);
    // adding extra element 6 to the vector v3 dynamically
    v3.emplace_back(6);
    // accessing address of vector element using iterator (it) from begining
    vector<int>::iterator it=v3.begin();
    // v.begin(); for first element
    // v.end(); for accessing address right after the last element
    // v.rend(); for accessing address right before the first element
    // v.rbegin(); for for accessing address of the last element
    // printing the elements of v3 directly using *it
    for(int i=0;i<6;i++){
        cout<<*it;
        it++;
        cout<<endl;
    }
    // adding 7,8,9,10,11 to vector v3
    v3.emplace_back(7);
    v3.emplace_back(8);
    v3.emplace_back(9);
    v3.emplace_back(10);
    v3.emplace_back(11);
    cout<<"before erasing"<<endl;
    for(auto it=v3.begin();it!=v3.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // to erase elements (2nd element to last 3rd element) from a vector
    v3.erase(v3.begin()+1,v3.end()-3);
    cout<<"remaining element after erasing elements"<<endl;
    for(auto it=v3.begin();it!=v3.end();it++){
        cout<<*it<<" ";
    }
}
void vector4(){
    // inserting elements to vector
    vector<int> v4(2,100); // {100,100}
    v4.insert(v4.begin(),300); //{300,100,100}
    v4.insert(v4.begin()+1,2,200); // {300,200,200,100,100}
    vector<int> copy(2,500); // new vector copy={500,500}
    v4.insert(v4.begin(),copy.begin(),copy.end()); //{500,500,300,200,200,100,100}
    cout<<"v4 size ="<<v4.size(); //size=7
    cout<<endl;
    v4.pop_back(); // pops out the last elements
    cout<<"size of v4 after pop="<<size(v4)<<endl; // size(v4)=7
    copy.swap(v4); //swaps copy to v4 and v4 to copy
    cout<<"size of v4 after swap="<<size(v4)<<endl; // size(v4)=2
    cout<<"size of copy after swap="<<size(copy)<<endl;
    copy.clear();
    cout<<"size of copy after swap and clear operation= "<<copy.size()<<endl; // size(copy)=0
    cout<<copy.empty()<<endl;//prints copy is empty or not
    cout<<v4.empty();
}
int main(){
    vector4();

    }