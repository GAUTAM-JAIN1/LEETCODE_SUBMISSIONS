class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
       int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     int a = (10 * (arriveAlice[0] - '0')) + (arriveAlice[1] - '0');
        int b = (10 * (leaveAlice[0] - '0')) + (leaveAlice[1] - '0');
        int c = (10 * (arriveAlice[3] - '0')) + (arriveAlice[4] - '0');
        int d = (10 * (leaveAlice[3] - '0')) + (leaveAlice[4] - '0');
      pair<int,int> alice = {c, d};
        for(int i = 0; i < a-1; i++) alice.first += days[i];
        for(int i = 0; i < b-1; i++) alice.second += days[i];

        

  int e = (10 * (arriveBob[0] - '0')) + (arriveBob[1] - '0');
        int f = (10 * (leaveBob[0] - '0')) + (leaveBob[1] - '0');
        int g = (10 * (arriveBob[3] - '0')) + (arriveBob[4] - '0');
        int h = (10 * (leaveBob[3] - '0')) + (leaveBob[4] - '0');
           pair<int,int> bob = {g, h};
        for(int i = 0; i < e-1; i++) bob.first += days[i];
        for(int i = 0; i < f-1; i++) bob.second += days[i];


            int x = max(alice.first,bob.first);
            int y =min(alice.second,bob.second);
         return max(0, y - x + 1);


    }
};