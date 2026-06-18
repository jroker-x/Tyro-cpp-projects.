#include<iostream>
#include<vector>

size_t hash(const std::string& str);
template<typename k,typename v>
class Hashmap{
    private:
    std::vector<std::vector<std::pair<std::string,int>>> buckets;

    public:
        Hashmap(size_t bucketcount = 10)
        : buckets(bucketcount){}

        void insert(const k& key,const v& value){
            
            size_t bucketindex = hash(key);
            bucketindex %= buckets.size();
            buckets[bucketindex].push_back({key,value});


        }

        void Printbucket()const{
            for (int i = 0; i < buckets.size(); i++)
            {
                std::cout << "Bucket" << i << '\n';
                for (const auto& pair : buckets[i])
                {
                    std::cout << pair.first << " : " << pair.second << '\n';
                }
                std::cout << '\n';
            }
            
            
        }

        bool contains(const k& key){

            size_t bucketindex = hash(key);
            bucketindex %= buckets.size();
            for (const auto& pair : buckets[bucketindex])
            {
              if (pair.first == key)
              {
                return true;
              }
              
            }
            return false;
        }

        v* find(const k& key){

            size_t bucketindex = hash(key);
            bucketindex %= buckets.size();
            for (auto& pair : buckets[bucketindex])
            {
              if (pair.first == key)
              {
                return &pair.second;
              }
              
            }
            return nullptr;

        }
        
        v& operator[](const k& key){

            size_t bucketindex = hash(key);
            bucketindex %= buckets.size();
            for (auto& pair : buckets[bucketindex])
            {
              if (pair.first == key)
              {
                return pair.second;
              }
            }

            buckets[bucketindex].push_back({key,v{}});

            return  buckets[bucketindex].back().second;
        }

}; 
 

int main(){

    Hashmap<std::string,int> map;
    map.insert("apple", 5);
    
    map["ab"] = 1;
    map["ba"] = 2;
    std::cout << map.find("ab");
    std::cout <<map.find("ba");




 return 0;
}

size_t hash(const std::string& str){

    size_t hash = 0;

    for (char c : str)
    {
       hash += c;
    }
    

    return hash;


}