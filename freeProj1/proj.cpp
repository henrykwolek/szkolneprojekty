#include <iostream>

using namespace std;

class loginManager {
    public:
        string userNameAttempt;
        string passWordAttempt;

        loginManager() {
            accesGranted = 0;
        }

        void login() {
            cout << "Password: \nUsername:";
            cin >> userNameAttempt;

            if (userNameAttempt == userName)
            {
                cout << "Password: ";
                cin >> passWordAttempt;

                if (passWordAttempt == passWord)
                {
                    cout << "That's right";
                }        
            }   
        }
    
    private:
        string passWord = "easypassword";
        string userName = "user@email.com";
        bool accesGranted;
};

int main() {
    loginManager loginManagerObj;
    loginManagerObj.login();
}