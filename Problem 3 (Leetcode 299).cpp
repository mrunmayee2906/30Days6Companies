string getHint(string secret, string guess) {
    // map
    // save the freuency of digits in map
    // there are digits only, we can use array
    int secretCount[10] = {0}, guessCount[10] = {0};
    int bulls = 0, cows = 0;

    for(int i = 0; i < secret.size(); i++) {
        // if secret[i] == guess[i] bulls++
        // and we don't count this 
        if(secret[i] == guess[i]) {
            bulls++;
        }
        // else we keep the count
        else {
            int secretDigit = secret[i] - '0';
            int guessDigit = guess[i] - '0';
            secretCount[secretDigit]++;
            guessCount[guessDigit]++;
        }
    }

    // calculating cows
    for(int i = 0; i < 10; i++) {
        // if guessCount[i] > secretCount[i], then secretCount[i] will be added to cows
        // else guessCount[i] will bew added to cows
        cows += min(secretCount[i], guessCount[i]);
    } 

    string result = to_string(bulls) + 'A' + to_string(cows) + 'B';
    return result;
}
