#include <accounts_merge.hpp>
#include <set>

namespace lc
{
struct node
{

	std::string name_;
	std::set<std::string> emails_;

	node(std::vector<std::string> records)
	{
		name_ = records[0];
		for (size_t i = 1; i < records.size(); ++i)
			emails_.insert(records[i]);
	}

	std::string name()
	{
		return name_;
	}
	std::set<std::string>& emails()
	{
		return emails_;
	}

	void show()
	{
		std::cout << "Name " << this->name() << " Emails ";
		for (auto e : this->emails())
			std::cout << e << " ";
		std::cout << "\n";
	}

	bool connected(node &n)
	{
		for (auto e : n.emails())
		{
			if (emails().find(e) != emails().end())
				return true;
		}

		return false;
	}
};

std::vector<std::set<size_t>> paths;
std::set<size_t> path;

void dfs(std::vector<std::vector<int> > &g, size_t i, size_t j, size_t row,
		size_t col)
{
	if (i < 0 or j < 0 or i >= row or j >= col)
		return;
	if (g[i][j] == 0)
		return;
	path.insert(i);
	path.insert(j);
	g[i][j] = 0;

	dfs(g, i + 1, j, row, col);
	dfs(g, i - 1, j, row, col);
	dfs(g, i, j + 1, row, col);
	dfs(g, i, j - 1, row, col);
	return;
}

std::vector<std::vector<std::string>> accounts_merge(
		std::vector<std::vector<std::string>> &accounts)
{
	std::vector<node> nodes;
	for (auto r : accounts)
		nodes.push_back(node(r));

	std::vector<std::vector<int> > m(nodes.size(),
			std::vector(nodes.size(), 0));
	for (size_t i = 0; i < m.size(); ++i)
	{
		for (size_t j = 0; j < m[i].size(); ++j)
		{
			if (m[i][j] or (not nodes[i].connected(nodes[j])))
				continue;
			m[i][j] = 1;
			m[j][i] = 1;
		}
	}

	for (size_t i = 0; i < m.size(); ++i)
	{
		for (size_t j = 0; j < m[i].size(); ++j)
		{
			dfs(m, i, j, nodes.size(), nodes.size());
			if (path.size() > 0)
			{
				if (path.size() > 1)
					paths.push_back(path);
				path.clear();
			}
		}
	}

	std::vector<std::vector<std::string>> ret;

	for (size_t i = 0; i < nodes.size(); ++i)
	{
		for (auto p : paths)
		{
			if (p.find(i) == p.end())
			{
				ret.push_back(accounts[i]);
			}
		}
	}

	for (auto p : paths)
	{
		int i = 0;
		for (auto index : p)
		{
			if (i == 0)
			{
				ret.push_back(std::vector<std::string>(
				{ nodes[index].name() }));
			}
			ret.push_back(
					std::vector<std::string>(accounts[index].begin() + 1,
							accounts[index].end()));
			i++;
		}
	}

	return ret;
}

}

