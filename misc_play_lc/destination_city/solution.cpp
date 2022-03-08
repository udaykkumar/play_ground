class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        std::unordered_map< std::string, bool > cmap;

        for ( auto p : paths )
        {
            for( auto i = 0; i < p.size() ; ++ i ) 
            {
                auto c = p.at(i);
                auto cit = cmap.find(c);

                if( cit != cmap.end() /** eixists**/ && cit->second /* True */ )
                {
                    continue;
                }
                else if (cit == cmap.end() /** We've seen it for the first time */ )
                {
                    cmap.insert(
                        std::pair<std::string, bool>(c, (i != p.size() - 1)));

                }
                else if( cit->second == false /* we found this as last city*/ )
                {
                    if ( i == p.size() -1 /* and its still last city */ )
                        continue;
                    else
                        cmap[c] = true ;
                }

            }
        }

        for ( auto c : cmap ) {
            if ( c.second == false)
                return c.first;
        }

        return "";
    }
};