
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& vec) 
    { 
        vector<vector<int>>a;
       
     int s=vec.size();
      for(int i=0;i<pow(2,s);i++)
        {
         vector<int>v;
            for(int j=0;j<vec.size();j++)
            {
                cout<<(1<<j);
                
    if(i&(1<<j))
                {
                   
                    v.emplace_back(vec[j]);
                }
            }
            a.emplace_back(v);
v.clear();
           
        }   
               return a; 
    }
};