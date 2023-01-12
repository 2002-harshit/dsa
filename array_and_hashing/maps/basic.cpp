#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> um;
    //key value pairs

    //insertion
    //or
    um.insert(make_pair("garv",2));
    um.insert(make_pair("harshit",1));
    um.insert(make_pair("h",1));
    um.insert(make_pair("hddf",1));
    um.insert(make_pair("dwd",1));
    um.insert(make_pair("wdw",1));

    //it is worthy noting that here the order of elements is not predictable;

    


    //if a value for a particular key is entered again it is updated


    /*
    for(auto p:um)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    */

//    cout<<um["harshit"]<<endl;//1
//    cout<<um.at("garv")<<endl;//2
//    cout<<um["dd"]<<endl;

    // try
    // {
    //     /* code */
    //     cout<<um.at("ff")<<endl;//this throws exception because ff is not present in the map as key


    // }
    // catch(...)
    // {
    //     cerr<<"key not present"<<endl;
    // }

    /*

    cout<<um["dd"]<<endl;//here it is important to know that since dd is not in the map , an entry is automatically created woth value 0 so, dd - 0 is created ,this was not done by at()!!!!!
    cout<<um["ef"]<<endl;//similarly ef - 0
    cout<<um.at("ef")<<endl;//bnow this will throw 0 because an entry was created by um["ef"];!!!!!!!!!!

    */
    // try
    // {
    //     /* code */
    //     cout<<um.at("ff")<<endl;//this throws exception


    // }
    // catch(...)
    // {
    //     cerr<<"key not present"<<endl;
    // }


    /*

    to tell whether a key is present or not
    cout<<um.count("harshit")<<endl;//1 because present
    cout<<um.count("d")<<endl;//0 not present

    */

   
   //to erase a entry
//    um.erase("harshit");//harshit is deleted
//    um.erase("l");//not present in map, so nothing happens

    

//traversing maps
   cout<<"Tha map values are"<<endl;

//    for(auto itr=um.begin();itr!=um.end();itr++)
//    {
        
//         cout<<(*itr).first<<" "<<(*itr).second<<endl;
//    }


    unordered_map<string,int>::iterator it=um.begin();
    while(it!=um.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    //in the case of a map(not unordered), entries are sorted according to keys;

   cout<<"The size is "<<um.size()<<endl;

    



    return 0;
}