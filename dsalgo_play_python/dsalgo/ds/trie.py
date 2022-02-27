"""
Created on Jun 7, 2021

@author: kumarkud
"""


class TrieNode:
    def __init__(self):
        self.kids = [None] * 26
        self.Done = False

    def show(self):
        for k in self.kids:
            if k:
                print("Kida", k, self.Done)

    def list_kids(self):
        return self.kids


class trie:
    """
    classdocs
    """

    def __init__(self):
        """
        Constructor
        """
        self.root = self.__getNode()

    def __getNode(self):
        return TrieNode()

    def __char_to_index(self, ch):
        return ord(ch) - ord("a")

    def inseret(self, key):
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self.__char_to_index(key[level])
            if not pCrawl.kids[index]:
                pCrawl.kids[index] = self.__getNode()
            pCrawl = pCrawl.kids[index]
        pCrawl.Done = True
        pCrawl.show()

    def show(self):
        if self.root:
            for k in self.root.kids:
                if k:
                    k.show()

    def search(self, key):
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self.__char_to_index(key[level])
            if not pCrawl.kids[index]:
                return False
            pCrawl = pCrawl.kids[level]
        return pCrawl != None and pCrawl.Done


# driver function
def main():

    # Input keys (use only 'a' through 'z' and lower case)
    keys = ["the", "a", "there", "anaswe", "any", "by", "their"]
    output = ["Not present in trie", "Present in trie"]

    # Trie object
    t = trie()

    # Construct trie
    for key in keys:
        t.inseret(key)
        t.show()

    # Search for different keys
    print("{} ---- {}".format("the", output[t.search("the")]))
    print("{} ---- {}".format("these", output[t.search("these")]))
    print("{} ---- {}".format("their", output[t.search("their")]))
    print("{} ---- {}".format("thaw", output[t.search("thaw")]))


if __name__ == "__main__":
    main()
