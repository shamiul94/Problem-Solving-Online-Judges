class Solution {
public:
    
    int find(vector<int> &parent, int u) {
        if(parent[u] == u) return u; 
        
        return parent[u] = find(parent, parent[u]); 
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n); 
        
        for(int i = 0; i < n; i++) {
            parent[i] = i; 
        }
        
        int components = n;
        
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0]; 
            int b = edges[i][1]; 
            
            int parentA = find(parent, a); 
            int parentB = find(parent, b); 
            
            if(parentA != parentB) {
                components--; 
                parent[parentA] = parentB;
            }
        }
        
        return components; 
    }
};