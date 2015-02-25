#include<iostream>
#include<cstring>
using namespace std;

bool allLeters (int containedLetters[26])
{

    for(int i = 0; i<26; ++i)
    {
        if(!containedLetters[i]) return false;
    }
    return true;
}

string smallestSubstringContainingTheAlphabet(string str){

    const char* arr = str.c_str();
    const int LETTERS = 26;
    int containedLetters[26] = {0,};

    for(int i = 0; i<26; i++){
        containedLetters[arr[i] - 'a']++;
    }

    int beginning = 0, ending = 26;

    if(allLeters(containedLetters)){
        string res;
        for(int i = beginning; i<ending; i++){
            res += arr[i];
        }
        return res;
    }

    int min = str.size();
    int begRes = beginning, endRes = ending;

    while(arr[ending-1]){
        for (ending; !allLeters(containedLetters) && ending <= str.size(); ending++){
            containedLetters[arr[ending] - 'a']++;
        }

        //cout<<"\nallLetters "<<allLeters(containedLetters)<<"\nending="<<ending;

        for(beginning; allLeters(containedLetters); beginning++){
            containedLetters[arr[beginning] - 'a']--;
        }

         //cout<<"\nallLetters "<<allLeters(containedLetters)<<"\nbeginning="<<beginning;

        if(ending - beginning + 1 < min){
            min = ending - beginning + 1;
            begRes = beginning - 1;
            endRes = ending;
        }
        //cout<<"\nbegRes="<<begRes<<"\nendRes="<<endRes;

    }

    //cout<<"\nallLetters "<<allLeters(containedLetters);
        string res;
        for(int i = begRes; i<endRes; i++){
            res += arr[i];
        }
        return res;

}

int main()
{
    cout<<endl<<smallestSubstringContainingTheAlphabet("abcdefghijklmn124345678!@#$%^&*opqrstuvwxyz!*abcdefghijklmnaaaaaaaaa");
    return 0;
}
