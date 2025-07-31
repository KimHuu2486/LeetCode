class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = 0, n2 = 0, v1ptr = 0, v2ptr = 0;
        while (v1ptr<version1.length()||v2ptr<version2.length()){
            n1 = 0;
            n2 = 0;
            while (v1ptr<version1.length()&& version1[v1ptr]!='.'){
                n1 = n1 * 10 + (version1[v1ptr] - '0');
                v1ptr++;
            }
            while (v2ptr<version2.length()&& version2[v2ptr]!='.'){
                n2 = n2 * 10 + (version2[v2ptr] - '0');
                v2ptr++;
            }
            if (n1>n2) return 1;
            if (n1<n2) return -1;
            v1ptr++; v2ptr++;
        }
        return 0;
        
    }
};