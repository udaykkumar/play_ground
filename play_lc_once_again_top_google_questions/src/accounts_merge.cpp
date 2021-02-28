#include <accounts_merge.hpp>
#include <set>

namespace lc
{
    struct node
    {

        std::string name_;
        std::set<std::string> emails_;

        node( std::vector<std::string> records )
        {
            name_ = records[0];
            for( size_t i = 1 ; i < records.size(); ++i )
                emails_.insert( records[i] );
        }

        std::string name()
        {
            return name_;
        }
        std::set< std::string > &emails()
        {
            return emails_;
        }

        void show()
        {
            std::cout << "Name " << this->name() << " Emails ";
            for( auto e : this->emails() )
                std::cout << e << " ";
            std::cout << "\n";
        }

        bool connected( node &n )
        {
            for ( auto e : n.emails() )
            {
                if( emails().find(e) != emails().end() )
                    return true;
            }

            return false;
        }
    };

    std::vector<std::vector<std::string>> accounts_merge(
                                           std::vector<std::vector<std::string>> &accounts)
    {
        std::vector< node > nodes;
        for( auto r : accounts )
            nodes.push_back( node(r) );

        std::vector< std::vector<int> > m( nodes.size(), std::vector( nodes.size(), 0));
        for (int i = 0; i < m.size(); ++i)
        {
            for (int j = 0; j < m[i].size(); ++j )
                std::cout << m[i][j] << " ";
            std::cout << "\n";
        }


        for (int i = 0; i < m.size(); ++i)
        {
            for (int j = 0; j < m[i].size(); ++j )
            {
                if ( m[i][j] )
                {
                    continue;
                }
                else
                {
                    if( nodes[i].connected(nodes[j]) )
                    {
                        m[i][j] = 1;
                        m[j][i] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < m.size(); ++i)
        {
            for (int j = 0; j < m[i].size(); ++j )
                std::cout << m[i][j] << " ";
            std::cout << "\n";
        }


        return accounts;
    }

}

