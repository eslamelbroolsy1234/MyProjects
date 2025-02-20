#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
const string FileName = "D:\\NewVS\\Bank1_Project\\Clients.txt.txt";

void ShowMainMenue();

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
    bool MarkForDelete = false;
};

enum enMainMenue
{

    Show = 1,
    Add = 2,
    Delete = 3,
    UpDate = 4,
    Find = 5,
    Exit = 6 

};

vector <string> Split(string S1, string delim)
{

    vector  <string> VEacheWorld;

    size_t pos = 0;
    string sWorld;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWorld = S1.substr(0, pos);

        if (sWorld != "")
        {
            VEacheWorld.push_back(sWorld);
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        VEacheWorld.push_back(S1);
    }

    return VEacheWorld;


}


stClient RemoveDataLineToRecord(string sLine, string delim = "#//#")
{

    vector<string> VEacheWorld = Split(sLine, delim);
    stClient Client;

    if (VEacheWorld.size() == 5) // التأكد من أن البيانات كاملة
    {
        Client.AccountNumber = VEacheWorld[0];
        Client.PinCode = VEacheWorld[1];
        Client.Name = VEacheWorld[2];
        Client.Phone = VEacheWorld[3];
        Client.AccountBalance = stod(VEacheWorld[4]);
    }

    return Client;

}

vector<stClient> LoadClientsDataFromFile(string FileName)
{

    vector<stClient> vClient;
    
    fstream MyFile(FileName, ios::in);
    
    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            stClient Client = RemoveDataLineToRecord(Line);

            if (!Client.AccountNumber.empty()) // التحقق من أن البيانات صحيحة قبل إضافتها
            {
                vClient.push_back(Client);
            }
        }

        MyFile.close();
    }

    return vClient;

}

void PrintClientRecord(stClient  Client)
{

    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(30) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;

}

void ShowClientList()
{

    vector <stClient> vClient = LoadClientsDataFromFile(FileName);

    cout << "\n\t\t\t\t\t Client List (" << vClient.size() << ") Clients\n";
    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code ";
    cout << "| " << left << setw(30) << "Client Name";
    cout << "| " << left << setw(12) << "Phone ";
    cout << "| " << left << setw(12) << "Balance \n";

    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;

    if (vClient.empty())
    {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }
    else
    {
        for (stClient & S : vClient)
        {

            PrintClientRecord(S);

            cout << endl;

        }
    }

    cout << "\n\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;


}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    vector <stClient> vClient;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        stClient Client;
        string Line;

        while (getline(MyFile, Line))
        {
            Client = RemoveDataLineToRecord(FileName);

            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }

            vClient.push_back(Client);
        }
        
        MyFile.close();

    }
        return false;
}


stClient ReadNewClient()
{

    vector <stClient> vClient = LoadClientsDataFromFile(FileName); 
    stClient ClientData;

    cout << "Enter AccountNumber? ";
    getline(cin >> ws, ClientData.AccountNumber);


    // One Method at least to used 
  /*  while (ClientExistsByAccountNumber(ClientData.AccountNumber,FileName))
    {
        cout << "\nClient with [ " << ClientData.AccountNumber << " ] already exists , Enter another Account Number? ";
        getline(cin >> ws, ClientData.AccountNumber);
    }*/

    for (stClient & Client : vClient)
    {
        while (ClientData.AccountNumber == Client.AccountNumber)
        {
            cout << "\nClient with [ " << ClientData.AccountNumber << " ] already exists , Enter another Account Number? ";
            getline(cin >> ws, ClientData.AccountNumber);
        }
    }


    cout << "Enter PinCode? ";
    getline(cin, ClientData.PinCode);

    cout << "Enter Name? ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone? ";
    getline(cin, ClientData.Phone);

    cout << "Enter AccountBalance? ";
    cin >> ClientData.AccountBalance;

    return ClientData;

}



string ConvertClientRecoredToLine(stClient ClientData, string Delim = "#//#")
{

    string RecoredName = "";

    RecoredName += ClientData.AccountNumber + Delim;
    RecoredName += ClientData.PinCode + Delim;
    RecoredName += ClientData.Name + Delim;
    RecoredName += ClientData.Phone + Delim;
    RecoredName += to_string(ClientData.AccountBalance);

    return RecoredName;

}

void AddDatalinetoFile(string FileName, string DataLine)
{

    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;

        MyFile.close();
    }

}

void AddnewClient()
{
    stClient Client;
    Client = ReadNewClient();
    AddDatalinetoFile(FileName, ConvertClientRecoredToLine(Client));
}

void AddDataClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls");
        cout << "Adding New Client: \n\n";
        AddnewClient();

        cout << "\nClient Add SuccessFully, do you want to add more Clients? ";
        cin >> AddMore;
        cin.ignore();

    } while (toupper(AddMore) == 'Y');
}

void AddNewClientsScreen()
{

    cout << "\n---------------------------------------\n" << endl;
    cout << setw(30) << right << "Add New Clients Screen";
    cout << "\n\n---------------------------------------\n" << endl;

    AddDataClients();

}

void PrintClientCard(stClient  Client)
{

    cout << "\n\nThe Following are the Client details: \n";
    cout << "- - - - - - - - - - - - - - - - - - \n";
    cout << "Account Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nClient Name   : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nBalance       : " << Client.AccountBalance;
    cout << "\n- - - - - - - - - - - - - - - - - - \n";

}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient & Client)
{

    for (stClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;

            return true;
        }
    }
    return false;

}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient> & vClients)
{

    for (stClient & C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;

            return true;
        }
    }
    return false;

}


string ReadClientAccountNumber()
{

    string AccountNumber = " "; 

    cout << "\nPleas Enter your AccountNumber ? ";
    cin >> AccountNumber;

    return AccountNumber;

}

vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient> & vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out); 

    string DataLine;
    
    if (MyFile.is_open())
    {
        for (stClient & C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                
                DataLine = ConvertClientRecoredToLine(C);

                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient> &  vClients)
{

    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete client ? n/y ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);

            SaveClientsDataToFile(FileName, vClients);

            vClients = LoadClientsDataFromFile(FileName);

            cout << "\n\nClient Deleted Successfully. \n";
            return true;
        }
    }

    else
 
    {
        cout << "\n\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n\n";
        return false;
    }

    return false;

}

void DeleteClientScreen()
{

    cout << "\n---------------------------------------\n" << endl;
    cout << setw(30) << right << "Delete Client Screen" << endl;
    cout << "\n---------------------------------------" << endl;


    vector <stClient> vClients = LoadClientsDataFromFile(FileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

}

stClient ReadToUpdateClient(string AccountNumber)
{

    stClient ClientData;

    ClientData.AccountNumber = AccountNumber;

    cout << "\nEnter PinCode? ";
    getline(cin >> ws, ClientData.PinCode);

    cout << "Enter Name? ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone? ";
    getline(cin, ClientData.Phone);

    cout << "Enter AccountBalance? ";
    cin >> ClientData.AccountBalance;

    return ClientData;

}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{

    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want updated client ? n/y ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClient & C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ReadToUpdateClient(AccountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(FileName, vClients);

            vClients = LoadClientsDataFromFile(FileName);

            cout << "\n\nClient Updated Successfully. \n";
            return true;
        }
    }

    else

    {

        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";
        return false;

    }

    return false;
}


void UpdateClientScreen()
{

    cout << "\n---------------------------------------\n" << endl;
    cout << setw(30) << right << "Update Client Screen" << endl;
    cout << "\n---------------------------------------" << endl;

    vector <stClient> vClient = LoadClientsDataFromFile(FileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClient);


}

void FindClientScreen()
{

    cout << "\n---------------------------------------\n" << endl;
    cout << setw(30) << right << "Find Client Screen" << endl;
    cout << "\n---------------------------------------" << endl;


    vector <stClient> vClient = LoadClientsDataFromFile(FileName); 
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();


    if (FindClientByAccountNumber( AccountNumber , vClient , Client))
    {

        PrintClientCard(Client);
        cout << endl;

    }
    else
    {

        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";

    }

}

void ExitProject()
{
    cout << "\n---------------------------------------\n" << endl;
    cout << setw(30) << right << "Program Ends :-) " << endl;
    cout << "\n---------------------------------------" << endl;

}

enMainMenue ChooseFromMainMenue()
{

    short Choice;

    do
    {

        cout << "Choose What do you want to do? [ 1 to 6 ] ? ";
        cin >> Choice;


    } while (Choice < 1 || Choice > 6);


    return (enMainMenue)Choice;
}


void GoBacktoMainMenue() 
{

    cout << "\nPress any kay to go back to main menue... ";
    system("pause > 0");
    ShowMainMenue();

}

void PerfromMainMenueOption(enMainMenue MainMenueOption)
{

    switch (MainMenueOption)
    {

    case Show:

        system("cls");
        ShowClientList();
        GoBacktoMainMenue();
        break;

    case Add:

        system("cls");
        AddDataClients();
        GoBacktoMainMenue();
        break;

    case Delete:

        system("cls");
        DeleteClientScreen();
        GoBacktoMainMenue();
        break;

    case UpDate:

        system("cls");
        UpdateClientScreen();
        GoBacktoMainMenue();
        break;

    case Find:

        system("cls");
        FindClientScreen();
        GoBacktoMainMenue();
        break;

    case Exit:

        system("cls");
        ExitProject();
        break;

    }
}

void ShowMainMenue()
{

    system("cls");
    cout << "============================================\n\n";
    cout << "\tMain Menue Screen\n";
    cout << "\n============================================\n";
    cout << "\t[1] " << "Show Client List.\n";
    cout << "\t[2] " << "Add New Client.\n";
    cout << "\t[3] " << "Delete Client.\n";
    cout << "\t[4] " << "Update Client Info.\n";
    cout << "\t[5] " << "Find Client.\n";
    cout << "\t[6] " << "Exist.\n";
    cout << "============================================\n";
    PerfromMainMenueOption(ChooseFromMainMenue());
}


int main()

{
   
    ShowMainMenue();

    return 0;
}

