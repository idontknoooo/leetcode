# Trie
# Knowledge Point:
#   TrieNode with addition parameter "word"
#   Trie save space on prefix
#   Trie search & add O(len(word))
#   Dictionary with enumeration can be a alternative
#   Search should stop if prefix not match (to save time)
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False
        self.word = ""

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add(self, word):
        cur_node = self.root
        for c in word:
            if c not in cur_node.children:
                cur_node.children[c] = TrieNode()
            cur_node = cur_node.children[c]
        cur_node.is_word = True
        cur_node.word = word

class Solution:
    """
    @param board: A list of lists of character
    @param words: A list of string
    @return: A list of string
    """
    def wordSearchII(self, board, words):
        # write your code here
        if not board:
            return []

        trie = Trie()
        for word in words:
            trie.add(word)

        result = set()
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.search(board, i, j, trie.root.children.get(board[i][j]), set([(i, j)]), result)
        return list(result)


    def search(self, board, i, j, node, visited, result):
        if not node: return

        if node.is_word:
            result.add(node.word)

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            _x, _y = dx + i, dy + j
            if 0 <= _x < len(board) and 0 <= _y < len(board[0]) and (_x, _y) not in visited:
                visited.add((_x, _y))
                self.search(board, _x, _y, node.children.get(board[_x][_y]), visited, result)
                visited.remove((_x, _y))
# Hash-dict + enumeration
# Space usage is greater
# time is approx same
class Solution:
    """
    @param board: A list of lists of character
    @param words: A list of string
    @return: A list of string
    """
    def wordSearchII(self, board, words):
        # write your code here

        # O(n*l), l is avg length of word
        prefix_set = set()
        for word in words:
            for i in range(1, len(word)+1):
                prefix_set.add(word[:i])

        # O(n)
        word_set = set()
        for word in words:
            word_set.add(word)

        result = set()
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.search(board, i, j, board[i][j], prefix_set, word_set, set([(i, j)]), result)

        return list(result)

    def search(self, board, i, j, word, prefix_set, word_set, visited, result):
        if word not in prefix_set:
            return

        if word in word_set:
            result.add(word)

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            _x, _y = dx + i, dy + j

            if 0 <= _x < len(board) and 0 <= _y < len(board[0]) and (_x, _y) not in visited:
                visited.add((_x, _y))
                self.search(board, _x, _y, word + board[_x][_y], prefix_set, word_set, visited, result)
                visited.remove((_x, _y))
