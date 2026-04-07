class Robot {
private:
    int w, h;
    int perimPos;
    int perimLen;
    bool hasMoved;

public:
    Robot(int width, int height) {
        w = width; h = height;
        perimLen = 2*(w + h) - 4;
        perimPos = 0;
        hasMoved = false;
    }
    
    void step(int num) {
        perimPos = (perimPos + num) % perimLen;
        hasMoved = true;
    }
    
    vector<int> getPos() {
        int pos = perimPos;
        if (pos < w)       return {pos, 0};
        pos -= w;
        if (pos < h-1)     return {w-1, pos+1};
        pos -= (h-1);
        if (pos < w-1)     return {w-2-pos, h-1};
        pos -= (w-1);
        return {0, h-2-pos};
    }
    
    string getDir() {
        // Handle wraparound: pos=0 after movement is NOT the initial East state
        if (perimPos == 0 && hasMoved)
            return h == 1 ? "West" : "South";
        if (perimPos <= w-1)      return "East";
        if (perimPos <= w+h-2)    return "North";
        if (perimPos <= 2*w+h-3)  return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
