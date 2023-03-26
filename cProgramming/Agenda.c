#include<stdio.h>

struct contact {
    int id;
    char name[50];
    char lname[50];
    char lmname[50];
    char address[250];
    char rfc[13];
    int cellphone;
    int phone;
    char email[100];
    char fb[100];
    char tw[100];
};

int menu();
int strCompare(const char *string1, const char *string2);
void printContact(struct contact contacto);

int main(){
    int option = 0, contacts = 0, id = 0;
    struct contact agenda[100];
    char search[50];
    printf("Bienvenido al sistema de agenda\n");
    do{
        option = menu();
        switch (option){
        case 1:
            printf("Ingresa los datos solicitados:\n");
            agenda[contacts].id = contacts;
            printf("Nombre: ");
            scanf("%s", agenda[contacts].name);
            printf("Apellido Paterno: ");
            scanf("%s", agenda[contacts].lname);
            printf("Apellido Materno: ");
            scanf("%s", agenda[contacts].lmname);
            printf("Direccion: ");
            scanf("%s", agenda[contacts].address);
            printf("RFC: ");
            scanf("%s", agenda[contacts].rfc);
            printf("Numero celular: ");
            scanf("%d", &agenda[contacts].cellphone);
            printf("Numero de casa: ");
            scanf("%d", &agenda[contacts].phone);
            printf("Email: ");
            scanf("%s", agenda[contacts].email);
            printf("Facebook: ");
            scanf("%s", agenda[contacts].fb);
            printf("Twitter: ");
            scanf("%s", agenda[contacts].tw);
            contacts++;
            break;
        case 2:
            printf("Ingresa el nombre a buscar: ");
            scanf("%s", search);
            for(int i = 0; i <= contacts; i++){
                if(strCompare(agenda[i].name, search)){
                    printf("El id de contacto es: %d\n", agenda[i].id);
                    i = contacts + 1;
                }
            }
            break;
        case 3:
            printf("Ingresa el ID del contacto a modificar");
            scanf("%d", &id);
            printf("Nombre: ");
            scanf("%s", agenda[id].name);
            printf("Apellido Paterno: ");
            scanf("%s", agenda[id].lname);
            printf("Apellido Materno: ");
            scanf("%s", agenda[id].lmname);
            printf("Direccion: ");
            scanf("%s", agenda[id].address);
            printf("RFC: ");
            scanf("%s", agenda[id].rfc);
            printf("Numero celular: ");
            scanf("%d", &agenda[id].cellphone);
            printf("Numero de casa: ");
            scanf("%d", &agenda[id].phone);
            printf("Email: ");
            scanf("%s", agenda[id].email);
            printf("Facebook: ");
            scanf("%s", agenda[id].fb);
            printf("Twitter: ");
            scanf("%s", agenda[id].tw);
            break;
        case 4:
            printf("Ingresa el ID del contacto a imprimir\n");
            scanf("%d", &id);
            printContact(agenda[id]);
            break;
        case 5:
            printf("Ingresa el ID del contacto a eliminar\n");
            scanf("%d", &id);
            for(int i = id; i < contacts; i++){
                agenda[i] = agenda[i + 1];
            }
            printf("Contacto eliminado\n");
            break;
        default:
            printf("BYE\n");
            break;
        }
    }while(option > 0 && option < 6);
    
}

int menu(){
    int option;
    printf("1. Nuevo contacto\n");
    printf("2. Buscar contacto por nombre\n");
    printf("3. Modificar contacto\n");
    printf("4. Imprimir contacto\n");
    printf("5. Eliminar contacto\n");
    printf("6. Salir\n");
    scanf("%d", &option);
    return option;
}

int strCompare(const char *string1, const char *string2){
    while (*string1){
        if (*string1 != *string2) {
            break;
        }
        string1++;
        string2++;
    }
    return *(const unsigned char*)string1 - *(const unsigned char*)string2;
}

void printContact(struct contact contacto){
    printf("ID: %d\n", contacto.id);
    printf("Nombre: %s\n", contacto.name);
    printf("Apellido Paterno: %s\n", contacto.lname);
    printf("Apellido Materno: %s\n", contacto.lmname);
    printf("Direccion: %s\n", contacto.address);
    printf("RFC: %s\n", contacto.rfc);
    printf("Numero celular: %d\n", contacto.cellphone);
    printf("Numero de casa: %d\n", contacto.phone);
    printf("Email: %s\n", contacto.email);
    printf("Facebook: %s\n", contacto.fb);
    printf("Twitter: %s\n", contacto.tw);
}