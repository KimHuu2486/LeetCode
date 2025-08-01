class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size()<2) return chars.size();
        int index = 0;
        int count = 1;
        for (int i = 0; i<chars.size()-1; i++){
            if (chars[i]!=chars[i+1]){
                if (count == 1){
                    chars[index++] = chars[i];
                }
                else {
                    chars[index++] = chars[i];
                    string temp = to_string(count);
                    for (int i = 0; i<temp.size();i++){
                        chars[index++] = temp[i];
                    }
                    count = 1;
                }
            }
            else {
                count++;
            }
        }
        if (count == 1) {
            chars[index++] = chars[chars.size()-1];
        }
        else {
            chars[index++] = chars[chars.size()-1];
            string temp = to_string(count);
            for (int i = 0; i<temp.size();i++){
                chars[index++] = temp[i];
            }
        }
        return index;
    }
};