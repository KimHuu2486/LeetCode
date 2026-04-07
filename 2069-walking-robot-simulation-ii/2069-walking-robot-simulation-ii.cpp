// East, South, West, North
const vector<string> DirStr = {"East", "North", "West", "South"};
const int dirX[4] = {1, 0, -1, 0};
const int dirY[4] = {0, 1, 0, -1};

class Robot {
private:
    int curDir;
    vector<int>pos;
    int w, h;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        curDir = 0;
        pos.push_back(0);
        pos.push_back(0);
    }
    
    void step(int num) {
        int perimeter = 2 * (w - 1) + 2 * (h - 1);
        num %= perimeter;
        
        if (num == 0) {
            if (pos[0] == 0 && pos[1] == 0) {
                curDir = 3; 
            }
            return; 
        }
        
        for (int i = 0; i < num; i++) {
            while (true) {
                int newX = pos[0] + dirX[curDir];
                int newY = pos[1] + dirY[curDir];
                if (newX >= 0 && newX < w && newY >= 0 && newY < h) {
                    pos[0] = newX;
                    pos[1] = newY;
                    break;
                }
                curDir = (curDir + 1) % 4; 
            }
        }
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        return DirStr[curDir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */