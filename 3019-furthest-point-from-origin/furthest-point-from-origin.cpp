class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
    int countL = 0, countR = 0, countS=0;

    for (char c : moves) {
        if (c == 'L') countL++;
        else if (c == 'R') countR++;
        else if (c == '_') countS++;
    }
    if(countL>countR){
        replace(moves.begin(),moves.end(),'_','L');
        countL=countL+countS;
    }
    else{
        replace(moves.begin(),moves.end(),'_','R');
        countR=countR+countS;
    }

    return abs(countL-countR);
    }
};