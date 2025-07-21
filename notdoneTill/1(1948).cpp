//not done by me 
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    // TrieNode represents a folder. The children are stored in a map
    // to keep them sorted, which is crucial for a canonical signature.
    struct TrieNode {
        std::map<std::string, TrieNode*> children;
        std::string signature; // To store the computed structural signature.
    };

    /**
     * @brief Performs a post-order DFS to compute a structural signature for
     * each folder. The signature for a folder is a string representing its
     * direct subfolders and their structures. These signatures are counted to
     * find duplicates.
     */
    std::string computeSignatures(TrieNode* node,
                                  std::map<std::string, int>& sig_counts) {
        // A leaf node (empty folder) has no sub-structure, so its signature is
        // empty.
        if (node->children.empty()) {
            return "";
        }

        std::string current_sig;
        // Iterate through children (map ensures alphabetical order for a
        // canonical signature).
        for (auto const& [name, child] : node->children) {
            std::string child_sig = computeSignatures(child, sig_counts);
            current_sig += name + "<" + child_sig + ">";
        }

        // Store the signature in the node for later lookup.
        node->signature = current_sig;

        // Count this signature if it represents a non-empty folder structure.
        if (!current_sig.empty()) {
            sig_counts[current_sig]++;
        }

        return current_sig;
    }

    /**
     * @brief Performs a pre-order DFS to collect the paths of non-deleted
     * folders. A folder is deleted if its signature count is > 1. If so, we
     * prune its entire subtree.
     */
    void buildResult(TrieNode* node, std::vector<std::string>& current_path,
                     std::vector<std::vector<std::string>>& result,
                     const std::map<std::string, int>& sig_counts) {
        // Check the children of the current node to decide which ones to keep.
        for (auto const& [name, child] : node->children) {
            // A folder is kept if it's a leaf (empty signature) or its
            // structure is unique (count == 1).
            if (child->signature.empty() ||
                sig_counts.at(child->signature) == 1) {
                current_path.push_back(name);
                result.push_back(
                    current_path); // Add the path of this non-deleted folder.
                buildResult(child, current_path, result,
                            sig_counts); // Recurse to find its valid children.
                current_path.pop_back(); // Backtrack for the next sibling.
            }
        }
    }

    // Helper to deallocate Trie memory.
    void deleteTrie(TrieNode* node) {
        if (!node)
            return;
        for (auto const& [name, child] : node->children) {
            deleteTrie(child);
        }
        delete node;
    }

    std::vector<std::vector<std::string>>
    deleteDuplicateFolder(std::vector<std::vector<std::string>>& paths) {
        TrieNode* root = new TrieNode();

        // 1. Build the Trie from the input paths.
        for (const auto& path : paths) {
            TrieNode* current = root;
            for (const std::string& folder : path) {
                if (current->children.find(folder) == current->children.end()) {
                    current->children[folder] = new TrieNode();
                }
                current = current->children[folder];
            }
        }

        // 2. Compute signatures for all subtrees using post-order DFS and count
        // them.
        std::map<std::string, int> sig_counts;
        computeSignatures(root, sig_counts);

        // 3. Build the result by traversing the trie (pre-order) and skipping
        // duplicate subtrees.
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current_path;
        buildResult(root, current_path, result, sig_counts);

        deleteTrie(root);

        return result;
    }
};