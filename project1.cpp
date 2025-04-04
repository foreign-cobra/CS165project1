#include <iostream>

using namespace std;

// Function to run OpenSSL and generate an MD5-Crypt hash

string generateMD5CryptHash(const string& password, const string& salt) {
    string command = "openssl passwd -1 -salt " + salt + " " + password;
    char buffer[128];
    string result;

    // Open a pipe to run the command
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Error running OpenSSL command!" << endl;
        return "";
    }

    // Read the output (the generated hash)
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    
    pclose(pipe);
    
    // Trim newline from result
    if (!result.empty() && result[result.length() - 1] == '\n') {
        result.pop_back();
    }

    return result;
}

// Here is our team's password hash!

//team17:$1$df2tStKi$hLdvAiOKArEPpj2sD0Czt1:16653:0:99999:7:::

int main() {

    string salt = "df2tStKi";
    string hash = "hLdvAiOKArEPpj2sD0Czt1"; 

    cout << generateMD5CryptHash("123456", salt) << endl;


    return 0;
}




