#include <iostream>
#include <string>
#include <limits>  // Para cin.ignore()

using namespace std;

// Estruturas
typedef struct {
    string nomePaciente;
    struct Data {
        int dia;
        int mes;
        int ano;
    } dataNascimento;  
    string endereco;
    int telefone;
} Cadastro;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    string nomePaciente;
    Data dataConsulta;
} Consulta;

Cadastro *Paciente = NULL;
Consulta *Consultas = NULL;
int numeroDePacientes = 0;  
int numeroDeConsultas = 0;  

int menu() {
    int opcao;
    while (true) {
        cout << "Bem-vindo ao sistema de gerenciamento da sua clinica medica!" << endl;
        cout << endl;
        cout << "Selecione uma das opcoes: " << endl;
        cout << "1 - Mostrar todos os pacientes cadastrados:" << endl
             << "2 - Buscar Pacientes:" << endl
             << "3 - Adicionar Pacientes:" << endl
             << "4 - Agendar Consulta:" << endl
             << "5 - Mostrar Consultas Agendadas:" << endl
             << "6 - Sair:" << endl;
        cout << "Digite a sua opcao (1 a 6): ";
        
        if (cin >> opcao) {
            cin.ignore();  
            if (opcao >= 1 && opcao <= 6) {
                return opcao;
            } else {
                cout << "Opcao invalida! Por favor, digite um numero entre 1 e 5." << endl;
            }
        } else {
            cout << "Entrada invalida! Por favor, digite um numero." << endl;
            cin.clear();
        }
    }
}
void adicionar_paciente() {
    Cadastro novoPaciente;

    while (true) {
        cout << "Informe o nome do paciente: ";
        getline(cin, novoPaciente.nomePaciente);
        if (novoPaciente.nomePaciente.empty()) {
            cout << "Nome nao pode ser vazio. Tente novamente.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Informe o dia de nascimento (1-31): ";
        cin >> novoPaciente.dataNascimento.dia;
        if (novoPaciente.dataNascimento.dia < 1 || novoPaciente.dataNascimento.dia > 31) {
            cout << "Dia invalido. Tente novamente.\n";
            cin.clear();  
            continue;
        }

        cout << "Informe o mes de nascimento (1-12): ";
        cin >> novoPaciente.dataNascimento.mes;
        if (novoPaciente.dataNascimento.mes < 1 || novoPaciente.dataNascimento.mes > 12) {
            cout << "Mes invalido. Tente novamente.\n";
            cin.clear();  
            continue;
        }

        cout << "Informe o ano de nascimento: ";
        cin >> novoPaciente.dataNascimento.ano;
        if (novoPaciente.dataNascimento.ano < 1900 || novoPaciente.dataNascimento.ano > 2024) { 
            cout << "Ano invalido. Tente novamente.\n";
            cin.clear(); 
            continue;
        }
        break;
    }

    cin.ignore(); 

    while (true) {
        cout << "Informe o endereco do paciente: ";
        getline(cin, novoPaciente.endereco);
        if (novoPaciente.endereco.empty()) {
            cout << "Endereco nao pode ser vazio. Tente novamente.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Informe o telefone do paciente(sem o uso de parenteses ou traco): ";
        cin >> novoPaciente.telefone;
        if (cin.fail()) {
            cout << "Telefone invalido. Tente novamente.\n";
            cin.clear(); 
        } else {
            break;
        }
    }

   
    Cadastro *tempPaciente = new Cadastro[numeroDePacientes + 1]; 

    // Verifica se a alocação foi bem-sucedida
    if (tempPaciente == nullptr) {
        cout << "Erro de alocação de memória!" << endl;
        exit(1);  // Encerra o programa em caso de falha
    }

    // Copia os pacientes existentes para o novo vetor
    for (int i = 0; i < numeroDePacientes; i++) {
        tempPaciente[i] = Paciente[i];
    }

    // Adiciona o novo paciente
    tempPaciente[numeroDePacientes] = novoPaciente;

    // Libera a memória antiga de pacientes
    delete[] Paciente;

    // Aponta o ponteiro original para o novo vetor
    Paciente = tempPaciente;

    // Incrementa o contador de pacientes
    numeroDePacientes++;

    cout << "Paciente adicionado com sucesso!" << endl;
}
void selectionSort(Cadastro arr[], int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        aux = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].nomePaciente < arr[aux].nomePaciente) {
                aux = j;
            }
        }
        swap(arr[i], arr[aux]);
    }
}

int busca_binaria(Cadastro arr[], int low, int high, const string &nome) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // Caso base: se o nome do paciente for igual
        if (arr[mid].nomePaciente == nome) {
            return mid;
        }

        // Se o nome procurado for menor, a busca ocorre na metade esquerda
        if (arr[mid].nomePaciente > nome) {
            return busca_binaria(arr, low, mid - 1, nome);
        }

        // Se o nome procurado for maior, a busca ocorre na metade direita
        return busca_binaria(arr, mid + 1, high, nome);
    }

    // Caso não encontrado
    return -1;
}
void buscar_paciente() {
    string nome;
    cout << "Digite o nome do paciente que deseja buscar: ";
    getline(cin, nome);

    // Ordena os pacientes pelo nome usando Selection Sort
    selectionSort(Paciente, numeroDePacientes);

    int resultado = busca_binaria(Paciente, 0, numeroDePacientes - 1, nome);

    if (resultado != -1) {
        cout << "Paciente encontrado!\n";
        cout << "Nome: " << Paciente[resultado].nomePaciente << endl;
        cout << "Data de Nascimento: " << Paciente[resultado].dataNascimento.dia << "/"
             << Paciente[resultado].dataNascimento.mes << "/" << Paciente[resultado].dataNascimento.ano << endl;
        cout << "Endereço: " << Paciente[resultado].endereco << endl;
        cout << "Telefone: " << Paciente[resultado].telefone << endl;
    } else {
        cout << "Paciente nao encontrado.\n";
    }
}

void agendar_consulta() {
    string nomePaciente;
    int mesConsulta, diaConsulta, anoConsulta;
    bool pacienteEncontrado = false;

    cout << "Digite o nome do paciente cadastrado para agendar a consulta: ";
    getline(cin, nomePaciente);

    // Verifica se o paciente existe
    for (int i = 0; i < numeroDePacientes; i++) {
        if (Paciente[i].nomePaciente == nomePaciente) {
            pacienteEncontrado = true;

            cout << "Informe o mês da consulta (1-12): ";
            cin >> mesConsulta;
            cout << "Informe o dia da consulta (1-31): ";
            cin >> diaConsulta;
            cout << "Informe o ano da consulta: ";
            cin >> anoConsulta;

            // Valida a data da consulta
            if (mesConsulta < 1 || mesConsulta > 12 || diaConsulta < 1 || diaConsulta > 31 || anoConsulta < 2024) {
                cout << "Data inválida. Tente novamente.\n";
                cin.clear();
                return;
            }

            // Aloca memória para o próximo agendamento de consulta
            Consulta *tempConsulta = new Consulta[numeroDeConsultas + 1];

            // Verifica se a alocação foi bem-sucedida
            if (tempConsulta == nullptr) {
                cout << "Erro de alocação de memória!" << endl;
                exit(1);  // Encerra o programa em caso de falha
            }

            // Copia as consultas existentes para o novo vetor
            for (int i = 0; i < numeroDeConsultas; i++) {
                tempConsulta[i] = Consultas[i];
            }

            // Adiciona a nova consulta
            tempConsulta[numeroDeConsultas] = {nomePaciente, {diaConsulta, mesConsulta, anoConsulta}};

            // Libera a memória antiga de consultas
            delete[] Consultas;

            // Aponta o ponteiro original para o novo vetor
            Consultas = tempConsulta;

            // Incrementa o contador de consultas
            numeroDeConsultas++;

            cout << "Consulta agendada com sucesso para o paciente " << nomePaciente << "!" << endl;
            break;
        }
    }

    if (!pacienteEncontrado) {
        cout << "Paciente não encontrado." << endl;
    }
}

void mostrar_pacientes() {
    if (numeroDePacientes == 0) {
        cout << "Nenhum paciente cadastrado.\n";
        return;
    }

    cout << "Lista de pacientes cadastrados:\n";
    for (int i = 0; i < numeroDePacientes; i++) {
        cout << "Paciente " << (i + 1) << ":\n";
        cout << "Nome: " << Paciente[i].nomePaciente << endl;
        cout << "Data de Nascimento: " << Paciente[i].dataNascimento.dia << "/"
             << Paciente[i].dataNascimento.mes << "/" << Paciente[i].dataNascimento.ano << endl;
        cout << "Endereço: " << Paciente[i].endereco << endl;
        cout << "Telefone: " << Paciente[i].telefone << endl;
        cout << endl;
    }
}

void mostrar_consultas(Consulta *lista, int numero_de_consultas)
{
    if (numero_de_consultas == 0) {
        cout << "Nenhuma consulta agendada.\n";
        return;
    }

    cout << "Lista de consultas agendadas:\n";
    for (int i = 0; i < numero_de_consultas; i++)
    {
        cout << "Paciente: " << (lista + i)->nomePaciente << endl;
        cout << "Data da consulta: " << (lista + i)->dataConsulta.dia << "/"
             << (lista + i)->dataConsulta.mes << "/"
             << (lista + i)->dataConsulta.ano << endl;
        cout << endl;
    }
}

void pacientes_preadicionados() {
    // Aloca memória para 10 pacientes
    Paciente = new Cadastro[10];

       Paciente[0].nomePaciente = "Carlos Silva";
    Paciente[0].dataNascimento.dia = 15;
    Paciente[0].dataNascimento.mes = 6;
    Paciente[0].dataNascimento.ano = 1985;
    Paciente[0].endereco = "Rua das Flores, 123";
    Paciente[0].telefone = 998877665;

    Paciente[1].nomePaciente = "Ana Costa";
    Paciente[1].dataNascimento.dia = 2;
    Paciente[1].dataNascimento.mes = 8;
    Paciente[1].dataNascimento.ano = 1990;
    Paciente[1].endereco = "Av. Paulista, 2000";
    Paciente[1].telefone = 987654321;

    Paciente[2].nomePaciente = "José Souza";
    Paciente[2].dataNascimento.dia = 21;
    Paciente[2].dataNascimento.mes = 7;
    Paciente[2].dataNascimento.ano = 1982;
    Paciente[2].endereco = "Rua 10, nº 50";
    Paciente[2].telefone = 998211445;

    Paciente[3].nomePaciente = "Maria Oliveira";
    Paciente[3].dataNascimento.dia = 11;
    Paciente[3].dataNascimento.mes = 5;
    Paciente[3].dataNascimento.ano = 1993;
    Paciente[3].endereco = "Av. Brasil, 100";
    Paciente[3].telefone = 994355987;

    Paciente[4].nomePaciente = "Pedro Santos";
    Paciente[4].dataNascimento.dia = 8;
    Paciente[4].dataNascimento.mes = 12;
    Paciente[4].dataNascimento.ano = 1978;
    Paciente[4].endereco = "Rua Rio, 500";
    Paciente[4].telefone = 999885433;

    Paciente[5].nomePaciente = "Lucia Almeida";
    Paciente[5].dataNascimento.dia = 19;
    Paciente[5].dataNascimento.mes = 3;
    Paciente[5].dataNascimento.ano = 1995;
    Paciente[5].endereco = "Rua da Paz, 300";
    Paciente[5].telefone = 987665432;

    Paciente[6].nomePaciente = "Paulo Souza";
    Paciente[6].dataNascimento.dia = 5;
    Paciente[6].dataNascimento.mes = 9;
    Paciente[6].dataNascimento.ano = 1988;
    Paciente[6].endereco = "Av. Central, 900";
    Paciente[6].telefone = 998766544;

    Paciente[7].nomePaciente = "Carla Pereira";
    Paciente[7].dataNascimento.dia = 16;
    Paciente[7].dataNascimento.mes = 2;
    Paciente[7].dataNascimento.ano = 1992;
    Paciente[7].endereco = "Rua dos Três, 20";
    Paciente[7].telefone = 992233556;

    Paciente[8].nomePaciente = "João Costa";
    Paciente[8].dataNascimento.dia = 23;
    Paciente[8].dataNascimento.mes = 4;
    Paciente[8].dataNascimento.ano = 1980;
    Paciente[8].endereco = "Rua Sete, 40";
    Paciente[8].telefone = 981234567;

    Paciente[9].nomePaciente = "Fernanda Rocha";
    Paciente[9].dataNascimento.dia = 30;
    Paciente[9].dataNascimento.mes = 11;
    Paciente[9].dataNascimento.ano = 1994;
    Paciente[9].endereco = "Av. São João, 75";
    Paciente[9].telefone = 997988332;

    numeroDePacientes = 10;
}

int main() {
    int opcao;

    pacientes_preadicionados();

    do {
        opcao = menu();  
        switch (opcao) {
            case 1:  
                mostrar_pacientes();
                break;
            case 2: 
                buscar_paciente();
                break;
            case 3:  
                adicionar_paciente();
                break;
            case 4: 
                agendar_consulta();
                break;
            case 5:  
                mostrar_consultas(Consultas, numeroDeConsultas);
                break;
            case 6:
                cout << "Saindo... Obrigado por usar o sistema!\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 6);  
    // Para garantir que a Liberação de memória foi feita corretamente
    delete[] Paciente;
    delete[] Consultas;
    Paciente = NULL;
    Consultas = NULL;

    return 0;
}
